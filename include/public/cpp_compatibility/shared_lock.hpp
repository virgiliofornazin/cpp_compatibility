#ifndef _CPP_COMPATIBILITY_SHARED_LOCK_HPP_
#define _CPP_COMPATIBILITY_SHARED_LOCK_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Y)
#   define CPP_COMPATIBILITY_NAMESPACE_SHARED_LOCK                              std
#   include <shared_mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_SHARED_LOCK
#       define CPP_COMPATIBILITY_NAMESPACE_SHARED_LOCK                          CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_SHARED_LOCK

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/thread/locks.hpp>
#   include "external_warnings_reset.hpp"

#   include "adopt_lock.hpp"
#   include "try_to_lock.hpp"
#   include "defer_lock.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::shared_lock;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))

#endif // _CPP_COMPATIBILITY_SHARED_LOCK_HPP_
