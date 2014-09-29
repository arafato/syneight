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
 * @version $Id: condition.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__CONDITION_HPP
#define SYNEIGHT__ANNOTATION__BASE__CONDITION_HPP

#include <syneight/base/annotation/config.hpp>
#include <syneight/base/diagnostics/facility.hpp>


#define SYNEIGHT__INTERNAL__LOG_EXCEPTION(LEVEL,TYPE,EXCEP) \
   ::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
						 LEVEL, \
						 TYPE , \
						 SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT(EXCEP), \
                                                 SYNEIGHT__PARAM__STD_NR_WHAT, \
						 SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION(EXCEP)); 

#define SYNEIGHT__INTERNAL__CONDITION(TYPE,LEVEL,NAME,COND) \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION0(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
	throw excep; \
    } \
   } while(false)


#define SYNEIGHT__INTERNAL__CONDITION1(TYPE,LEVEL,NAME,COND,W1)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION1(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
	throw excep; \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION2(TYPE,LEVEL,NAME,COND,W1,W2)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION2(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
	throw excep; \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION3(TYPE,LEVEL,NAME,COND,W1,W2,W3)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION3(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2,W3); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
	throw excep; \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION4(TYPE,LEVEL,NAME,COND,W1,W2,W3,W4)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION4(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2,W3,W4); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
        throw excep; \
    } \
   } while(false)


////////////////////////////////////////////////////////////////////////////////

#define SYNEIGHT__INTERNAL__CONDITION_LOG(TYPE,LEVEL,NAME,COND) \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION0(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
    } \
   } while(false)


#define SYNEIGHT__INTERNAL__CONDITION_LOG1(TYPE,LEVEL,NAME,COND,W1)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION1(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION_LOG2(TYPE,LEVEL,NAME,COND,W1,W2)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION2(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION_LOG3(TYPE,LEVEL,NAME,COND,W1,W2,W3)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION3(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2,W3); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION_LOG4(TYPE,LEVEL,NAME,COND,W1,W2,W3,W4)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION4(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2,W3,W4); \
	SYNEIGHT__INTERNAL__LOG_EXCEPTION(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                         ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                         excep); \
    } \
   } while(false)



////////////////////////////////////////////////////////////////////////////////

#define SYNEIGHT__INTERNAL__CONDITION_THROW(TYPE,LEVEL,NAME,COND) \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION0(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND); \
        throw excep; \
    } \
   } while(false)


#define SYNEIGHT__INTERNAL__CONDITION_THROW1(TYPE,LEVEL,NAME,COND,W1)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION1(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1); \
        throw excep; \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION_THROW2(TYPE,LEVEL,NAME,COND,W1,W2)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION2(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2); \
        throw excep; \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION_THROW3(TYPE,LEVEL,NAME,COND,W1,W2,W3)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION3(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2,W3); \
        throw excep; \
    } \
   } while(false)

#define SYNEIGHT__INTERNAL__CONDITION_THROW4(TYPE,LEVEL,NAME,COND,W1,W2,W3,W4)  \
   do { \
    if(!(COND)) { \
	SYNEIGHT__INTERNAL__PARAM__EXCEPTION4(::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                             ::syneight::diagnostics:: FAILED_ ## TYPE ## _TYPE, \
                                             NAME,COND,W1,W2,W3,W4); \
        throw excep; \
    } \
   } while(false)



#endif
// vim:ts=4:sw=4
