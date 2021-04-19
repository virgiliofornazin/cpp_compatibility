#ifndef _CPP_COMPATIBILITY_DETAIL_PTHREAD_MUTEX_HPP_
#define _CPP_COMPATIBILITY_DETAIL_PTHREAD_MUTEX_HPP_

#include "../prolog.hpp"

#include <cassert>

#include <pthread.h>

namespace cpp_compatibility
{
    namespace detail
    {
        class pthread_mutex
        {
        public:
            typedef pthread_mutex_t& native_handle_type;

        private:
            pthread_mutex_t m_handle;

        public:
            constexpr explicit pthread_mutex(bool const recursive) noexcept
                : m_handle(PTHREAD_MUTEX_INITIALIZER)
            {
                int api_result;

                pthread_mutexattr_t attributes;

                api_result = ::pthread_mutexattr_init(std::addressof(attributes));

                assert(api_result == 0);

                api_result = ::pthread_mutexattr_settype(std::addressof(attributes), (recursive ? PTHREAD_MUTEX_RECURSIVE : PTHREAD_MUTEX_NORMAL));

                assert(api_result == 0);

                api_result = ::pthread_mutex_init(std::addressof(m_handle), std::addressof(attributes));

                assert(api_result == 0);

                api_result = ::pthread_mutexattr_destroy(std::addressof(attributes));

                assert(api_result == 0);
            }

            ~mutex()
            {
                int api_result;

                api_result = ::pthread_mutex_destroy(std::addressof(m_handle));

                assert(api_result == 0);
            }

            void lock()
            {
                int api_result;

                api_result = ::pthread_mutex_lock(std::addressof(m_handle));

                assert(api_result == 0);
            }

            bool try_lock()
            {
                int api_result;

                api_result = ::pthread_mutex_trylock(std::addressof(m_handle));

                bool result = (api_result == 0);

                assert((api_result == 0) || (api_result == EBUSY));

                return result;
            }

            void unlock()
            {
                int api_result;

                api_result = ::pthread_mutex_lock(std::addressof(m_handle));

                assert(api_result == 0);
            }

            native_handle_type native_handle()
            {
                return m_handle;
            }

        private:
            pthread_mutex()
            {
            }

            pthread_mutex(pthread_mutex const&) noexcept
            {
            }

            pthread_mutex& operator = (pthread_mutex const&)
            {
            }
        };

        typedef pthread_mutex mutex;
    }
}

#endif // _CPP_COMPATIBILITY_DETAIL_PTHREAD_MUTEX_HPP_
