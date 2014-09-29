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
 * @version $Id: unexpected_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__UNEXPECTED_EXCEPTION_HPP
#define SYNEIGHT__ANNOTATION__BASE__UNEXPECTED_EXCEPTION_HPP

#include <syneight/base/annotation/config.hpp>
#include <syneight/base/diagnostics/facility.hpp>

////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////

#define SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_RETHROW(RETHROW) \
  SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_RETHROW ## RETHROW

#define SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_RETHROW0 ((void)0)
#define SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_RETHROW1 throw

#if SYNEIGHT__INTERNAL__SWITCH__HANDLE_TEST_EXCEPTION_EXPLICITLY == 1
#  define SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_HANDLE_TEST_EXCEP(LEVEL,RETHROW) \
      catch(SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_TYPE & e) { \
   	::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
   						     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
   						     ::syneight::diagnostics:: UNEXPECTED_EXCEPTION_TYPE, \
   						     ::std::string(SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_WHAT(e)) \
   						     + " thrown at "  \
   						     + ::syneight::baseutil::to_string( \
                                                       SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_SOURCE_LOCATION(e)), \
                                                     SYNEIGHT__PARAM__STD_NR_WHAT, \
   						     SYNEIGHT__BASE_FILE, \
   						     __FILE__, \
   						     __LINE__); \
   	SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_RETHROW(RETHROW); \
      }
#else
#  define SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_HANDLE_TEST_EXCEP(LEVEL,RETHROW)
#endif



#define SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(LEVEL,RETHROW) \
    catch(SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_TYPE & e) { \
	::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
						     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
						     ::syneight::diagnostics:: UNEXPECTED_EXCEPTION_TYPE, \
						     ::std::string(SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT(e)) \
						     + " thrown at "  \
						     + ::syneight::baseutil::to_string( \
                                                       SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION(e)), \
                                                     SYNEIGHT__PARAM__STD_NR_WHAT, \
						     SYNEIGHT__BASE_FILE, \
						     __FILE__, \
						     __LINE__); \
	SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_RETHROW(RETHROW); \
    } \
    SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_HANDLE_TEST_EXCEP(LEVEL,RETHROW) \
    catch(...) { \
	::syneight::diagnostics::Facility::log(SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY, \
						     ::syneight::diagnostics:: LEVEL ## _LEVEL, \
						     ::syneight::diagnostics:: UNEXPECTED_EXCEPTION_TYPE, \
						     "Unknown Exception Type", \
                                                     SYNEIGHT__PARAM__STD_NR_WHAT, \
						     SYNEIGHT__BASE_FILE, \
						     __FILE__, \
						     __LINE__); \
	SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION_RETHROW(RETHROW); \
    } \
    ((void)0)

#endif
// vim:ts=4:sw=4
