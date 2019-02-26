#ifndef _EXEC_TREE_HPP_
#define _EXEC_TREE_HPP_

/*
 * This file defines our own tree of CtxNode subclasses to represent SQL
 * statements or expression.  These should have no references to the
 * antlr classes, and antlr_visitor essentially translates the antlr tree
 * into our simplified CtxNode tree.
 */

#include "simplesql.h"

enum OP {
  OP_NONE,
  OP_OR,
  OP_AND,
  OP_EQ,
  OP_NEQ,
  OP_LT,
  OP_GT,
  OP_LTE,
  OP_GTE,
  OP_NOT,
  OP_ISNOT,
  OP_IS,

  OP_SUB,
  OP_ADD,
  OP_MUL,
  OP_DIV,

  OP_LIKE,
  OP_REGEX,
  OP_MATCH

};

enum UnaryOP {
  UOP_PLUS,
  UOP_MINUS,
  UOP_NOT,
  //UOP_TILDE // bitwise 2s complement
};

struct CtxUtil {

  static DynVal parseNumericLiteral(std::string str) {
    DynVal val;
    if (str.find(".") == std::string::npos) {
      val = (int64_t)atoll(str.c_str());
    } else {
      val = atof(str.c_str());
    }
    return val;
  }

  static std::string parseStringLiteral(std::string val) {
    size_t pos = val.find("'");
    if (pos != std::string::npos) {
      // strip off single quotes
      size_t rpos = val.rfind("'");
      if (rpos != pos) {
        return val.substr(pos+1,rpos-1);
      }
    }
    return val;
  }

};


/*
 * Node for any literal value (number or string)
 */
struct CtxLiteralValue : public CtxNode {
  DynVal _value;
  bool _isNull;
  CtxLiteralValue(DynVal val) : CtxNode(), _value(val), _isNull(false) {}
  virtual ~CtxLiteralValue() {}

  virtual bool isLeaf() override { return true; }
  virtual NodeType getType() override { return NODE_LITERAL; }
};

struct CtxExprList : public CtxNode {
  virtual NodeType getType() override { return NODE_EXPR_LIST; }
  std::vector<SPCtxNode> items;
  CtxExprList(): items() {}
  void add(SPCtxNode item) {
    items.push_back(item);
  }

  virtual bool isLeaf() override { return false; }
};
typedef std::shared_ptr<CtxExprList> SPCtxExprList;


/*
 * Class for 'somefield IN (a,b,c)' clause.
 */
struct CtxOpInList : public CtxNode {
  SPCtxExprList list;
  SPCtxNode value;
  bool isNot;
  std::string valueListName; // only when running makecvl on tree

  CtxOpInList(SPCtxExprList l, bool negate, SPCtxNode val) : CtxNode(), list(l), value(val), isNot(negate) {
  }
  virtual ~CtxOpInList() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_INLIST; }
};

struct CtxOpGetValue : public CtxNode {
  std::string _name;
  CtxOpGetValue(std::string name) : CtxNode(), _name(name) {}

  virtual ~CtxOpGetValue() {}

  virtual bool isLeaf() override { return true; }
  virtual NodeType getType() override { return NODE_GETVAL; }
};


/*
 * Node for comparison operations.
 */
struct CtxOpCompare : public CtxNode {
  SPCtxNode _left;
  SPCtxNode _right;
  bool _isNot;
  OP _op;

  virtual NodeType getType() override { return NODE_OPCOMPARE; }


  CtxOpCompare(SPCtxNode left, OP op, bool negate, SPCtxNode right) : CtxNode(),
    _left(left), _right(right), _isNot(negate), _op(op) {
  }

  virtual ~CtxOpCompare() {}

  virtual bool isLeaf() override { return false;}
};

#define LIKE_WILDCARD_STR "%"

/*
 * Node for LIKE comparison operator
 */
