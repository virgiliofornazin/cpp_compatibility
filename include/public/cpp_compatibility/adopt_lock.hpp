#ifndef _CPP_COMPATIBILITY_ADOPT_LOCK_HPP_
#define _CPP_COMPATIBILITY_ADOPT_LOCK_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_ADOPT_LOCK                               std
#   include <mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_ADOPT_LOCK
#       define CPP_COMPATIBILITY_NAMESPACE_ADOPT_LOCK                           CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_ADOPT_LOCK

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/thread/lock_types.hpp>
#   include "external_warnings_reset.hpp"

#   include "adopt_lock_t.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::adopt_lock;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_ADOPT_LOCK_HPP_
