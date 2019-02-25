#include <gtest/gtest.h>
#include <string>
using namespace std;

#include "../include/simplesql.h"
#include "../src/_sqlexpr_eval.hpp"

class SqlExecTest : public ::testing::Test {
protected:
  virtual void SetUp() {  }


  int exec_sql(std::string sql_expr)
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

    int result = simplesql::eval(expr, state);
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

TEST_F(SqlExecTest, integer_arith) {
  int result = exec_sql("(3 - 1) * (1 + 3) / (2)");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(4, result);
}

TEST_F(SqlExecTest, bool_false) {
  int result = exec_sql("0 OR (1 = 1) AND (3 = 4)");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(0, result);
}


TEST_F(SqlExecTest, bool_true) {
  int result = exec_sql("1 OR (0 = 1) AND 1");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(1, result);
}

static const std::string SQL_WIN_EVENT = "((provider_name = 'Microsoft-Windows-Sysmon') OR (provider_name = 'Microsoft-Windows-Security-Auditing' AND eventid in (1102, 1104, 5632, 4738, 4739, 4740, 4741, 4743, 6281, 4624, 4881, 4754, 643, 4756, 4757, 4758, 4767, 4768, 4719, 4649, 4769, 4898, 4771, 5030, 4776, 4905, 5034, 5035, 5038, 4664, 4794, 4896, 1102, 4688, 4690, 4697, 4698, 4880, 4625, 4713, 4714, 4720, 4648, 4722, 4724, 4725, 4726, 4727, 4728, 4729, 4950, 4730, 4731, 4732, 4733, 4734, 4782, 6006, 4770, 4772)) OR (provider_name = 'Microsoft-Windows-PowerShell' AND eventid != 40961 AND eventid != 40962) OR (provider_name = 'PowerShell') OR (provider_name = 'Microsoft-Windows-Windows Defender') OR (provider_name = 'Service Control Manager') OR (provider_name = 'Microsoft-Windows-TaskScheduler' AND eventid in (106)) OR (provider_name = 'Microsoft-Windows-AppLocker') OR (provider_name = 'Microsoft-Windows-Eventlog' AND eventid in (104)) OR (provider_name = 'EventLog' AND eventid in (6008)) OR (provider_name = 'Microsoft-Windows-SoftwareRestrictionPolicies' AND eventid in (865, 866, 867, 868, 882)) OR (provider_name = 'EMET' AND eventid in (2)) OR (provider_name = 'Microsoft-Windows-WindowsUpdateClient' AND eventid in (20, 31, 33, 25, 32)) OR (provider_name = 'Microsoft-Windows-Windows Firewall with Advanced Security' AND eventid in (2004, 2005, 2006, 2033)) OR (provider_name = 'Microsoft-Windows-CodeIntegrity' AND eventid in (3001, 3002, 3003, 3004, 3010, 3023)) OR (provider_name = 'Microsoft-Windows-Kernel-PNP' AND eventid in (219)) OR (provider_name = 'Microsoft-Windows-GroupPolicy' AND eventid in (1125, 1127, 1129)) OR (provider_name = 'Microsoft-Windows-GroupPolicy' AND eventid in (1125, 1127, 1129)) OR (provider_name = 'MSSQLSERVER' AND eventid in (15457, 18452, 18456)) OR (provider_name in ('Microsoft-Windows-MountMgr', 'MountMgr') AND eventid in (100)) OR (provider_name = 'Microsoft-Windows-DNSServer' AND eventid in (541)) OR (provider_name = 'Microsoft-Windows-DNS-Server-Service' AND eventid in (541)))";

TEST_F(SqlExecTest, complex_with_vars_true) {
  _valueStore.obj["provider_name"] = "Microsoft-Windows-Security-Auditing";
  _valueStore.obj["eventid"] = "4727";
  int result = exec_sql(SQL_WIN_EVENT);
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(1, result);
}

TEST_F(SqlExecTest, complex_with_vars_false) {
  _valueStore.obj["provider_name"] = "Microsoft-Windows-Security-Auditing";
  _valueStore.obj["eventid"] = "5555";
  int result = exec_sql(SQL_WIN_EVENT);
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(0, result);
}

static const std::string SQL_FILE_PATH = "file_path NOT IN ('/bin/grep', '/bin/cat', '/bin/bash', '/bin/ps', '/usr/bin/tr', '/bin/mkdir', '/bin/uname', '/bin/cp', '/usr/bin/make', '/bin/sed', '/bin/rm', '/usr/bin/dpkg', '/usr/bin/cat', '/usr/bin/gpg', '/usr/bin/gcc-5', '/usr/bin/wc', '/usr/bin/mawk', '/bin/sleep', '/usr/bin/id', '/usr/bin/head', '/usr/bin/locale', '/bin/tar', '/bin/run-parts', '/bin/hostname', '/bin/gzip', '/usr/bin/xargs', '/bin/ls')";

TEST_F(SqlExecTest, long_string_in_true) {
  _valueStore.obj["file_path"] = "/usr/local/bin/nc";
  int result = exec_sql(SQL_FILE_PATH);
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(1, result);
}

TEST_F(SqlExecTest, long_string_in_false) {
  _valueStore.obj["file_path"] = "/usr/bin/cat";
  int result = exec_sql(SQL_FILE_PATH);
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(0, result);
}

TEST_F(SqlExecTest, like_test) {
  _valueStore.obj["path"] = "/usr/bin/armitage";
  int result = exec_sql("path LIKE '%armitage%' AND path LIKE '/usr/bin/%' AND path NOT LIKE '/usr/local/bin'");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(1, result);
}

TEST_F(SqlExecTest, var_like) {
  _valueStore.obj["file1"] = "/usr/bin/armitage";
  _valueStore.obj["file2"] = "/usr/bin/armitage/v2/armi";
  _valueStore.obj["file3"] = "armitage";
  int result = exec_sql("file1 LIKE '%armitage%' AND file2 LIKE '%armitage%' AND file3 LIKE '%armitage%'");
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(1, result);
}

TEST_F(SqlExecTest, precedence_op_div) {
  int result = exec_sql("1 + 12 - 4 / 2");  // 1 + 12 - (4 / 2 )
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(11, result);
}

TEST_F(SqlExecTest, precedence_op_mul) {
  int result = exec_sql("8 - 2 * 4 - 4");  // 8 - (2 * 4) - 4
  ASSERT_FALSE(_hasParseError || _hasExecError);
  ASSERT_EQ(-4, result);
}