struct CtxOpLike : public CtxNode {
  SPCtxNode _left;
  SPCtxNode _right;
  bool _isNot;
  std::vector<std::string> _parts;

  virtual NodeType getType() override { return NODE_LIKE; }

  static int split_like(const std::string &str, std::vector<std::string> &dest) {
    size_t pos = 0;
    while (true) {
      size_t pos2 = str.find('%',pos); //LIKE_WILDCARD_STR);
      if (pos2 == std::string::npos) {
        dest.push_back(str.substr(pos));
        break;
      }
      dest.push_back(str.substr(pos, (pos2-pos)));
      pos = pos2 + 1;
    }
    return dest.size();
  }

  CtxOpLike(SPCtxNode left, bool negate, SPCtxNode right) : CtxNode(),
    _left(left), _right(right), _isNot(negate) {
      if (right->getType() == NODE_LITERAL) {
        CtxLiteralValue *pr = static_cast<CtxLiteralValue*>(right.get());
        std::string str = CtxUtil::parseStringLiteral(pr->_value );
        split_like(str, _parts);
      } else if (left->getType() == NODE_LITERAL) {
        CtxLiteralValue *pr = static_cast<CtxLiteralValue*>(left.get());
        std::string str = CtxUtil::parseStringLiteral(pr->_value );
        split_like(str, _parts);
      } else {
        ASSERT(false);
      }
  }

  virtual ~CtxOpLike() {}

  virtual bool isLeaf() override { return false;}

};

/*
 * Node for comparison operations.
 */
struct CtxOpArith : public CtxNode {
  SPCtxNode _left;
  SPCtxNode _right;
  OP _op;
  CtxOpArith(SPCtxNode left, OP op, SPCtxNode right) : CtxNode(), _left(left), _right(right), _op(op) {
  }

  virtual ~CtxOpArith() {}

  virtual NodeType getType() override { return NODE_OPARITH; }

  virtual bool isLeaf() override { return false; }
};

struct CtxUnaryOp : public CtxNode {
  UnaryOP _op;
  SPCtxNode _expr;
  CtxUnaryOp(UnaryOP op, SPCtxNode expr) : CtxNode(), _op(op), _expr(expr) {
  }

  virtual ~CtxUnaryOp() {}

  virtual NodeType getType() override { return NODE_UNARY_OP; }

  virtual bool isLeaf() override { return false; }
};

/*
 * function_name ( expr (, expr)* )
 */
struct CtxFunctionCall : public CtxNode {
  std::string _function_name;
  std::vector<SPCtxNode> _params;

  CtxFunctionCall(std::string function_name="") :
    _function_name(function_name), _params() {}

  virtual ~CtxFunctionCall() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_FUNCTION_CALL; }
};

struct CtxResultColumn : public CtxNode {
  std::string _table_name;
  bool _isStar;
  SPCtxNode _expr;
  std::string _alias;
  std::string _column_name;

  CtxResultColumn(SPCtxNode expr, std::string table_name="", std::string alias="") : CtxNode(),
    _table_name(table_name), _isStar(false), _expr(expr), _alias(alias), _column_name() {}

  virtual ~CtxResultColumn() {}

  virtual bool isLeaf() override { return (_expr == nullptr); }
  virtual NodeType getType() override { return NODE_RESULT_COLUMN; }
};

/*
K_SELECT ( K_DISTINCT | K_ALL )? result_column ( ',' result_column )*
   ( K_FROM ( table_or_subquery ( ',' table_or_subquery )* | join_clause ) )?
   ( K_WHERE expr )?
   ( K_GROUP K_BY expr ( ',' expr )* ( K_HAVING expr )? )?
*/

struct CtxSelectCore : public CtxNode {
  bool _isDistinct;
  std::vector<SPCtxNode> _columns;
  std::vector<SPCtxNode> _table_or_subqueries;
  SPCtxNode _joinClause;
  SPCtxNode _whereExpr;
  std::vector<SPCtxNode> _groupExprs;
  SPCtxNode _havingExpr;

