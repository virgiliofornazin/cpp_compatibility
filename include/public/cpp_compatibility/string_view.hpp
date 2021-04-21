#ifndef _CPP_COMPATIBILITY_STRING_VIEW_HPP_
#define _CPP_COMPATIBILITY_STRING_VIEW_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_STRING_VIEW                              std
#   include <string_view>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_STRING_VIEW
#       define CPP_COMPATIBILITY_NAMESPACE_STRING_VIEW                          CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_STRING_VIEW

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/utility/string_view.hpp>
#   include "external_warnings_reset.hpp"
#   include "hash.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    using boost::detail::basic_string_view;
    using boost::string_view;
    using boost::wstring_view;
    using boost::u8string_view;
    using boost::u16string_view;
    using boost::u32string_view;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_STRING_VIEW_HPP_
