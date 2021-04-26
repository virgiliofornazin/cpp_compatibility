#ifndef _CPP_COMPATIBILITY_SWAP_HPP_
#define _CPP_COMPATIBILITY_SWAP_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_SWAP                                     std
#   include <algorithm>
#elif (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_SWAP                                     std
#   include <utility>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#ifdef CPP_COMPATIBILITY_NO_STD_NAMESPACE
#   ifndef CPP_COMPATIBILITY_NAMESPACE_SWAP
#       define CPP_COMPATIBILITY_NAMESPACE_SWAP                                 CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_SWAP

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/core/swap.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::swap;
}

#endif // CPP_COMPATIBILITY_NO_STD_NAMESPACE

#endif // _CPP_COMPATIBILITY_SWAP_HPP_
