
// Generated from ./SQLite.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SQLiteVisitor.h"


/**
 * This class provides an empty implementation of SQLiteVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SQLiteBaseVisitor : public SQLiteVisitor {
public:

  virtual antlrcpp::Any visitParse(SQLiteParser::ParseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError(SQLiteParser::ErrorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSql_stmt_or_expr(SQLiteParser::Sql_stmt_or_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSql_stmt(SQLiteParser::Sql_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_select_stmt(SQLiteParser::Simple_select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_stmt(SQLiteParser::Select_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_or_values(SQLiteParser::Select_or_valuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_name(SQLiteParser::Type_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(SQLiteParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdering_term(SQLiteParser::Ordering_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult_column(SQLiteParser::Result_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_or_subquery(SQLiteParser::Table_or_subqueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_clause(SQLiteParser::Join_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_operator(SQLiteParser::Join_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_constraint(SQLiteParser::Join_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_core(SQLiteParser::Select_coreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_operator(SQLiteParser::Compound_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSigned_number(SQLiteParser::Signed_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral_value(SQLiteParser::Literal_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(SQLiteParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_alias(SQLiteParser::Column_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyword(SQLiteParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(SQLiteParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_name(SQLiteParser::Function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDatabase_name(SQLiteParser::Database_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_name(SQLiteParser::Table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_name(SQLiteParser::Column_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_alias(SQLiteParser::Table_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAny_name(SQLiteParser::Any_nameContext *ctx) override {
    return visitChildren(ctx);
  }


};

