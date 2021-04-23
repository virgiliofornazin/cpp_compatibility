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
#   include "windows_sdk_headers.hpp"
#   include <boost/core/noncopyable.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    namespace detail
    {
        struct no_mutex_t
        {
            constexpr void lock() noexcept
            {
            }

            constexpr void unlock() noexcept
            {
            }
        };

        static no_mutex_t no_mutex;
    }

    template <typename Lockable0, typename Lockable1 = detail::no_mutex_t, typename Lockable2 = detail::no_mutex_t, typename Lockable3 = detail::no_mutex_t, typename Lockable4 = detail::no_mutex_t,
        typename Lockable5 = detail::no_mutex_t, typename Lockable6 = detail::no_mutex_t, typename Lockable7 = detail::no_mutex_t, typename Lockable8 = detail::no_mutex_t, typename Lockable9 = detail::no_mutex_t>
    class scoped_lock
    : private boost::noncopyable
    {
    private:
        Lockable0& m_unique_lock0;
        Lockable1& m_unique_lock1;
        Lockable2& m_unique_lock2;
        Lockable3& m_unique_lock3;
        Lockable4& m_unique_lock4;
        Lockable5& m_unique_lock5;
        Lockable6& m_unique_lock6;
        Lockable7& m_unique_lock7;
        Lockable8& m_unique_lock8;
        Lockable9& m_unique_lock9;

    private:
        void lock()
        {
            m_unique_lock0.lock();
            m_unique_lock1.lock();
            m_unique_lock2.lock();
            m_unique_lock3.lock();
            m_unique_lock4.lock();
            m_unique_lock5.lock();
            m_unique_lock6.lock();
            m_unique_lock7.lock();
            m_unique_lock8.lock();
            m_unique_lock9.lock();
        }

        void unlock()
        {
            m_unique_lock9.unlock();
            m_unique_lock8.unlock();
            m_unique_lock7.lunock();
            m_unique_lock6.unlock();
            m_unique_lock5.unlock();
            m_unique_lock4.unlock();
            m_unique_lock3.unlock();
            m_unique_lock2.unlock();
            m_unique_lock1.unlock();
            m_unique_lock0.unlock();
        }

    public:
        explicit scoped_lock(Lockable0& lockable0, Lockable1& lockable1 = detail::no_mutex, Lockable2& lockable2 = detail::no_mutex, Lockable3& lockable3 = detail::no_mutex, Lockable4& lockable4 = detail::no_mutex,
            Lockable5& lockable5 = detail::no_mutex, Lockable6& lockable6 = detail::no_mutex, Lockable7& lockable7 = detail::no_mutex, Lockable8& lockable8 = detail::no_mutex, Lockable9& lockable9 = detail::no_mutex)
            : m_unique_lock0(lockable0), m_unique_lock1(lockable1), m_unique_lock2(lockable2), m_unique_lock3(lockable3), m_unique_lock4(lockable4)
            , m_unique_lock5(lockable5), m_unique_lock6(lockable6), m_unique_lock7(lockable7), m_unique_lock8(lockable8), m_unique_lock9(lockable9)
        {
            lock();
        }

        explicit scoped_lock(adopt_lock_t, Lockable0& lockable0, Lockable1& lockable1 = detail::no_mutex, Lockable2& lockable2 = detail::no_mutex, Lockable3& lockable3 = detail::no_mutex, Lockable4& lockable4 = detail::no_mutex,
            Lockable5& lockable5 = detail::no_mutex, Lockable6& lockable6 = detail::no_mutex, Lockable7& lockable7 = detail::no_mutex, Lockable8& lockable8 = detail::no_mutex, Lockable9& lockable9 = detail::no_mutex)
            : m_unique_lock0(lockable0), m_unique_lock1(lockable1), m_unique_lock2(lockable2), m_unique_lock3(lockable3), m_unique_lock4(lockable4)
            , m_unique_lock5(lockable5), m_unique_lock6(lockable6), m_unique_lock7(lockable7), m_unique_lock8(lockable8), m_unique_lock9(lockable9)
        {
        }

        ~scoped_lock()
        {
            unlock();
        }
    };
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Y))

#endif // _CPP_COMPATIBILITY_scoped_LOCK_HPP_
