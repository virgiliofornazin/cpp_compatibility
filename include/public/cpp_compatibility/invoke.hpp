#ifndef _CPP_COMPATIBILITY_INVOKE_HPP_
#define _CPP_COMPATIBILITY_INVOKE_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Z)
#   define CPP_COMPATIBILITY_NAMESPACE_INVOKE                                   std
#   include <functional>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Z)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Z))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_INVOKE
#       define CPP_COMPATIBILITY_NAMESPACE_INVOKE                               CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_INVOKE

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/fusion/functional/invocation/invoke.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::fusion::invoke;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Z))

#endif // _CPP_COMPATIBILITY_INVOKE_HPP_
