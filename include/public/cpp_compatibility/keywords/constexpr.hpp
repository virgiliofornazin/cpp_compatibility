#ifndef _CPP_COMPATIBILITY_KEYWORDS_CONSTEXPR_HPP_
#define _CPP_COMPATIBILITY_KEYWORDS_CONSTEXPR_HPP_

#include "../dialect.hpp"

#if !defined(__cpp_constexpr)
#	define constexpr															inline
#endif // !defined(__cpp_constexpr)

#define constexpr_11															constexpr
#define constexpr_14															constexpr
#define constexpr_17															constexpr
#define constexpr_2a															constexpr
#define constexpr_20															constexpr

#if defined(__cpp_constexpr)
#	if (__cpp_constexpr < 201907L)
#		undef constexpr_20
#		define constexpr_20														inline
#	elif (__cpp_constexpr < 201711L)
#		undef constexpr_2a
#		define constexpr_2a														inline
#	elif (__cpp_constexpr < 201603L)
#		undef constexpr_17
#		define constexpr_17														inline
#	elif (__cpp_constexpr < 201304L)
#		undef constexpr_14
#		define constexpr_14														inline
#	elif (__cpp_constexpr < 200704L)
#		undef constexpr_11
#		define constexpr_11														inline
#	endif // (__cpp_constexpr < [VERSION]L)
#endif // defined(__cpp_constexpr)

#endif // _CPP_COMPATIBILITY_KEYWORDS_CONSTEXPR_HPP_
