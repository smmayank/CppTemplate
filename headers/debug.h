#ifndef _DEBUG_H_
#define _DEBUG_H_
#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__); printf("\n");
#define LOG_ARRAY(array_pointer, size, identifier) { \
                lld _arr_index_; \
                for(_arr_index_=0; _arr_index_<size; _arr_index_++) \
                { \
                        printf(identifier, array_pointer[_arr_index_]); \
                        printf(", "); \
                } \
                LOG("\n") }
#else
#define LOG(...)
#define LOG_ARRAY(array_pointer, size, type)
#endif
#endif
