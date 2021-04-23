#ifndef _CPP_COMPATIBILITY_CONSTEXPR_HPP_
#define _CPP_COMPATIBILITY_CONSTEXPR_HPP_

#include "prolog.hpp"

#if ((CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X) || !defined(__cpp_constexpr))
#   define constexpr                                                            const
#endif // ((CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X) || !defined(__cpp_constexpr))

#define cpp_compatibility_constexpr_11                                          constexpr
#define cpp_compatibility_constexpr_14                                          constexpr
#define cpp_compatibility_constexpr_17                                          constexpr
#define cpp_compatibility_constexpr_2a                                          constexpr
#define cpp_compatibility_constexpr_20                                          constexpr

#if defined(__cpp_constexpr)
#   if (__cpp_constexpr < 201907L)
#       undef cpp_compatibility_constexpr_20
#       define cpp_compatibility_constexpr_20                                   const
#   elif (__cpp_constexpr < 201711L)
#       undef cpp_compatibility_constexpr_2a
#       define cpp_compatibility_constexpr_2a                                   const                                  
#   elif (__cpp_constexpr < 201603L)
#       undef cpp_compatibility_constexpr_17
#       define cpp_compatibility_constexpr_17                                   const
#   elif (__cpp_constexpr < 201304L)
#       undef cpp_compatibility_constexpr_14
#       define cpp_compatibility_constexpr_14                                   const
#   elif (__cpp_constexpr < 200704L)
#       undef cpp_compatibility_constexpr_11
#       define cpp_compatibility_constexpr_11                                   const
#   endif // (__cpp_constexpr < [VERSION]L)
#endif // defined(__cpp_constexpr)

#endif // _CPP_COMPATIBILITY_CONSTEXPR_HPP_
