#include <antlr4-runtime.h>
#include "../gencpp/SQLiteLexer.h"
#include "../gencpp/SQLiteParser.h"
#include "../gencpp/SQLiteBaseVisitor.h"

using namespace antlr4;

// uncomment this to enable asserts in Debug build
//#define WITH_ASSERTS

#include "../include/simplesql_tree.h"

/*
 * Implementation of the ANTLR4 Visitor.
 * In SqlExpr::Build(), it will first run an antlr parse,
 * and if successful, will invoke a visit() where SqlExecTreeBuilder will
 * get callbacks for every node in the parse tree.  The job here is to
 * build a corresponding tree of CtxNode objects, leaving no references to the
 * antlr tree.  The CtxNode tree can be thought of as a compiled program,
 * which can be executed by the application to evaluate expressions on demand.
 *
 * in -> parse -> antlr4::parseTree -> visit -> CtxNode tree -> exec -> result
 */


#if NDEBUG
#define DBG_CHILD_STR(CTX)
#else
/* In a debugger, can view text values of all antlr context children */
#define DBG_CHILD_STR(CTX)            \
  std::vector<std::string> childs;    \
  for (auto c : (CTX)->children) {    \
    childs.push_back(c->getText());   \
  }

#endif // NDEBUG

class  SqlExecTreeBuilder : public SQLiteBaseVisitor {
public:
  SqlExecTreeBuilder(std::vector<std::string> &active_schemas,
    SqlExprValueStore *pConstants) : SQLiteBaseVisitor(), _activeSchemas(active_schemas), _pConstants(pConstants) {
  }

  virtual antlrcpp::Any visitLiteral_value(SQLiteParser::Literal_valueContext *ctx) override {
    DynVal dynval;
    if (ctx->K_NULL()) {
      // nothing
    } else if (ctx->NUMERIC_LITERAL()) {
      dynval = CtxUtil::parseNumericLiteral(ctx->getText());
    } else {
      dynval = CtxUtil::parseStringLiteral(ctx->getText());
    }
    auto p = new CtxLiteralValue(dynval);
    if (ctx->K_NULL()) {
      p->_isNull = true;
    }
    return std::shared_ptr<CtxNode>(p);
  }

  virtual antlrcpp::Any visitSigned_number(SQLiteParser::Signed_numberContext *ctx) override {
    DynVal dynval = CtxUtil::parseNumericLiteral(ctx->getText());
    auto p = new CtxLiteralValue(dynval);
    return std::shared_ptr<CtxNode>(p);
  }

  virtual antlrcpp::Any visitParse(SQLiteParser::ParseContext *ctx) override {
    DBG_CHILD_STR(ctx);
    ASSERT(ctx->EOF());
 //   ASSERT(ctx->children.size() == 2);

    if (ctx->children.size() != 2) {
      return SPCtxNode();
    }

    auto x = visit(ctx->children[0]);
    ASSERT(x.isNotNull());
    return x;
  }

  //virtual antlrcpp::Any visitError(SQLiteParser::ErrorContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitSql_stmt_or_expr(SQLiteParser::Sql_stmt_or_exprContext *ctx) override {
    //DBG_CHILD_STR(ctx);
    //ASSERT(false);
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSql_stmt(SQLiteParser::Sql_stmtContext *ctx) override {
    //DBG_CHILD_STR(ctx);
    // second, third, etc child will be semi-colon ';'
    return visit(ctx->children[0]);
  }

