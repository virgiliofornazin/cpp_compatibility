#ifndef _CPP_COMPATIBILITY_WINDOWS_SDK_HEADERS_HPP_
#define _CPP_COMPATIBILITY_WINDOWS_SDK_HEADERS_HPP_

#if (defined(_WIN32) || defined(WIN32))
#   include <ws2tcpip.h>
#   include <windows.h>
#   include <comdef.h>
#   include <ntverp.h>
#endif // (defined(_WIN32) || defined(WIN32))

#endif // _CPP_COMPATIBILITY_WINDOWS_SDK_HEADERS_HPP_
