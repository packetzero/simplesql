
// Generated from ./SQLite.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SQLiteParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SQLiteParser.
 */
class  SQLiteVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SQLiteParser.
   */
    virtual antlrcpp::Any visitParse(SQLiteParser::ParseContext *context) = 0;

    virtual antlrcpp::Any visitError(SQLiteParser::ErrorContext *context) = 0;

    virtual antlrcpp::Any visitSql_stmt_or_expr(SQLiteParser::Sql_stmt_or_exprContext *context) = 0;

    virtual antlrcpp::Any visitSql_stmt(SQLiteParser::Sql_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSimple_select_stmt(SQLiteParser::Simple_select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSelect_stmt(SQLiteParser::Select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitSelect_or_values(SQLiteParser::Select_or_valuesContext *context) = 0;

    virtual antlrcpp::Any visitType_name(SQLiteParser::Type_nameContext *context) = 0;

    virtual antlrcpp::Any visitExpr(SQLiteParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitOrdering_term(SQLiteParser::Ordering_termContext *context) = 0;

    virtual antlrcpp::Any visitResult_column(SQLiteParser::Result_columnContext *context) = 0;

    virtual antlrcpp::Any visitTable_or_subquery(SQLiteParser::Table_or_subqueryContext *context) = 0;

    virtual antlrcpp::Any visitJoin_clause(SQLiteParser::Join_clauseContext *context) = 0;

    virtual antlrcpp::Any visitJoin_operator(SQLiteParser::Join_operatorContext *context) = 0;

    virtual antlrcpp::Any visitJoin_constraint(SQLiteParser::Join_constraintContext *context) = 0;

    virtual antlrcpp::Any visitSelect_core(SQLiteParser::Select_coreContext *context) = 0;

    virtual antlrcpp::Any visitCompound_operator(SQLiteParser::Compound_operatorContext *context) = 0;

    virtual antlrcpp::Any visitSigned_number(SQLiteParser::Signed_numberContext *context) = 0;

    virtual antlrcpp::Any visitLiteral_value(SQLiteParser::Literal_valueContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(SQLiteParser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitColumn_alias(SQLiteParser::Column_aliasContext *context) = 0;

    virtual antlrcpp::Any visitKeyword(SQLiteParser::KeywordContext *context) = 0;

    virtual antlrcpp::Any visitName(SQLiteParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitFunction_name(SQLiteParser::Function_nameContext *context) = 0;

    virtual antlrcpp::Any visitDatabase_name(SQLiteParser::Database_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_name(SQLiteParser::Table_nameContext *context) = 0;

    virtual antlrcpp::Any visitColumn_name(SQLiteParser::Column_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_alias(SQLiteParser::Table_aliasContext *context) = 0;

    virtual antlrcpp::Any visitAny_name(SQLiteParser::Any_nameContext *context) = 0;


};

