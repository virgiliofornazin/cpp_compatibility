#ifndef _CPP_COMPATIBILITY_IF_CONSTEXPR_HPP_
#define _CPP_COMPATIBILITY_IF_CONSTEXPR_HPP_

#include "dialect.hpp"

#if defined(__cpp_if_constexpr)
#   define if_constexpr                                                         if constexpr
#else  // defined(__cpp_if_constexpr)
#   define if_constexpr                                                         if
#endif // defined(__cpp_if_constexpr)

#endif // _CPP_COMPATIBILITY_IF_CONSTEXPR_HPP_
