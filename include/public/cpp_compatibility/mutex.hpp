#ifndef _CPP_COMPATIBILITY_MUTEX_
#define _CPP_COMPATIBILITY_MUTEX_

#include "dialect.hpp"
#include "keywords.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#	include <mutex
#else // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#ifndef CPP_COMPATIBILITY_MUTEX
#	ifdef _WIN32
#		include <detail/windows_mutex.hpp>
#	endif // _WIN32
#endif // CPP_COMPATIBILITY_MUTEX

#ifndef CPP_COMPATIBILITY_MUTEX
#	ifdef _REENTRANT
#		include <detail/pthread_mutex.hpp>
#	endif // _REENTRANT
#endif // CPP_COMPATIBILITY_MUTEX

namespace std
{
	class mutex
	{
	private:
		typedef cpp_compatibility::detail::mutex mutex_type;
		typedef mutex_type::native_handle_type native_handle_type;

	private:
		mutex_type m_mutex;

	public:
		constexpr mutex() noexcept
		{
		}

		~mutex()
		{
		}

		void lock()
		{
			m_mutex.lock();
		}

		bool try_lock()
		{
			return m_mutex.try_lock();
		}

		void unlock()
		{
			m_mutex.unlock();
		}

		native_handle_type native_handle()
		{
			return m_mutex.native_handle();
		}

	private:
		mutex(mutex const&) noexcept
		{
		}

		mutex& operator = (mutex const&)
		{
		}
	};
}

#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#endif // _CPP_COMPATIBILITY_MUTEX_
