#ifndef _CPP_COMPATIBILITY_IS_PLACEHOLDER_HPP_
#define _CPP_COMPATIBILITY_IS_PLACEHOLDER_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_IS_PLACEHOLDER                           std
#   include <functional>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_IS_PLACEHOLDER
#       define CPP_COMPATIBILITY_NAMESPACE_IS_PLACEHOLDER                       CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_IS_PLACEHOLDER

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/bind/is_placeholder.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    namespace placeholdders = boost::is_placeholder;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_IS_PLACEHOLDER_HPP_
