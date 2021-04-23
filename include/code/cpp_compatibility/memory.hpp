#ifndef _CPP_COMPATIBILITY_MEMORY_HPP_
#define _CPP_COMPATIBILITY_MEMORY_HPP_

#include "dialect.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_MEMORY                                   std
#   include <memory>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_MEMORY
#       define CPP_COMPATIBILITY_NAMESPACE_MEMORY                               CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_MEMORY

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/core/addressof.hpp>
#   include <boost/smart_ptr/shared_ptr.hpp>
#   include <boost/smart_ptr/weak_ptr.hpp>
#   include <boost/smart_ptr/make_shared.hpp>
#   include <boost/move/unique_ptr.hpp>
#   include <boost/smart_ptr/make_unique.hpp>
#   include <boost/smart_ptr/enable_shared_from_this.hpp>
#   include <boost/smart_ptr/owner_less.hpp>
#   include "external_warnings_reset.hpp"

#   include "type_traits.hpp"

// #include <boost/smart_ptr/allocate_unique.hpp> // put in cpp_extensions

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::addressof;
    using boost::unique_ptr;
    using boost::shared_ptr;
    using boost::weak_ptr;
    using boost::enable_shared_from_this;
    using boost::owner_less;
    using boost::make_unique;
    using boost::make_shared;   
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_MEMORY_HPP_
