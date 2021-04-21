#ifndef _CPP_COMPATIBILITY_ONCE_FLAG_HPP_
#define _CPP_COMPATIBILITY_ONCE_FLAG_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_ONCE_FLAG                                std
#   include <mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_ONCE_FLAG
#       define CPP_COMPATIBILITY_NAMESPACE_ONCE_FLAG                            CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_ONCE_FLAG

#   include "external_warnings_silence.hpp"
#   include <boost/thread/once.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    class once_flag
        : public boost::once_flag
    {
    public:
        constexpr once_flag() noexcept
            : boost::once_flag(BOOST_ONCE_INIT)
        {
        }
    };
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_ONCE_FLAG_HPP_
