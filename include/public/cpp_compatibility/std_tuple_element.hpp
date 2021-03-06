#ifndef _CPP_COMPATIBILITY_STD_TUPLE_ELEMENT_HPP_
#define _CPP_COMPATIBILITY_STD_TUPLE_ELEMENT_HPP_

#include "prolog.hpp"

#if (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)
#   define CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_ELEMENT                        std
#   include <tuple>
#endif // (CPP_COMPATIBILITY_DIALECT >= CPP_COMPATIBILITY_DIALECT_0X)

#if (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))
#   ifndef CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_ELEMENT
#       define CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_ELEMENT                    CPP_COMPATIBILITY_NAMESPACE
#   endif // CPP_COMPATIBILITY_NAMESPACE_STD_TUPLE_ELEMENT

#   include "tuple_element.hpp"

namespace CPP_COMPATIBILITY_NAMESPACE
{
#error TODO
}

#endif // (defined(CPP_COMPATIBILITY_NO_STD_NAMESPACE) || (CPP_COMPATIBILITY_DIALECT < CPP_COMPATIBILITY_DIALECT_0X))

#endif // _CPP_COMPATIBILITY_STD_TUPLE_ELEMENT_HPP_
