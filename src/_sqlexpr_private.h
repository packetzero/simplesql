#ifndef _SQLEXPR_PRIVATE_H_
#define _SQLEXPR_PRIVATE_H_

#include "../include/simplesql.h"

#define WITH_ASSERTS
#ifdef WITH_ASSERTS
#include <assert.h>
#define ASSERT(a) assert(a)
#else
#define ASSERT(a)
#endif

#endif // _SQLEXPR_PRIVATE_H_
