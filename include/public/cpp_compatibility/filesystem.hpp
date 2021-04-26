#ifndef _CPP_COMPATIBILITY_FILESYSTEM_HPP_
#define _CPP_COMPATIBILITY_FILESYSTEM_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Z)
#   define CPP_COMPATIBILITY_NAMESPACE_FILESYSTEM                               std
#   include <filesystem>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_1Z)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Z))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_FILESYSTEM
#       define CPP_COMPATIBILITY_NAMESPACE_FILESYSTEM                           CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_FILESYSTEM

#   include "external_warnings_silence.hpp"
#   include "windows_sdk_headers.hpp"
#   include <boost/filesystem.hpp>
#   include "external_warnings_reset.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
    namespace filesystem = boost::filesystem;
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_1Z))

#endif // _CPP_COMPATIBILITY_FILESYSTEM_HPP_
