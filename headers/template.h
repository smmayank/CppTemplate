#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_
#include "debug.h"

#define lld long long int
#define LLD_FORMAT "%lld"

#define CASE_VAR __case_var__
#define CASE_INDEX __case_index__

#define ITERATE_CASE lld CASE_VAR; \
        LOG("Enter case no"); \
        GET(LLD_FORMAT, &CASE_VAR); \
        LOG("Total cases"); \
        LOG(LLD_FORMAT, CASE_VAR);\
        for(lld CASE_INDEX = 0; CASE_INDEX < CASE_VAR; CASE_INDEX++) \

#define GET(...) scanf(__VA_ARGS__);

#define GET_MAX(a,b) ((a)>(b)?(a):(b))

#define GET_MIN(a,b) ((a)<(b)?(a):(b))

#endif
