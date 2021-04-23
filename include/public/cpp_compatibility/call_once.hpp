#ifndef _CPP_COMPATIBILITY_CALL_ONCE_HPP_
#define _CPP_COMPATIBILITY_CALL_ONCE_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_CALL_ONCE                                std
#   include <mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_CALL_ONCE
#       define CPP_COMPATIBILITY_NAMESPACE_CALL_ONCE                            CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_CALL_ONCE

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/thread/once.hpp>
#   include "external_warnings_reset.hpp"

#   include "once_flag.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::call_once;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_call_once_HPP_
