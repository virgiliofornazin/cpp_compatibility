#ifndef _CPP_COMPATIBILITY_SHARED_MUTEX_HPP_
#define _CPP_COMPATIBILITY_SHARED_MUTEX_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_SHARED_MUTEX                             std
#   include <shared_mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_SHARED_MUTEX
#       define CPP_COMPATIBILITY_NAMESPACE_SHARED_MUTEX                         CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_SHARED_MUTEX

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/thread/shared_mutex.hpp>
#   include "external_warnings_reset.hpp"

#   include "lock_types.hpp"
#   include "unique_lock.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::shared_mutex;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_SHARED_MUTEX_HPP_
