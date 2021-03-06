// Copyright 2017-2018 by Martin Moene
//
// https://github.com/martinmoene/ring-span-lite
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifndef ring_span_lite_T_INCLUDED
#define ring_span_lite_T_INCLUDED

// Compiler detection (C++17 is speculative):

#define nsrs_CPP11_OR_GREATER  ( __cplusplus >= 201103L )
#define nsrs_CPP14_OR_GREATER  ( __cplusplus >= 201402L )
#define nsrs_CPP17_OR_GREATER  ( __cplusplus >= 201700L )

// Determine MSVC version (e.g. 14 is VC14, (VS2015/VS2017):

#if defined(_MSC_VER ) && !defined(__clang__)
# define nsrs_COMPILER_MSVC_VER      (_MSC_VER )
# define nsrs_COMPILER_MSVC_VERSION  (_MSC_VER / 10 - 10 * ( 5 + (_MSC_VER < 1900 ) ) )
#else
# define nsrs_COMPILER_MSVC_VER      0
# define nsrs_COMPILER_MSVC_VERSION  0
#endif

// Consider VC14 as C++11, C++14 for SG14 ring_span:

#if nsrs_COMPILER_MSVC_VERSION >= 140
# undef  nsrs_CPP11_OR_GREATER
# define nsrs_CPP11_OR_GREATER  1
# undef  nsrs_CPP14_OR_GREATER
# define nsrs_CPP14_OR_GREATER  1
#endif

#include "sg14/sg14-ring.h"
#include "lest_cpp03.hpp"

using namespace sg14;

#define ring_span_lite_VERSION "(sg14)"

#define CASE( name ) lest_CASE( specification(), name )

extern lest::tests & specification();

namespace sg14 {

template< typename T, class Popper>
inline std::ostream & operator<<( std::ostream & os, ::sg14::ring_span<T, Popper> const & rs )
{
    os << "[ring_span: "; std::copy( rs.begin(), rs.end(), std::ostream_iterator<T>(os, ", ") ); return os << "]";
}

template< class RS, bool is_const >
inline std::ostream & operator<<( std::ostream & os, ::sg14::ring_iterator<RS, is_const> const & it )
{
    return os << "[ring_iterator: ?]";
}

}

namespace lest {

using ::sg14::operator<<;

} // namespace lest

// Provide the following to enable compilation:

#define ring_span_lite_MAJOR     0
#define ring_span_lite_MINOR     0
#define ring_span_lite_PATCH     0
#define nsrs_HAVE_STD_RING_SPAN  0
#define nsrs_USES_STD_RING_SPAN  0
#define nsrs_RING_SPAN_DEFAULT   0
#define nsrs_RING_SPAN_NONSTD    0
#define nsrs_RING_SPAN_STD       0
#define nsrs_CONFIG_SELECT_RING_SPAN 0
#define nsrs_CPLUSPLUS             __cplusplus
#define nsrs_COMPILER_CLANG_VERSION  0
#define nsrs_COMPILER_GNUC_VERSION   0
#define nsrs_HAVE_CONSTEXPR_11       0
#define nsrs_HAVE_CONSTEXPR_14       0
#define nsrs_HAVE_IS_DEFAULT         0
#define nsrs_HAVE_IS_DELETE          0
#define nsrs_HAVE_NOEXCEPT           0
#define nsrs_HAVE_NULLPTR            0

namespace nonstd{}

#endif // ring_span_lite_T_INCLUDED

// end of file
