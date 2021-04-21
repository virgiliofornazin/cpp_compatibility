#ifndef _CPP_COMPATIBILITY_SCOPED_LOCK_HPP_
#define _CPP_COMPATIBILITY_SCOPED_LOCK_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Z)
#   define CPP_COMPATIBILITY_NAMESPACE_SCOPED_LOCK                              std
#   include <mutex>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Z))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_SCOPED_LOCK
#       define CPP_COMPATIBILITY_NAMESPACE_SCOPED_LOCK                          CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_SCOPED_LOCK

#   include "external_warnings_silence.hpp"
#   include <boost/thread/locks.hpp>
#   include <boost/core/noncopyable.hpp>
#   include "external_warnings_reset.hpp"

#   include "unique_lock.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    template <typename Lockable>
    class scoped_lock
        : private boost::noncopyable
    {
    private:
        unique_lock<Lockable> m_lock;

    public:
        explicit scoped_lock(Lockable& lockable)
            : m_lock(lockable)
        {
        }

        explicit scoped_lock(adopt_lock_t, Lockable& lockable)
            : m_lock(lockable, adopt_lock_t())
        {
        }
    };
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))

#endif // _CPP_COMPATIBILITY_scoped_LOCK_HPP_
