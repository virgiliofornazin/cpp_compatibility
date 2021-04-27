#ifndef _CPP_COMPATIBILITY_MAKE_TUPLE_HPP_
#define _CPP_COMPATIBILITY_MAKE_TUPLE_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Z)
#   define CPP_COMPATIBILITY_NAMESPACE_TUPLE                                    std
#   include <tuple>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Z)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Z))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_TUPLE
#       define CPP_COMPATIBILITY_NAMESPACE_TUPLE                                CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_TUPLE

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include "boost/tuple/tuple.hpp"
#   include "boost/tuple/tuple_comparison.hpp"
#   include "boost/tuple/tuple_io.hpp"
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::make_tuple;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Z))

#endif // _CPP_COMPATIBILITY_MAKE_TUPLE_HPP_
