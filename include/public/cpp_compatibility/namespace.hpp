#ifndef _CPP_COMPATIBILITY_NAMESPACE_HPP_
#define _CPP_COMPATIBILITY_NAMESPACE_HPP_

#ifndef CPP_COMPATIBILITY_NAMESPACE
#   define CPP_COMPATIBILITY_NAMESPACE                                          std
#   undef CPP_COMPATIBILITY_NO_STD_NAMESPACE
#else // CPP_COMPATIBILITY_NAMESPACE
#   define CPP_COMPATIBILITY_NO_STD_NAMESPACE                                   std
#endif // CPP_COMPATIBILITY_NAMESPACE

#endif // _CPP_COMPATIBILITY_NAMESPACE_HPP_