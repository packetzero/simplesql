#include <gtest/gtest.h>
#include <string>
using namespace std;

#include "../include/simplesql.h"
#include "../src/_sqlexpr_eval.hpp"

/*
result_columns
  Join
    select 1
    select 2
*/

class SqlSelectTest : public ::testing::Test {
protected:
  virtual void SetUp() {  }

  static DynVal eval(SPCtxNode exprTree, RuntimeState &state) {

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

  int exec_sql(std::string sql_expr)
  {
    std::string err_msg;
    SqlEngineParser builder = SqlEngineParser();
    SPCtxNode expr = builder.Build(sql_expr, err_msg);

    if (0L == expr.get() || !err_msg.empty()) {
      _hasParseError = true;
      fprintf(stderr, "Parse Error: %s\n", err_msg.c_str());
      return 9999;
    }
    _hasParseError = false;

    RuntimeState state = RuntimeState(_valueStore);

    int result = eval(expr, state);
    if (state.hasErrors()) {
      _hasExecError = true;
      return 9999;
    }
    _hasExecError = false;

    return result;
  }

  bool _hasParseError, _hasExecError;
  StringMapValueStore _valueStore;
};

TEST_F(SqlSelectTest, join_using) {
  /*int result =*/ exec_sql("SELECT listenports.*, processes.path FROM listenports LEFT JOIN processes USING (pid)");
  ASSERT_FALSE(_hasParseError || _hasExecError);
}
