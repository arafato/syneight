/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/annotation/config.hpp
 *
 * @author TODO
 * @author $Author: esdentem $
 *
 * @version $Id: config.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__ANNOTATION__CONFIG_HPP
#define SYNEIGHT__BASE__ANNOTATION__CONFIG_HPP

#include <syneight/base/diagnostics/level.hpp>

////////////////////////////////////////////////////////////////////////////////
//
// Public Configuration
//
////////////////////////////////////////////////////////////////////////////////

#ifndef SYNEIGHT__SWITCH__BUILD_LEVEL
#  define SYNEIGHT__SWITCH__BUILD_LEVEL 2
#endif

#ifndef SYNEIGHT__BUILD_LEVEL
#  if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
#    define SYNEIGHT__BUILD_LEVEL ::syneight::diagnostics::AUD_LEVEL
#  elif SYNEIGHT__SWITCH__BUILD_LEVEL == 1
#    define SYNEIGHT__BUILD_LEVEL ::syneight::diagnostics::DEB_LEVEL
#  elif SYNEIGHT__SWITCH__BUILD_LEVEL == 0
#    define SYNEIGHT__BUILD_LEVEL ::syneight::diagnostics::PRO_LEVEL
#  elif SYNEIGHT__SWITCH__BUILD_LEVEL == -1
#    define SYNEIGHT__BUILD_LEVEL ::syneight::diagnostics::SYS_LEVEL
#  else
#    error Invalid value for SYNEIGHT__SWITCH__BUILD_LEVEL
#  endif
#else
#  error SYNEIGHT__BUILD_LEVEL already defined
#endif

#ifndef SYNEIGHT__SWITCH__TEST_ANNOTATIONS
#  define SYNEIGHT__SWITCH__TEST_ANNOTATIONS -1
#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS < -1 || SYNEIGHT__SWITCH__TEST_ANNOTATIONS > 1
#  error Invalid value for SYNEIGHT__SWITCH__TEST_ANNOTATIONS
#endif

#ifndef SYNEIGHT__SWITCH__LOG_PRO_CHECKS
#  if SYNEIGHT__SWITCH__BUILD_LEVEL > 1
#    define SYNEIGHT__SWITCH__LOG_PRO_CHECKS 1
#  else 
#    define SYNEIGHT__SWITCH__LOG_PRO_CHECKS 0
#  endif
#elif SYNEIGHT__SWITCH__LOG_PRO_CHECKS < 0 || SYNEIGHT__SWITCH__LOG_PRO_CHECKS > 1
#  error Invalid value for SYNEIGHT__SWITCH__LOG_PRO_CHECKS
#endif

#ifndef SYNEIGHT__PARAM__STD_NR_WHAT 
#  define SYNEIGHT__PARAM__STD_NR_WHAT 0
#endif

////////////////////////////////////////////////////////////////////////////////
//
// Mandatory Internal Configuration
//
////////////////////////////////////////////////////////////////////////////////


// Exception Base Type /////////////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_TYPE
#  error SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_TYPE undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT
#  error SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION
#  error SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION undefined
#endif


// Test Exception Type ///////////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_TYPE
#  error SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_TYPE undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_WHAT
#  error SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_WHAT undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_SOURCE_LOCATION
#  error SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_SOURCE_LOCATION undefined
#endif

// Specific Test Exception Types ////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_ERROR_EXCEPTION_TYPE
#  error SYNEIGHT__INTERNAL__PARAM__TEST_ERROR_EXCEPTION_TYPE undefined
#endif

// Test Exception Handling //////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__SWITCH__HANDLE_TEST_EXCEPTION_EXPLICITLY
#  error SYNEIGHT__INTERNAL__SWITCH__HANDLE_TEST_EXCEPTION_EXPLICITLY undefined
#endif

// Standard Logging Category ///////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY
#  error SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY undefined
#endif

// Memory Analysis /////////////////////////////////////////////////////////////

#ifndef SYNEIGHT__SWITCH__MEMORY_ANALYSIS
#  error SYNEIGHT__SWITCH__MEMORY_ANALYSIS undefined
#endif

// Exception Construction //////////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION0
#  error SYNEIGHT__INTERNAL__PARAM__EXCEPTION0 undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION1
#  error SYNEIGHT__INTERNAL__PARAM__EXCEPTION1 undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION2
#  error SYNEIGHT__INTERNAL__PARAM__EXCEPTION2 undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION3
#  error SYNEIGHT__INTERNAL__PARAM__EXCEPTION3 undefined
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION4
#  error SYNEIGHT__INTERNAL__PARAM__EXCEPTION4 undefined
#endif

////////////////////////////////////////////////////////////////////////////////
//
// Optional Internal Configuration
//
////////////////////////////////////////////////////////////////////////////////

     

#endif
// vim:ts=4:sw=4