  virtual antlrcpp::Any visitSimple_select_stmt(SQLiteParser::Simple_select_stmtContext *ctx) override {
    //DBG_CHILD_STR(ctx);
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_stmt(SQLiteParser::Select_stmtContext *ctx) override {
    //DBG_CHILD_STR(ctx);
    return visitChildren(ctx);
  }

  SPCtxNode _visitSelectValues(SQLiteParser::Select_or_valuesContext *ctx) {
    CtxSelectValues* pValues = new CtxSelectValues();
    int num_rows = ctx->OPEN_PAR().size();
    // results are undetermined if each value row is not same size
    int row_size = ctx->expr().size() / num_rows;
    int r = -1;
    for (int i=0; i < ctx->expr().size(); i++) {
      auto pExpr = ctx->expr()[i];
      if (i % row_size == 0) {
        // add new row
        r++;
        pValues->_rows.push_back(std::vector<SPCtxNode>());
      }
      pValues->_rows[r].push_back(visit(pExpr));
    }
    return std::shared_ptr<CtxNode>(pValues);
  }
/*
: K_SELECT ( K_DISTINCT | K_ALL )? result_column ( ',' result_column )*
  ( K_FROM ( table_or_subquery ( ',' table_or_subquery )* | join_clause ) )?
  ( K_WHERE expr )?
  ( K_GROUP K_BY expr ( ',' expr )* ( K_HAVING expr )? )?
| K_VALUES '(' expr ( ',' expr )* ')' ( ',' '(' expr ( ',' expr )* ')' )*
*/
  virtual antlrcpp::Any visitSelect_or_values(SQLiteParser::Select_or_valuesContext *ctx) override {
    if (ctx->K_VALUES()) {
      return _visitSelectValues(ctx);
    }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_name(SQLiteParser::Type_nameContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitOrdering_term(SQLiteParser::Ordering_termContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  /*
   : '*'
   | table_name '.' '*'
   | expr ( K_AS? column_alias )?
   */
  virtual antlrcpp::Any visitResult_column(SQLiteParser::Result_columnContext *ctx) override {
    std::string table_name = "";
    std::string alias = "";
    if (ctx->table_name()) {
      table_name = ctx->table_name()->getText();
    }
    if (ctx->column_alias()) {
      alias = ctx->column_alias()->getText();
    }
    SPCtxNode expr;
    if (ctx->expr()) {
      expr = visit(ctx->expr());
      if (expr->getType() == NODE_RESULT_COLUMN) {
        CtxResultColumn *pChild = static_cast<CtxResultColumn*>(expr.get());
        if (pChild->_expr == nullptr) {
          // we can collapse this into one
          pChild->_alias = alias;
          pChild->_isStar = ctx->STAR() != nullptr;
          return expr;
        }
      }
    }

    CtxResultColumn* pColumn = new CtxResultColumn(expr, table_name,alias);
    pColumn->_isStar = (nullptr != ctx->STAR());
    return std::shared_ptr<CtxNode>(pColumn);
  }

  /*
   table_or_subquery
   : ( database_name '.' )? table_name ( K_AS? table_alias )?
   | '(' ( table_or_subquery ( ',' table_or_subquery )*
        | join_clause )
     ')' ( K_AS? table_alias )?
   | '(' select_stmt ')' ( K_AS? table_alias )?
   */
  virtual antlrcpp::Any visitTable_or_subquery(SQLiteParser::Table_or_subqueryContext *ctx) override {
    CtxTableOrSubquery *pNode = new CtxTableOrSubquery();
    if (ctx->table_alias()) {
      pNode->_alias = ctx->table_alias()->getText();
    }
    if (ctx->table_name()) {
      pNode->_table_name = ctx->table_name()->getText();
      if (ctx->database_name()) {
        pNode->_database_name = ctx->database_name()->getText();
      }
    } else if (ctx->select_stmt()) {
      pNode->_selectStmt = visit(ctx->select_stmt());
    } else {
      for (auto node : ctx->table_or_subquery()) {
        pNode->_table_or_subqueries.push_back(visit(node));
      }
      if (ctx->join_clause()) {
        pNode->_joinClause = visit(ctx->join_clause());
      }
    }
    return std::shared_ptr<CtxNode>(pNode);
  }

  JoinOp _get_join_op(SQLiteParser::Join_operatorContext* ctx) {
    if (ctx->K_OUTER()) {
      return JOP_OUTER;
    }
    if (ctx->K_LEFT()) {
      return JOP_LEFT;
    }
    if (ctx->COMMA()) {
      return JOP_COMMA;
    }
    if (ctx->K_INNER()) {
      return JOP_INNER;
    }
    return JOP_NONE;
  }
  //virtual antlrcpp::Any visitJoin_operator(SQLiteParser::Join_operatorContext *ctx) override {
  //  ASSERT(false); return visitChildren(ctx);
  //}


  // table_or_subquery ( join_operator table_or_subquery join_constraint )*
  virtual antlrcpp::Any visitJoin_clause(SQLiteParser::Join_clauseContext *ctx) override {
    CtxJoinClause* pJoinClause = new CtxJoinClause();
    pJoinClause->_table_or_subquery = visit(ctx->table_or_subquery()[0]);
    for (int i=0; i < ctx->join_operator().size(); i++) {
      CtxJoiner* pj = new CtxJoiner();

      pj->_op = _get_join_op(ctx->join_operator(i));
      pj->_table_or_subquery = visit(ctx->table_or_subquery(i + 1));
      pj->_constraint = visit(ctx->join_constraint(i));
      pJoinClause->_joins.push_back(std::shared_ptr<CtxNode>(pj));
    }
    return std::shared_ptr<CtxNode>(pJoinClause);
  }


  //  : ( K_ON expr
  //  | K_USING '(' column_name ( ',' column_name )* ')' )?
  virtual antlrcpp::Any visitJoin_constraint(SQLiteParser::Join_constraintContext *ctx) override {
    CtxJoinConstraint* p = new CtxJoinConstraint();
    if (ctx->K_ON()) {
      p->_on_expr = visit(ctx->expr());
    } else {
      if (ctx->column_name().empty()) {
        // hmm.. no join constraint
      } else {
        for (auto pColName : ctx->column_name()) {
          p->_using_columns.push_back(pColName->getText());
        }
      }
    }
    return std::shared_ptr<CtxNode>(p);
  }

/*
select_core
 : K_SELECT ( K_DISTINCT | K_ALL )? result_column ( ',' result_column )*
   ( K_FROM ( table_or_subquery ( ',' table_or_subquery )* | join_clause ) )?
   ( K_WHERE expr )?
   ( K_GROUP K_BY expr ( ',' expr )* ( K_HAVING expr )? )?
*/
  virtual antlrcpp::Any visitSelect_core(SQLiteParser::Select_coreContext *ctx) override {
    DBG_CHILD_STR(ctx);
    CtxSelectCore* pSelectCore = new CtxSelectCore();
    if (ctx->K_DISTINCT()) {
      pSelectCore->_isDistinct = true;
    }

    for (auto child : ctx->result_column()) {
      // add rc to select
      pSelectCore->_columns.push_back(visit(child));
    }
    if (ctx->K_FROM()) {
      // add table_or_subqueries
      for (auto child : ctx->table_or_subquery()) {
        pSelectCore->_table_or_subqueries.push_back(visit(child));
      }
      // add join
      if (ctx->join_clause()) {
        pSelectCore->_joinClause = visit(ctx->join_clause());
      }
    }
    if (ctx->K_WHERE()) {
      // add expr
      pSelectCore->_whereExpr = visit(ctx->expr()[0]);
    }
    int group_expr_size = ctx->expr().size();
    if (ctx->K_HAVING()) {
      pSelectCore->_havingExpr = visit(ctx->expr()[group_expr_size-1]);
      group_expr_size--;
    }
    if (ctx->K_GROUP()) {
      // add exprs
      for (int i=1; i < group_expr_size; i++) {
        pSelectCore->_groupExprs.push_back(visit(ctx->expr()[i]));
      }
    }
    return std::shared_ptr<CtxNode>(pSelectCore);
  }

  virtual antlrcpp::Any visitCompound_operator(SQLiteParser::Compound_operatorContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitUnary_operator(SQLiteParser::Unary_operatorContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitColumn_alias(SQLiteParser::Column_aliasContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitKeyword(SQLiteParser::KeywordContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitName(SQLiteParser::NameContext *ctx) override {
    auto p = new CtxOpGetValue(ctx->getText());
    return std::shared_ptr<CtxNode>(p);
  }
  virtual antlrcpp::Any visitColumn_name(SQLiteParser::Column_nameContext *ctx) override {
    auto p = new CtxOpGetValue(ctx->getText());
    return std::shared_ptr<CtxNode>(p);
  }
  virtual antlrcpp::Any visitAny_name(SQLiteParser::Any_nameContext *ctx) override {
    ASSERT(false);
    auto p = new CtxOpGetValue(ctx->getText());
    return std::shared_ptr<CtxNode>(p);
  }

  virtual antlrcpp::Any visitFunction_name(SQLiteParser::Function_nameContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitDatabase_name(SQLiteParser::Database_nameContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitTable_name(SQLiteParser::Table_nameContext *ctx) override { ASSERT(false); return visitChildren(ctx); }

  virtual antlrcpp::Any visitTable_alias(SQLiteParser::Table_aliasContext *ctx) override { ASSERT(false); return visitChildren(ctx); }


  OP to_op(SQLiteParser::ExprContext *ctx) {
    DBG_CHILD_STR(ctx);

    if (ctx->STAR()) { return OP_MUL; }
    if (ctx->DIV()) { return OP_DIV; }
    if (ctx->MINUS()) { return OP_SUB; }
    if (ctx->PLUS()) { return OP_ADD; }

    if (ctx->K_LIKE()) { return OP_LIKE; }
    if (ctx->K_MATCH()) { return OP_MATCH; }
    if (ctx->K_REGEXP()) { return OP_REGEX; }

    if (ctx->EQ() || ctx->ASSIGN()) { return OP_EQ; }
    if (ctx->NOT_EQ1() || ctx->NOT_EQ2()) { return OP_NEQ; }
    if (ctx->K_IS()) { return OP_IS; }
    if (ctx->LT()) { return OP_LT; }
    if (ctx->LT_EQ()) { return OP_LTE; }
    if (ctx->GT()) { return OP_GT; }
    if (ctx->GT_EQ()) { return OP_GTE; }

    if (ctx->K_NOT()) { return OP_NOT; }

    ASSERT(false);
    return OP_NONE;
  }

  virtual antlrcpp::Any visitExpr(SQLiteParser::ExprContext *ctx) override {
    DBG_CHILD_STR(ctx);

    if (ctx->K_IN()) {
      if (ctx->OPEN_PAR()) {
        auto _left_ = visit(ctx->children[0]);
        SPCtxNode left = _left_.as<SPCtxNode>();
        int i = (ctx->K_NOT() ? 4 : 3); // blah NOT IN ( xxx )

        auto list = new CtxExprList();
        SPCtxExprList spCtxList = std::shared_ptr<CtxExprList>(list);

        for (; i < ctx->children.size()-1; i+=2) {
          list->add(visit(ctx->children[i]));
        }

        auto p = new CtxOpInList(spCtxList, ctx->K_NOT() != nullptr, visit(ctx->children[0]).as<SPCtxNode>());
        return std::shared_ptr<CtxNode>(p);

      } else {
        ASSERT(false);
        return visitChildren(ctx);
      }
    } else if (ctx->K_IS() || ctx->ASSIGN() || ctx->EQ() || ctx->LT_EQ() || ctx->LT() || ctx->GT()
               || ctx->LT2() || ctx->GT2() || ctx->GT_EQ() || ctx->NOT_EQ1() || ctx->NOT_EQ2()) {

//      auto p = new CtxOpCompare(left, to_op(ctx->compareop()), ctx->K_NOT() != nullptr, right);
      auto _left_ = visit(ctx->children[0]);
      SPCtxNode left = _left_.as<SPCtxNode>();
      SPCtxNode right = visit(ctx->children[ctx->children.size()-1]).as<SPCtxNode>();

      ASSERT(ctx->children.size() == 3 || ctx->children.size() == 4);
      auto p = new CtxOpCompare(left, to_op(ctx), ctx->K_NOT() != nullptr, right);
      return std::shared_ptr<CtxNode>(p);

    } else if (ctx->K_LIKE()) {

      auto _left_ = visit(ctx->children[0]);
      SPCtxNode left = _left_.as<SPCtxNode>();
      SPCtxNode right = visit(ctx->children[ctx->children.size()-1]).as<SPCtxNode>();

      ASSERT(ctx->children.size() == 3 || ctx->children.size() == 4);
      auto p = new CtxOpLike(left, ctx->K_NOT() != nullptr, right);
      return std::shared_ptr<CtxNode>(p);

    } else if (ctx->function_name()) {

      auto p = new CtxFunctionCall(ctx->function_name()->getText());
      for (auto pExpr : ctx->expr()) {
        p->_params.push_back(visit(pExpr));
      }
      return std::shared_ptr<CtxNode>(p);

    } else if (ctx->STAR() || ctx->DIV() || ctx->PLUS() || ctx->MINUS()) {

      auto _left_ = visit(ctx->children[0]);
      SPCtxNode left = _left_.as<SPCtxNode>();
      SPCtxNode right = visit(ctx->children[ctx->children.size()-1]).as<SPCtxNode>();

      ASSERT(ctx->children.size() == 3);

      auto p = new CtxOpArith(left, to_op(ctx), right);
      return std::shared_ptr<CtxNode>(p);

    } else if (ctx->K_OR() || ctx->K_AND()) {

      ASSERT(ctx->children.size() == 3);

      auto _left_ = visit(ctx->children[0]);
      SPCtxNode left = _left_.as<SPCtxNode>();
      auto _right_ = visit(ctx->children[ctx->children.size()-1]);
      SPCtxNode right = _right_.as<SPCtxNode>();

      auto p = new CtxOpCompare(left, (ctx->K_OR() ? OP_OR : OP_AND), false, right);
      return std::shared_ptr<CtxNode>(p);

    } else if (ctx->OPEN_PAR()) {

      if (ctx->children.size() == 3) {
        auto retval = visit(ctx->children[1]);
        auto x = retval.as<SPCtxNode>();
        return retval;
      }
      ASSERT(false);
    } else if (ctx->children.size() == 3 && !ctx->DOT().empty() && ctx->column_name()) {
      auto p = new CtxResultColumn(nullptr);
      if (ctx->table_name()) p->_table_name = ctx->table_name()->getText();
      if (ctx->column_name()) p->_column_name = ctx->column_name()->getText();
      return std::shared_ptr<CtxNode>(p);

    } else if (ctx->unary_operator()) {
      UnaryOP op = UOP_PLUS;

      if (ctx->K_NOTNULL() || (ctx->K_NOT() && ctx->K_NULL())) {
        op = UOP_NOT;

        CtxLiteralValue *n = new CtxLiteralValue(DynVal());
        n->_isNull = true;
        CtxUnaryOp* p = new CtxUnaryOp(op, std::shared_ptr<CtxNode>(n));
        return std::shared_ptr<CtxNode>(p);
      }

      std::string opstr = ctx->children[0]->getText();
      if (opstr == "-") {
        op = UOP_MINUS;
      } else if (ctx->K_NOT()) {
        op = UOP_NOT;
      }
      SPCtxNode expr = visit(ctx->expr()[0]);

      // optimization : turn unaryop(-,555) into literal(-555)

      if (expr->getType() == NODE_LITERAL && op == UOP_MINUS) {
        CtxLiteralValue* p = static_cast<CtxLiteralValue*>(expr.get());
        if (p->_value.type() != TSTRING) {
          if (p->_value.type() == TFLOAT64 || p->_value.type() == TFLOAT32) {
            p->_value = -1 * p->_value.as_double();
          } else {
            p->_value = -1 * p->_value.as_i64();
          }
          return expr;
        }
      }

      CtxUnaryOp* p = new CtxUnaryOp(op, expr);
      return std::shared_ptr<CtxNode>(p);

    } else if (ctx->children.size() == 1) {

      return visit(ctx->children[0]);

    } else {
      _errmsg = "Unexpected expression scenario. children:" + std::to_string(ctx->children.size());
      ASSERT(false);

    }

    ASSERT(false);
    return NULL;
  }

protected:
  std::vector<std::string> _activeSchemas;
  SqlExprValueStore *_pConstants;
  std::string _errmsg;
};

SQLiteVisitor* NewSqlExecTreeBuilder(SqlExprValueStore *pConstants,
    std::vector<std::string> &active_schemas ) {
  return new SqlExecTreeBuilder(active_schemas, pConstants);
}
