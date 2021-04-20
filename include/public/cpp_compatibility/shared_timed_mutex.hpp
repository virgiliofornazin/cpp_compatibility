#ifndef _CPP_COMPATIBILITY_SHARED_TIMED_MUTEX_HPP_
#define _CPP_COMPATIBILITY_SHARED_TIMED_MUTEX_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Y)
#   include <shared_mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Y)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))

#include "external_warnings_silence.hpp"

#include <boost/thread/shared_mutex.hpp>

#include "external_warnings_reset.hpp"

#include "lock_types.hpp"
#include "unique_lock.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    typedef boost::shared_timed_mutex shared_timed_mutex;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))

#endif // _CPP_COMPATIBILITY_SHARED_TIMED_MUTEX_HPP_
