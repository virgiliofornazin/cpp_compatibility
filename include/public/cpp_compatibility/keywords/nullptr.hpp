#ifndef _CPP_COMPATIBILITY_KEYWORDS_NULLPTR_HPP_
#define _CPP_COMPATIBILITY_KEYWORDS_NULLPTR_HPP_

#include "../dialect.hpp"

#if (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X)
#	define nullptr																NULL
#endif // (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X)

#endif // _CPP_COMPATIBILITY_KEYWORDS_NULLPTR_HPP_