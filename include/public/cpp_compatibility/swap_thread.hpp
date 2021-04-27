#ifndef _CPP_COMPATIBILITY_SWAP_THREAD_HPP_
#define _CPP_COMPATIBILITY_SWAP_THREAD_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_SWAP_THREAD                              std
#   include <memory>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_SWAP_THREAD
#       define CPP_COMPATIBILITY_NAMESPACE_SWAP_THREAD                          CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_SWAP_THREAD

#   include "swap.hpp"
#   include "thread.hpp"

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_SWAP_THREAD_HPP_
