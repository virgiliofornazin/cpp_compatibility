#ifndef _CPP_COMPATIBILITY_LOCK_TYPES_HPP_
#define _CPP_COMPATIBILITY_LOCK_TYPES_HPP_

#include "prolog.hpp"

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#include "external_warnings_silence.hpp"

#include <boost/thread/lock_types.hpp>

#include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    typedef boost::defer_lock_t defer_lock_t;
    typedef boost::adopt_lock_t adopt_lock_t;
    typedef boost::try_to_lock_t try_to_lock_t;

    static constexpr defer_lock_t defer_lock;
    static constexpr adopt_lock_t adopt_lock;
    static constexpr try_to_lock_t try_to_lock;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_LOCK_TYPES_HPP_
