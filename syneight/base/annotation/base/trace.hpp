/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file TODO
 *
 * @author TODO
 * @author $Author: esdentem $
 *
 * @version $Id: trace.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__TRACE_HPP
#define SYNEIGHT__ANNOTATION__BASE__TRACE_HPP

#include <syneight/base/annotation/config.hpp>
#include <syneight/base/diagnostics/facility.hpp>

////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////

#define SYNEIGHT__INTERNAL__TRACE1(TYPE,LEVEL,WHAT,CATEGORY) \
	::syneight::diagnostics::Facility::log \
	    (CATEGORY, \
	     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
	     ::syneight::diagnostics:: TYPE ## _TYPE, \
	     WHAT, \
             SYNEIGHT__PARAM__STD_NR_WHAT, \
	     SYNEIGHT__BASE_FILE, \
	     __FILE__, \
	     __LINE__);

#define SYNEIGHT__INTERNAL__TRACE_NR1(TYPE,LEVEL,WHAT,NR,CATEGORY) \
	::syneight::diagnostics::Facility::log \
	    (CATEGORY, \
	     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
	     ::syneight::diagnostics:: TYPE ## _TYPE, \
	     WHAT, \
             NR, \
	     SYNEIGHT__BASE_FILE, \
	     __FILE__, \
	     __LINE__);


////////////////////////////////////////////////////////////////////////////////
//
// Derived Macros
//
////////////////////////////////////////////////////////////////////////////////

#define SYNEIGHT__INTERNAL__TRACE(TYPE,LEVEL,WHAT) \
  SYNEIGHT__INTERNAL__TRACE1(TYPE,LEVEL,WHAT,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY)

#define SYNEIGHT__INTERNAL__TRACE_NR(TYPE,LEVEL,WHAT) \
  SYNEIGHT__INTERNAL__TRACE_NR1(TYPE,LEVEL,WHAT,NR,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY)


#endif
// vim:ts=4:sw=4
