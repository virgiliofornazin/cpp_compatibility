#ifndef _CPP_COMPATIBILITY_JTHREAD_HPP_
#define _CPP_COMPATIBILITY_JTHREAD_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_2A)
#   define CPP_COMPATIBILITY_NAMESPACE_JTHREAD                                  std
#   include <thread>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_2A)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_2A))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_JTHREAD
#       define CPP_COMPATIBILITY_NAMESPACE_JTHREAD                              CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_JTHREAD

#   include "thread.hpp"
#   include "stop_source.hpp"
#   include "stop_token.hpp""

namespace CPP_COMPATIBILITY_NAMESPACE
{
#error TODO
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_2A))

#endif // _CPP_COMPATIBILITY_JTHREAD_HPP_
