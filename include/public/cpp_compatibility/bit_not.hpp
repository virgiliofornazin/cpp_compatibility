#ifndef _CPP_COMPATIBILITY_BIT_NOT_HPP_
#define _CPP_COMPATIBILITY_BIT_NOT_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Y)
#   define CPP_COMPATIBILITY_NAMESPACE_BIT_NOT                                  std
#   include <functional>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Y)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_BIT_NOT
#       define CPP_COMPATIBILITY_NAMESPACE_BIT_NOT                              CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_BIT_NOT

namespace CPP_COMPATIBILITY_NAMESPACE
{
    template <class Type = void>
    struct bit_not
    {
        constexpr Type operator()(Type const& value) const
        {
            return ~value;
        }
    };

    template <>
    struct bit_not<void>
    {
        template <class Type>
#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X1)
        constexpr Type operator()(Type&& _Left) const
        {
            return ~forward<Type>(_Left);
#else // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
        Type operator()(Type const& _Left) const
        {
            return ~forward<Type>(_Left);
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
        }

        using is_transparent = int;
    };
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))

#endif // _CPP_COMPATIBILITY_BIT_NOT_HPP_
