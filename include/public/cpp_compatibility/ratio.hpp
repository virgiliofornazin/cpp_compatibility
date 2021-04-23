#ifndef _CPP_COMPATIBILITY_RATIO_HPP_
#define _CPP_COMPATIBILITY_RATIO_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_RATIO                                    std
#   include <ratio>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_RATIO
#       define CPP_COMPATIBILITY_NAMESPACE_RATIO                                CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_RATIO

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/ratio.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::ratio;

    namespace detail
    {
        template <typename Type>
        struct boost_ratio_from
            : boost::false_type
        {
        };

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
        template <intmax_t Num, intmax_t Denom>
        struct boost_ratio_from<std::ratio<Num, Denom>>
            : boost::true_type
        {
            typedef boost::ratio<Num, Denom> type;
        };
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

        template <intmax_t Num, intmax_t Denom>
        struct boost_ratio_from<boost::ratio<Num, Denom>>
            : boost::true_type
        {
            typedef boost::ratio<Num, Denom> type;
        };
    }
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_RATIO_HPP_
