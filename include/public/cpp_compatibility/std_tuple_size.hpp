#ifndef _CPP_COMPATIBILITY_STD_TUPLE_SIZE_HPP_
#define _CPP_COMPATIBILITY_STD_TUPLE_SIZE_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_SIZE                           std
#   include <tuple>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_SIZE
#       define CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_SIZE                       CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_SIZE

#   include "tuple.hpp"
#   include "tuple_size.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
#error TODO
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_STD_TUPLE_SIZE_HPP_
