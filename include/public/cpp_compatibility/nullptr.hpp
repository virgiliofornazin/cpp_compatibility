#ifndef _CPP_COMPATIBILITY_NULLPTR_HPP_
#define _CPP_COMPATIBILITY_NULLPTR_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   include <type_traits>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#include <boost/type_traits.hpp>
#include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_NULLPTR_HPP_
