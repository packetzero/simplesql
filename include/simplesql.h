#ifndef _SIMPLESQL_H_
#define _SIMPLESQL_H_

#include <stdint.h>
#include <string>
#include <memory>
#include <vector>
#include <map>

#include <dynobj.hpp>


/*
 * The value store contains values of named constants or variables.
 */
struct SqlExprValueStore {

  /*
   * A value name may contain a schema prefix separated by a '.'.
   * If name is "address.zipcode", then the schema is 'address'.
   * If name is simply "zipcode", this function will use pActiveSchemas if
   * provided, to narrow down the possibilites.
   *
   * It's up to the application to determine convention for constant naming,
   * such as ALLCAPS.
   *
   * Consider an expression filtering on network ports by service name.
   *   "IF dstport IN (HTTP,HTTPS,8080,SSH,SFTP)"
   * The constant HTTP may be a constant relevant to several schemas.  The
   * active schemas can help narrow those constants down.  The constants
   * may actually be defined as NetworkPorts.SSH, etc.
   */
  virtual DynVal lookupValue(std::string name, std::vector<std::string> *pActiveSchemas = 0L) = 0;
};

//typedef DynVal (*func)(std::vector<DynVal> &params, std::string &errmsg) SqlScalarFunction;

struct SqlFunctionFactory {
  virtual DynVal call(std::string function_name, std::vector<DynVal> &params, std::string &errmsg) = 0;
};
typedef std::shared_ptr<SqlFunctionFactory> SPSqlFunctionFactory;

/*
 * Basic interface between SqlEngineTree and application data.
 */
struct RuntimeState {
  RuntimeState(SqlExprValueStore &valueStore) : _trace(false), _errors(), _valueStore(valueStore) {}
  ~RuntimeState() {}

  /**
   * If trace() returns true, then SqlEngineTree may log
   * details during exec().
   */
  virtual bool trace() { return _trace; }

  /*
   * The SqlEngineTree.exec() implementation will call addError()
   * to report any errors.
   */
  void addError(const std::string msg) {
    _errors.push_back(msg);
  }
  bool hasErrors() { return _errors.size() > 0; }

  virtual DynVal call(std::string function_name, std::vector<DynVal> &params) {
    if (_spFunctionFactory == nullptr) {
      return DynVal();
    }
    std::string errmsg;
    DynVal retval = _spFunctionFactory->call(function_name, params, errmsg);
    if (!errmsg.empty()) {
      _errors.push_back(errmsg);
    }
    return retval;
  }

  bool _trace;
  std::vector<std::string> _errors;
  SqlExprValueStore &_valueStore;
  SPSqlFunctionFactory _spFunctionFactory;
};

enum NodeType {
  NODE_UNKNOWN,
  NODE_OPCOMPARE,
  NODE_OPARITH,
  NODE_LITERAL,
  NODE_GETVAL,
  NODE_INLIST,
  NODE_LIKE,
  NODE_EXPR_LIST,
  NODE_FUNCTION_CALL,
  NODE_UNARY_OP,

  NODE_RESULT_COLUMN,
  NODE_SELECT_CORE,
  NODE_TABLE_OR_SUBQUERY,
  NODE_SELECT_VALUES,
  NODE_JOIN_CLAUSE,
  NODE_JOINER,
  NODE_JOIN_CONSTRAINT
};
/*
 * Base class for all nodes in the execution tree.
 */
struct CtxNode {
  virtual ~CtxNode() {}
  virtual bool isLeaf() = 0;
  virtual NodeType getType() = 0;

  void* _appdata; // can be used by apps to augment node data
};

typedef std::shared_ptr<CtxNode> SPCtxNode;

/*
 * All functionality is implemented using a SqlTreeVisitor.
 */

template <class T>
struct SqlTreeVisitor {
  virtual ~SqlTreeVisitor() {}

  virtual T visit(SPCtxNode spNode, int level) = 0;
};

class SqlEngineParser {
public:
  SqlEngineParser() : _activeSchemas(), _pConstants(0L) {}
  SqlEngineParser(std::vector<std::string> &active_schemas,
    SqlExprValueStore *pConstants) : _activeSchemas(active_schemas),
    _pConstants(pConstants) {}

  /**
   * Parse 'sql', build a SqlEngineTree.
   * If an error occurs during the parsing, nullptr will be returned and errmsg
   * will provide details.
   */
  SPCtxNode Build(std::string sql, std::string &errmsg);

private:
  std::vector<std::string> _activeSchemas;
  SqlExprValueStore *_pConstants;
};



/**
 * Simplest implementation of a value store tied to string map.
 * Does not consider schemas.
 */
struct StringMapValueStore : public SqlExprValueStore {

  StringMapValueStore() : obj() {}
  ~StringMapValueStore() {}

  virtual DynVal lookupValue(std::string name, std::vector<std::string> *pActiveSchemas) override {
    auto fit = obj.find(name);
    if (fit != obj.end()) {
      return fit->second;
    }
    return DynVal();
  }

  std::map<std::string,std::string> obj;
};

/**
 * Basic implementation of a value state that contains a single
 * DynMap for access to variable or constant values used in expressions.
 */
class DynMapValueStore : public SqlExprValueStore {
public:
  DynMapValueStore(DynMap *obj = 0L) : SqlExprValueStore(), _pObj(obj) {}
  ~DynMapValueStore() {}

  void set(DynMap *obj) { _pObj = obj; }

  virtual DynVal lookupValue(std::string name, std::vector<std::string> *pActiveSchemas) override;
private:
  DynMap *_pObj;
};

#endif // _SIMPLESQL_H_
