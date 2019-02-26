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

TEST_F(SqlParseTest, crash1) {
  std::string sql_expr = "select h.md5, h.sha1, h.sha256, s.name, s.service_type, s.display_name, s.module_path, s.user_account from services s, hash h where h.path =  s.module_path and ((s.module_path like '%GeeSetup_x86%' and h.sha256 = 'dc9b5e8aa6ec86db8af0a7aa897ca61db3e5f3d2e0942e319074db1aaccfdc83') or (s.module_pat\nh like '%EFACli64%' and h.sha256 = '128aca58be325174f0220bd7ca6030e4e206b4378796e82da460055733bb6f4f') or (s.module_path like '%TSMSISrv%' and h.sha256 = '0\n7fb252d2e853a9b1b32f30ede411f2efbb9f01e4a7782db5eacf3f55cf34902'));";
  std::string err_msg;
  SqlEngineParser builder = SqlEngineParser();
  SPCtxNode expr = builder.Build(sql_expr, err_msg);
  
  ASSERT_EQ(0L, expr.get());
  ASSERT_FALSE(err_msg.empty());
}
