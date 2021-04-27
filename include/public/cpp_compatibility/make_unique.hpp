#ifndef _CPP_COMPATIBILITY_MAKE_UNIQUE_HPP_
#define _CPP_COMPATIBILITY_MAKE_UNIQUE_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_MAKE_UNIQUE                              std
#   include <memory>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_MAKE_UNIQUE
#       define CPP_COMPATIBILITY_NAMESPACE_MAKE_UNIQUE                          CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_MAKE_UNIQUE

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/make_unique.hpp>
#   include "external_warnings_reset.hpp"

#   include "unique_ptr.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::make_unique;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_MAKE_UNIQUE_HPP_
