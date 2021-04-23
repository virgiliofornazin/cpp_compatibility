#ifndef _CPP_COMPATIBILITY_FUNCTION_HPP_
#define _CPP_COMPATIBILITY_FUNCTION_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_FUNCTION                                 std
#   include <functional>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_FUNCTION
#       define CPP_COMPATIBILITY_NAMESPACE_FUNCTION                             CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_FUNCTION

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/function.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::function;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_FUNCTION_HPP_
