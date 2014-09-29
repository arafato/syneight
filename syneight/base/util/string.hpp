/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/util/string.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: string.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::baseutil::to_string,
 * @ref ::syneight::baseutil::from_string.
 *
 * TODO: Long description.
 *
 * @note HALFWAY DOCUMENTED
 *
 * @todo Add test / fix documentation.
 */

#ifndef SYNEIGHT__BASE__UTIL__STRING_HPP
#define SYNEIGHT__BASE__UTIL__STRING_HPP

#include <syneight/base/util/namespace.hpp>

#include <syneight/base/preprocessor/arith.hpp>
#include <syneight/base/preprocessor/emit_parameter.hpp>
#include <syneight/base/preprocessor/for.hpp>

#include <iostream>
#include <string>
#include <sstream>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__BASEUTIL;

#define SYNEIGHT__INTERNAL__EMIT__TO_STRING(COUNT) \
template< SYNEIGHT__BASE__EMIT__PARAMETER(typename T,COUNT) > \
::std::string to_string( SYNEIGHT__BASE__EMIT__PARAMETER2(T,COUNT,const & t)) \
{ \
    ::std::ostringstream os; \
     os SYNEIGHT__BASE__EMIT__PARAMETER_USE(<< t, SYNEIGHT__BASE__DEC(COUNT) , << ' ') << t ## COUNT; \
    return os.str(); \
}
SYNEIGHT__BASE__FOR_0_TO(SYNEIGHT__INTERNAL__EMIT__TO_STRING,SYNEIGHT__BASE__FOR_0_TO_MAX);
#undef SYNEIGHT__INTERNAL__EMIT__TO_STRING


#define SYNEIGHT__INTERNAL__EMIT__FROM_STRING(COUNT) \
template< SYNEIGHT__BASE__EMIT__PARAMETER(typename T,COUNT) > \
void from_string(::std::string const & str, SYNEIGHT__BASE__EMIT__PARAMETER2(T,COUNT, & t)) \
{ \
    ::std::istringstream is(str); \
     is SYNEIGHT__BASE__EMIT__PARAMETER_USE(>> t, COUNT ,) ; \
}
SYNEIGHT__BASE__FOR_0_TO(SYNEIGHT__INTERNAL__EMIT__FROM_STRING,SYNEIGHT__BASE__FOR_0_TO_MAX);
#undef SYNEIGHT__INTERNAL__EMIT__FROM_STRING


SYNEIGHT__END__NAMESPACE__BASEUTIL;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
