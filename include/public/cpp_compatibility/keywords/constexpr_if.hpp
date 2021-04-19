#ifndef _CPP_COMPATIBILITY_KEYWORDS_CONSTEXPR_IF_HPP_
#define _CPP_COMPATIBILITY_KEYWORDS_CONSTEXPR_IF_HPP_

#include "../dialect.hpp"

#if defined(__cpp_if_constexpr)
#	define constexpr_if															constexpr
#else  // defined(__cpp_if_constexpr)
#	define constexpr_if
#endif // defined(__cpp_if_constexpr)

#endif // _CPP_COMPATIBILITY_KEYWORDS_CONSTEXPR_IF_HPP_
