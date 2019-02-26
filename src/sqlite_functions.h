#pragma once

#include "../include/simplesql.h"

/*
abs(X)
coalesce(X,Y,...)
glob(X,Y)
hex(X)
ifnull(X,Y)
instr(X,Y)
length(X)
like(X,Y)
lower(X)
ltrim(X)
ltrim(X,Y)
max(X,Y,...)
min(X,Y,...)
quote(X)
random()
round(X)
round(X,Y)
rtrim(X)
rtrim(X,Y)
substr(X,Y)
substr(X,Y,Z)
trim(X)
trim(X,Y)
typeof(X)
upper(X)
*/

struct StdSqlScalarFuncs : public SqlFunctionFactory {
  virtual ~StdSqlScalarFuncs() {}

  DynVal call(std::string function_name, std::vector<DynVal> &params, std::string &errmsg) override;

  // published here for unit test use only
  DynVal func_max(std::vector<DynVal> &params, std::string &errmsg);
};
