#include <gtest/gtest.h>
#include <string>
using namespace std;

#include "../include/simplesql.h"
#include "../src/_sqlexpr_eval.hpp"
#include "../src/sqlite_functions.h"

class SqlFuncTest : public ::testing::Test {
protected:
  virtual void SetUp() {  }

  DynVal eval(SPCtxNode exprTree, RuntimeState &state) {

    static std::shared_ptr<StdSqlScalarFuncs> stdFuncs = std::make_shared<StdSqlScalarFuncs>();

    if (exprTree) {
      if (state._spFunctionFactory == nullptr) {
        state._spFunctionFactory = stdFuncs;
      }
      SqlTreeExprEval evaluator(state);
      DynVal result = evaluator.visit(exprTree, 0);
      if (result.valid()) {
        return result;
      }
      // assume STDERR already has details about error
    }
    return 0;
  }

  DynVal eval_sql_expr(std::string sql_expr)
  {
    std::string err_msg;
    SqlEngineParser builder = SqlEngineParser();
    SPCtxNode expr = builder.Build(sql_expr, err_msg);

    if (0L == expr.get() || !err_msg.empty()) {
      _hasParseError = true;
      return 9999;
    }
    _hasParseError = false;

    RuntimeState state = RuntimeState(_valueStore);

    DynVal result = eval(expr, state);
    if (state.hasErrors()) {
      _hasExecError = true;
      fprintf(stderr, "Exec error:%s\n", state._errors[0].c_str());
      return 9999;
    }
    _hasExecError = false;

    return result;
  }

  bool _hasParseError, _hasExecError;
  StringMapValueStore _valueStore;
};

TEST_F(SqlFuncTest, func_max) {
  DynVal result = eval_sql_expr("max(3,-3,6666,44)");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(6666, result.as_i64());

  result = eval_sql_expr("max(-12.5, -3.25, -55)");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(-3.25, result.as_double());
}

TEST_F(SqlFuncTest, func_unknown_func) {
  /*int result =*/ eval_sql_expr("8 == unknown_func(64)");
  ASSERT_FALSE(_hasParseError);
  ASSERT_TRUE(_hasExecError);
}

/*
TEST_F(SqlFuncTest, func_sqrt) {
  int result = eval_sql_expr("8 == sqrt(64)");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(1, result);
}*/

TEST_F(SqlFuncTest, func_max_eq) {
  DynVal result = eval_sql_expr("4 == max(1,0,-5,4,3)");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(1, result.as_i32());
}
