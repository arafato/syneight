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
 * @version $Id: throw.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__THROW_HPP
#define SYNEIGHT__ANNOTATION__BASE__THROW_HPP

#include <syneight/base/annotation/config.hpp>
#include <syneight/base/diagnostics/facility.hpp>

#include <syneight/base/util/string.hpp>

////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__INTERNAL__SWITCH__HANDLE_TEST_EXCEPTION_EXPLICITLY == 1
#  define SYNEIGHT__INTERNAL__THROW_HANDLE_TEST_EXCEP \
    catch(SYNEIGHT__INTERNAL__PARAM__TYPE_EXCEPTION_TYPE & e) { \
	missing_exception=false; \
	::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
						     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
						     ::syneight::diagnostics:: WRONG_EXCEPTION_TYPE, \
						     ::std::string(SYNEIGHT__INTERNAL__PARAM__TYPE_EXCEPTION_WHAT(e)) \
						     + " thrown at "  \
						     + ::syneight::baseutil::to_string( \
                                                       SYNEIGHT__INTERNAL__PARAM__TYPE_EXCEPTION_SOURCE_LOCATION(e)) \
						     + " is not of type " #TYPE, \
                                                     SYNEIGHT__PARAM__STD_NR_WHAT, \
						     SYNEIGHT__BASE_FILE, \
						     __FILE__, \
						     __LINE__); \
    }
#else
#  define SYNEIGHT__INTERNAL__THROW_HANDLE_TEST_EXCEP
#endif




#define SYNEIGHT__INTERNAL__THROW1(LEVEL,STATEMENT,TYPE,PRED) \
do { \
    bool missing_exception(true); \
    try { \
	STATEMENT; \
    } \
    catch(TYPE & e){ \
	missing_exception=false; \
	if(! (PRED)) { \
	    ::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
							 ::syneight::diagnostics:: LEVEL ## _LEVEL, \
							 ::syneight::diagnostics:: WRONG_EXCEPTION_TYPE, \
							 ::std::string(SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT(e)) \
							 + " thrown at "  \
							 + ::syneight::baseutil::to_string( \
                                                           SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION(e)) \
							 + " does not satisfy " #PRED, \
						         SYNEIGHT__PARAM__STD_NR_WHAT, \
							 SYNEIGHT__BASE_FILE, \
							 __FILE__, \
							 __LINE__); \
	} \
    } \
    catch(SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_TYPE & e) { \
	missing_exception=false; \
	::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
						     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
						     ::syneight::diagnostics:: WRONG_EXCEPTION_TYPE, \
						     ::std::string(SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT(e)) \
						     + " thrown at "  \
						     + ::syneight::baseutil::to_string( \
                                                       SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION(e)) \
						     + " is not of type " #TYPE, \
						     SYNEIGHT__PARAM__STD_NR_WHAT, \
						     SYNEIGHT__BASE_FILE, \
						     __FILE__, \
						     __LINE__); \
    } \
    SYNEIGHT__INTERNAL__THROW_HANDLE_TEST_EXCEP \
    if(missing_exception) \
	::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
						     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
						     ::syneight::diagnostics:: MISSING_EXCEPTION_TYPE, \
						     "Expected exception of type " #TYPE " satisfying " #TYPE, \
						     SYNEIGHT__PARAM__STD_NR_WHAT, \
						     SYNEIGHT__BASE_FILE, \
						     __FILE__, \
						     __LINE__); \
} while(false)
 


////////////////////////////////////////////////////////////////////////////////
//
// Derived Macros
//
////////////////////////////////////////////////////////////////////////////////


#define SYNEIGHT__INTERNAL__THROW(LEVEL,STATEMENT,TYPE) SYNEIGHT__INTERNAL__THROW1(LEVEL,STATEMENT,TYPE,true)

#endif
// vim:ts=4:sw=4
