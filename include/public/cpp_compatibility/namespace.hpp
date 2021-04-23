#ifndef _CPP_COMPATIBILITY_NAMESPACE_HPP_
#define _CPP_COMPATIBILITY_NAMESPACE_HPP_

#include "prolog.hpp"

#if (defined(CPP_COMPATIBILITY_STD_NAMESPACE) && !defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) && !defined(CPP_COMPATIBILITY_NAMESPACE))
#   define CPP_COMPATIBILITY_NAMESPACE                                          std
#else // (defined(CPP_COMPATIBILITY_STD_NAMESPACE) && !defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) && !defined(CPP_COMPATIBILITY_NAMESPACE))
#   ifdef CPP_COMPATIBILITY_STD_NAMESPACE
#       undef CPP_COMPATIBILITY_STD_NAMESPACE
#   endif // CPP_COMPATIBILITY_STD_NAMESPACE
#   ifndef CPP_COMPATIBILITY_NAMESPACE
#       define CPP_COMPATIBILITY_NAMESPACE                                      cpp_compatibility
#   endif // CPP_COMPATIBILITY_NAMESPACE
#   ifndef CPP_COMPATIBILITY_NO_STD_NAMESPACE
#       define CPP_COMPATIBILITY_NO_STD_NAMESPACE
#   endif // CPP_COMPATIBILITY_NO_STD_NAMESPACE
#endif // (defined(CPP_COMPATIBILITY_STD_NAMESPACE) && !defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) && !defined(CPP_COMPATIBILITY_NAMESPACE))

#endif // _CPP_COMPATIBILITY_NAMESPACE_HPP_
