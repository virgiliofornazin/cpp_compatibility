#ifndef _CPP_COMPATIBILITY_BIND_FRONT_HPP_
#define _CPP_COMPATIBILITY_BIND_FRONT_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_2A)
#   define CPP_COMPATIBILITY_NAMESPACE_BIND_FRONT                               std
#   include <functional>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_2A)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_2A))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_BIND_FRONT
#       define CPP_COMPATIBILITY_NAMESPACE_BIND_FRONT                           CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_BIND_FRONT

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/bind.hpp>
#   include "external_warnings_reset.hpp"

#   include "placeholders.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::bind;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_2A))

#endif // _CPP_COMPATIBILITY_BIND_FRONT_HPP_
