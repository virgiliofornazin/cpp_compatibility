#ifndef _CPP_COMPATIBILITY_UNIQUE_LOCK_HPP_
#define _CPP_COMPATIBILITY_UNIQUE_LOCK_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_UNIQUE_LOCK                              std
#   include <mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_UNIQUE_LOCK
#       define CPP_COMPATIBILITY_NAMESPACE_UNIQUE_LOCK                          CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_UNIQUE_LOCK

#   include "external_warnings_silence.hpp"
#   include <boost/thread/locks.hpp>
#   include "external_warnings_reset.hpp"

#   include "adopt_lock_t.hpp"
#   include "adopt_lock.hpp"
#   include "try_to_lock_t.hpp"
#   include "try_to_lock.hpp"
#   include "defer_lock_t.hpp"
#   include "defer_lock.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::unique_lock;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_UNIQUE_LOCK_HPP_