  virtual ~CtxSelectCore() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_SELECT_CORE; }

};

/*
table_or_subquery
 : ( database_name '.' )? table_name ( K_AS? table_alias )?
 | '(' ( table_or_subquery ( ',' table_or_subquery )*
       | join_clause )
   ')' ( K_AS? table_alias )?
 | '(' select_stmt ')' ( K_AS? table_alias )?
 */
struct CtxTableOrSubquery : public CtxNode {
  std::string _database_name;
  std::string _table_name;
  std::string _alias;
  SPCtxNode _selectStmt;
  std::vector<SPCtxNode> _table_or_subqueries;
  SPCtxNode _joinClause;

  virtual ~CtxTableOrSubquery() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_TABLE_OR_SUBQUERY; }
};

/*
 K_VALUES '(' expr ( ',' expr )* ')' ( ',' '(' expr ( ',' expr )* ')' )*
*/
struct CtxSelectValues : public CtxNode {
  std::vector<std::vector<SPCtxNode> > _rows;

  virtual ~CtxSelectValues() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_SELECT_VALUES; }
};

// : ( K_ON expr
//   | K_USING '(' column_name ( ',' column_name )* ')' )?
struct CtxJoinConstraint : public CtxNode {
  SPCtxNode _on_expr;
  std::vector<std::string> _using_columns;

  virtual ~CtxJoinConstraint() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_JOIN_CONSTRAINT; }
};

enum JoinOp {
  JOP_NONE,
  JOP_COMMA,
  JOP_LEFT,
  JOP_OUTER,
  JOP_INNER,
  JOP_CROSS
};

typedef std::shared_ptr<CtxJoinConstraint> SPCtxJoinConstraint;

/*
join_operator table_or_subquery join_constraint
*/
struct CtxJoiner : public CtxNode {
  JoinOp _op;
  SPCtxNode _table_or_subquery;
  SPCtxNode _constraint;

  virtual ~CtxJoiner() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_JOINER; }
};
typedef std::shared_ptr<CtxJoiner> SPCtxJoiner;

/*
: table_or_subquery ( join_operator table_or_subquery join_constraint )*
*/
struct CtxJoinClause : public CtxNode {
  SPCtxNode _table_or_subquery;
  std::vector<SPCtxNode> _joins;

  virtual ~CtxJoinClause() {}

  virtual bool isLeaf() override { return false; }
  virtual NodeType getType() override { return NODE_JOIN_CLAUSE; }
};


template <class T>
struct SqlTreeExprVisitor {
  virtual ~SqlTreeExprVisitor() {}

  virtual T visit(CtxOpCompare &node, int level) = 0;
  virtual T visit(CtxOpArith &node, int level) = 0;
  virtual T visit(CtxOpGetValue &node, int level) = 0;
  virtual T visit(CtxLiteralValue &node, int level) = 0;
  virtual T visit(CtxOpInList &node, int level) = 0;
  virtual T visit(CtxOpLike &node, int level) = 0;
  virtual T visit(CtxExprList &node, int level) = 0;
  virtual T visit(CtxFunctionCall &node, int level) = 0;
  virtual T visit(CtxUnaryOp &node, int level) = 0;
};

template <class T>
struct SqlTreeStmtVisitor {
  virtual ~SqlTreeStmtVisitor() {}
  virtual T visit(CtxResultColumn &node, int level) = 0;
  virtual T visit(CtxSelectCore &node, int level) = 0;
  virtual T visit(CtxTableOrSubquery &node, int level) = 0;
  virtual T visit(CtxSelectValues &node, int level) = 0;
  virtual T visit(CtxJoinClause &node, int level) = 0;
  virtual T visit(CtxJoiner &node, int level) = 0;
  virtual T visit(CtxJoinConstraint &node, int level) = 0;
};


#endif // _EXEC_TREE_HPP_
