#ifndef _CPP_COMPATIBILITY_RECURSIVE_MUTEX_HPP_
#define _CPP_COMPATIBILITY_RECURSIVE_MUTEX_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   include <mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#include "external_warnings_silence.hpp"

#include <boost/thread/recursive_mutex.hpp>

#include "external_warnings_reset.hpp"

#include "lock_types.hpp"
#include "unique_lock.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    typedef boost::recursive_mutex recursive_mutex;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_RECURSIVE_MUTEX_HPP_
