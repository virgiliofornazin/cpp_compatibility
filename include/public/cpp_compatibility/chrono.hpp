#ifndef _CPP_COMPATIBILITY_CHRONO_HPP_
#define _CPP_COMPATIBILITY_CHRONO_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   include <chrono>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#include <boost/chrono.hpp>
#include "external_warnings_reset.hpp"

#include "ratio.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    namespace detail
    {
        template <typename Type>
        struct boost_chrono_duration_from
            : boost::false_type
        {
        };

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
        template <typename Rep, typename Period>
        struct boost_chrono_duration_from<std::chrono::duration<Rep, Period>>
            : boost::true_type
        {
            typedef typename boost::enable_if_c<boost_ratio_from<Period>::value, typename boost_ratio_from<Period>::type>::type period_type;

            typedef typename boost::chrono::duration<Rep, period_type> type;
        };
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

        template <typename Rep, typename Period>
        struct boost_chrono_duration_from<boost::chrono::duration<Rep, Period>>
            : boost::true_type
        {
            typename boost::chrono::duration<Rep, Period> type;
        };

        template <typename Type>
        struct boost_chrono_clock_from
            : boost::false_type
        {
        };

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
        template <>
        struct boost_chrono_clock_from<std::chrono::system_clock>
            : boost::true_type
        {
            typename boost::chrono::system_clock type;
        };

        template <>
        struct boost_chrono_clock_from<std::chrono::steady_clock>
            : boost::true_type
        {
            typename boost::chrono::steady_clock type;
        };
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

        template <>
        struct boost_chrono_clock_from<boost::chrono::system_clock>
            : boost::true_type
        {
            typename boost::chrono::system_clock type;
        };

        template <>
        struct boost_chrono_clock_from<boost::chrono::steady_clock>
            : boost::true_type
        {
            typename boost::chrono::steady_clock type;
        };

        template <typename Type>
        struct boost_chrono_time_point_from
            : boost::false_type
        {
        };

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
        template <typename Clock, typename Duration>
        struct boost_chrono_time_point_from<std::chrono::time_point<Clock, Duration>>
            : boost::true_type
        {
            typedef typename boost::enable_if_c<boost_chrono_clock_from<Clock>::value, typename boost_chrono_clock_from<Clock>::type>::type clock_type;
            typedef typename boost::enable_if_c<boost_chrono_duration_from<Duration>::value, typename boost_chrono_duration_from<Duration>::type>::type duration_type;

            typename boost::chrono::time_point<clock_type, duration_type> type;
        };
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

        template <typename Clock, typename Duration>
        struct boost_chrono_time_point_from<boost::chrono::time_point<Clock, Duration>>
            : boost::true_type
        {
            typename boost::chrono::time_point<Clock, Duration> type;
        };

        template <class Rep, class Period>
        static inline typename boost_chrono_duration_from<std::chrono::duration<Rep, Period>>::type
            duration_from_std(std::chrono::duration<Rep, Period> const& duration) noexcept
        {
            typename boost_chrono_duration_from<std::chrono::duration<Rep, Period>>::type result(duration.count());

            return result;
        }

        template <class Clock, class Duration>
        static inline typename boost_chrono_time_point_from<std::chrono::time_point<Clock, Duration>>::type
            time_point_from_std(std::chrono::time_point<Clock, Duration> const& time_point) noexcept
        {
            Duration time_since_epoch(time_point.time_since_epoch());
            typename boost_chrono_duration_from<Duration>::type time_since_epoch_converted = duration_from_std(time_since_epoch);
            typename boost_chrono_time_point_from<std::chrono::time_point<Clock, Duration>>::type result(time_since_epoch_converted);

            return result;
        }
    }
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_CHRONO_HPP_
