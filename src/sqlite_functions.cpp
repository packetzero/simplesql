#include "_sqlexpr_private.h"
#include "sqlite_functions.h"

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

DynVal StdSqlScalarFuncs::call(std::string function_name, std::vector<DynVal> &params, std::string &errmsg) {
  if (function_name == "max") {
    return func_max(params, errmsg);
  }
  return DynVal();
}

inline DynVal dynval_max(DynVal &a, DynVal &b) {
  switch(a.type()) {
    case TFLOAT64:
    case TFLOAT32:
      return (a.as_double() >= b.as_double() ? a : b);
    case TSTRING:
      return (a.as_s() >= b.as_s() ? a : b);
    default:
      return (a.as_i64() >= b.as_i64() ? a : b);
  }
}

DynVal StdSqlScalarFuncs::func_max(std::vector<DynVal> &params, std::string &errmsg) {
  DynVal retval;
  for (DynVal param : params) {

    if (!param.valid()) return param;  // return null if any param null

    if (!retval.valid()) {
      retval = param;
      continue;
    }
    retval = dynval_max(retval, param);
  }
  return retval;
}
