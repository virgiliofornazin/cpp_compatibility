#ifndef _CPP_COMPATIBILITY_ADDRESSOF_HPP_
#define _CPP_COMPATIBILITY_ADDRESSOF_HPP_

#include "dialect.hpp"

#if (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X)

namespace CPP_COMPATIBILITY_NAMESPACE
{
    template <typename Type>
    constexpr Type* addressof(Type& value) noexcept
    {
        return &(value);
    }
}

#endif // (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X)

#endif // _CPP_COMPATIBILITY_ADDRESSOF_HPP_
