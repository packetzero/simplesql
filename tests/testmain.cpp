#include <gtest/gtest.h>
#include <string>
using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int status= RUN_ALL_TESTS();
  return status;
}

class MiscExprTest : public ::testing::Test {
protected:
  virtual void SetUp() {  }
};

#include "../src/exec_tree.hpp"
#include "../src/_sqlexpr_eval.hpp"

TEST_F(MiscExprTest, like_split) {
  
  std::vector<std::string> parts;
  int num = CtxOpLike::split_like("prefix%", parts);
  ASSERT_EQ(2, num);
  ASSERT_EQ("prefix", parts[0]);
  ASSERT_TRUE(parts[1].empty());
  
  bool result;
  result = SqlTreeExprEval::is_like("prefix suffix", parts);
  ASSERT_TRUE(result);
  result = SqlTreeExprEval::is_like("xxprefix suffix", parts);
  ASSERT_FALSE(result);
  result = SqlTreeExprEval::is_like("prefiXX", parts);
  ASSERT_FALSE(result);

  parts.clear();

  num = CtxOpLike::split_like("%/bin/%", parts);
  ASSERT_EQ(3, num);
  ASSERT_TRUE(parts[0].empty());
  ASSERT_EQ("/bin/", parts[1]);
  ASSERT_TRUE(parts[2].empty());

  result = SqlTreeExprEval::is_like("/usr/bin/cat", parts);
  ASSERT_TRUE(result);
  result = SqlTreeExprEval::is_like("/usr/bin", parts);
  ASSERT_FALSE(result);
  result = SqlTreeExprEval::is_like("/usr/local/bin/cat", parts);
  ASSERT_TRUE(result);
  result = SqlTreeExprEval::is_like("/bin/", parts);
  ASSERT_TRUE(result);

}
