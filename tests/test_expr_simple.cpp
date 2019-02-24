#include <gtest/gtest.h>
#include <string>
using namespace std;

#include "../include/simplesql.h"

class SqlParseTest : public ::testing::Test {
protected:
  virtual void SetUp() {  }
};

TEST_F(SqlParseTest, invalid_syntax_unrecognized_char) {
  std::string err_msg;
  std::string sql_expr = "this isn't valid SQL";
  SqlEngineParser builder = SqlEngineParser();
  SPCtxNode expr = builder.Build(sql_expr, err_msg);

  ASSERT_EQ(0L, expr.get());
  ASSERT_FALSE(err_msg.empty());
}

TEST_F(SqlParseTest, missing_in_list_paren) {
  std::string err_msg;
  std::string sql_expr = "SELECT a IN 1,2";
  SqlEngineParser builder = SqlEngineParser();
  SPCtxNode expr = builder.Build(sql_expr, err_msg);

  ASSERT_EQ(0L, expr.get());
  ASSERT_FALSE(err_msg.empty());
}

TEST_F(SqlParseTest, unsupported_keywords) {
  std::string err_msg;
  std::string sql_expr = "DELETE FROM sometable WHERE port=22";
  SqlEngineParser builder = SqlEngineParser();
  SPCtxNode expr = builder.Build(sql_expr, err_msg);

  ASSERT_EQ(0L, expr.get());
  ASSERT_FALSE(err_msg.empty());
}
