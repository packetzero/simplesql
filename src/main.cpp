// Copyright packetzero / AT&T 2018-present. All Rights Reserved.

#include <antlr4-runtime.h>
#include "../gencpp/SQLiteLexer.h"
#include "../gencpp/SQLiteParser.h"
#include "../gencpp/SQLiteBaseVisitor.h"

using namespace antlr4;

#include "../include/simplesql.h"
#include "_sqlexpr_eval.hpp"
#include "sqlite_functions.h"

class SqlExprErrorListener : public antlr4::BaseErrorListener {
public:
  virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
                           const std::string &msg, std::exception_ptr e) {
    std::string str;
    str += std::to_string(line);
    str += ":";
    str += std::to_string(charPositionInLine);
    str += " ";
    str += msg;

    _syntaxErrors.push_back(str);
  }
  bool hasError() { return _syntaxErrors.size() > 0; }
  std::vector<std::string> _syntaxErrors;
};

/*
 * This returns the abstracted ANTLR vistor to parse and build our CtxNode tree.
 * TODO: rethink the active_schemas argument... purpose is for eval, not build?
 */
extern SQLiteVisitor* NewSqlExecTreeBuilder(
  SqlExprValueStore *pConstants, std::vector<std::string> &active_schemas);

/**
 * Build() is the main entrypoint for the application to parse an expression
 * and obtain an
 */
SPCtxNode SqlEngineParser::Build(std::string sql, std::string &errmsg)
{
  ANTLRInputStream input(sql);
  SQLiteLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  SQLiteParser parser(&tokens);
  parser.removeErrorListeners();
  SqlExprErrorListener errorListener;
  parser.addErrorListener(&errorListener);

  SQLiteParser::ParseContext* tree = nullptr;
  try {
     tree = parser.parse();
    if (nullptr == tree || errorListener.hasError() ) {
      errmsg = errorListener._syntaxErrors[0];
      return SPCtxNode();
    }
  } catch (const std::exception &ex) {
    fprintf(stderr, "Exception:%s\n", ex.what());
  }
  // look for parse error

  SQLiteVisitor *pVisitor = NewSqlExecTreeBuilder(_pConstants, _activeSchemas);
  auto calcTreeAny = pVisitor->visit(tree);
  delete pVisitor;

  if (!calcTreeAny.is<SPCtxNode>()) {
    errmsg = "Unknown Error building SqlExprExecTree";
    return SPCtxNode();
  }

  SPCtxNode calcTree = calcTreeAny.as<SPCtxNode>();
  return calcTree;
}

DynVal DynMapValueStore::lookupValue(std::string name, std::vector<std::string> *pActiveSchemas) {
  if (nullptr == _pObj) {
    return DynVal();
  }

  // TODO: consider schemas
  for (auto it = _pObj->begin(); it != _pObj->end(); it++) {
    if (it->first->name == name) {
      return it->second;
    }
  }
  return DynVal();
}

namespace simplesql {
  DynVal eval(SPCtxNode exprTree, RuntimeState &state) {

    if (exprTree) {
      SqlTreeExprEval evaluator(state);
      DynVal result = evaluator.visit(exprTree, 0);
      if (result.valid()) {
        return result;
      }
      // assume STDERR already has details about error
    }
    return 0;
  }  
}
