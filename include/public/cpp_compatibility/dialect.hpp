#ifndef _CPP_COMPATIBILITY_DIALECT_HPP_
#define _CPP_COMPATIBILITY_DIALECT_HPP_

#include "prolog.hpp"

/*
NOTE: Microsoft compilers defined _MSC_LANG as the value for C++ dialect in legacy preprocessor. There's a
compiler switch /Zc:__cplusplus that updates __cplusplus to correct version, so we must check which one we
should use for detecting C++ dialect.
*/

#ifdef _MSVC_LANG
#   define __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO                              _MSVC_LANG
#else // _MSVC_LANG
#   define __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO                              __cplusplus
#endif // _MSVC_LANG

/*
NOTE: The 'intermediate' C++ dialects (or drafts) are pre-defined as latest below approved dialect plus one,
to make difference in constants for testing. When compiling, the constant for current 'intermediate' dialect
will be updated with current value for real testing against __cplusplus (or _MSVC_LANG) with current value.
*/

#define CPP_COMPATIBILITY_DIALECT_03                                            199711L
#define CPP_COMPATIBILITY_DIALECT_0X                                            (CPP_COMPATIBILITY_DIALECT_03 + 1)
#define CPP_COMPATIBILITY_DIALECT_11                                            201103L
#define CPP_COMPATIBILITY_DIALECT_1Y                                            (CPP_COMPATIBILITY_DIALECT_11 + 1)
#define CPP_COMPATIBILITY_DIALECT_14                                            201402L
#define CPP_COMPATIBILITY_DIALECT_1Z                                            (CPP_COMPATIBILITY_DIALECT_14 + 1)
#define CPP_COMPATIBILITY_DIALECT_17                                            201703L
#define CPP_COMPATIBILITY_DIALECT_2A                                            (CPP_COMPATIBILITY_DIALECT_17 + 1)
#define CPP_COMPATIBILITY_DIALECT_20                                            202002L
#define CPP_COMPATIBILITY_DIALECT_2B                                            (CPP_COMPATIBILITY_DIALECT_20 + 1)

/*
Check for 'intermediate' C++ dialects and update definition to current defined value
*/
#if ((__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO > CPP_COMPATIBILITY_DIALECT_03) && (__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO < CPP_COMPATIBILITY_DIALECT_11))
#   undef CPP_COMPATIBILITY_DIALECT_0X
#   define CPP_COMPATIBILITY_DIALECT_0X                                         __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO
#elif ((__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO > CPP_COMPATIBILITY_DIALECT_11) && (__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO < CPP_COMPATIBILITY_DIALECT_14))
#   undef CPP_COMPATIBILITY_DIALECT_1Y
#   define CPP_COMPATIBILITY_DIALECT_1Y                                         __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO
#elif ((__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO > CPP_COMPATIBILITY_DIALECT_14) && (__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO < CPP_COMPATIBILITY_DIALECT_17))
#   undef CPP_COMPATIBILITY_DIALECT_1Z
#   define CPP_COMPATIBILITY_DIALECT_1Z                                         __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO
#elif ((__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO > CPP_COMPATIBILITY_DIALECT_17) && (__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO < CPP_COMPATIBILITY_DIALECT_20))
#   undef CPP_COMPATIBILITY_DIALECT_2A
#   define CPP_COMPATIBILITY_DIALECT_2A                                         __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO
#elif (__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO > CPP_COMPATIBILITY_DIALECT_20)
#   undef CPP_COMPATIBILITY_DIALECT_2B
#   define CPP_COMPATIBILITY_DIALECT_2B                                         __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO
#endif // (__CPP_COMPATIBILITY_DIALECT_CHECK_MACRO)

#define CPP_COMPATIBILITY_DIALECT                                               __CPP_COMPATIBILITY_DIALECT_CHECK_MACRO

#endif // _CPP_COMPATIBILITY_DIALECT_HPP_
