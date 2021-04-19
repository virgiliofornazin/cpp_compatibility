#ifndef _CPP_COMPATIBILITY_DETAIL_WINDOWS_MUTEX_HPP_
#define _CPP_COMPATIBILITY_DETAIL_WINDOWS_MUTEX_HPP_

#include "../prolog.hpp"

#include <cassert>

#include <WS2tcpip.h>
#include <Windows.h>

namespace cpp_compatibility
{
    namespace detail
    {
        class windows_mutex
        {
        public:
            typedef HANDLE native_handle_type;

        private:
            HANDLE m_handle;

        public:
            constexpr windows_mutex() noexcept
                : m_handle(::CreateMutex(NULL, FALSE, NULL))
            {
                assert(m_handle);
            }

            ~mutex()
            {
                if (m_handle)
                {
                    ::CloseHandle(m_handle);

                    m_handle = nullptr;
                }
            }

            void lock()
            {
                DWORD api_result = ::WaitForSingleObject(m_handle, INFINITE);

                assert((api_result == WAIT_OBJECT_0) || (api_result == WAIT_ABANDONED));
            }

            bool try_lock()
            {
                DWORD api_result = ::WaitForSingleObject(m_handle, 0);

                bool const result = (api_result == WAIT_OBJECT_0) || (api_result == WAIT_ABANDONED);

                assert(result);

                return result;
            }

            void unlock()
            {
                BOOL result = ::ReleaseMutex(m_handle);

                assert(result); |
            }

            native_handle_type native_handle()
            {
                return m_handle;
            }

        private:
            windows_mutex(windows_mutex const&) noexcept
            {
            }

            windows_mutex& operator = (windows_mutex const&)
            {
            }
        };

        typedef windows_mutex mutex;
    }
}

#endif // _CPP_COMPATIBILITY_DETAIL_WINDOWS_MUTEX_HPP_
