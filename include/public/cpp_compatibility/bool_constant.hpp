#ifndef _CPP_COMPATIBILITY_INTEGRAL_CONSTANT_HPP_
#define _CPP_COMPATIBILITY_INTEGRAL_CONSTANT_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_INTEGRAL_CONSTANT                        std
#   include <type_traits>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_INTEGRAL_CONSTANT
#       define CPP_COMPATIBILITY_NAMESPACE_INTEGRAL_CONSTANT                    CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_INTEGRAL_CONSTANT

#   include "integral_constant.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    template <typename T>
    struct bool_constant
        : integral_constant<bool, T>
    {
    };

    typedef bool_constant<true> true_type;
    typedef bool_constant<false> false_type;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_INTEGRAL_CONSTANT_HPP_
