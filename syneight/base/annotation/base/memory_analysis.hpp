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
 * @version $Id: memory_analysis.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__MEMORY_ANALYSIS_HPP
#define SYNEIGHT__ANNOTATION__BASE__MEMORY_ANALYSIS_HPP

#include <syneight/base/annotation/config.hpp>
#include <syneight/base/memory_monitoring/guard.hpp>

////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////


#define  SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_GUARD1(LEVEL,LOGGING,BALANCE,CATEGORY) \
  ::syneight::memory_monitoring::Guard \
  syneight_reserved_name_internal_memory_analysis_guard(LOGGING,BALANCE, \
                                                       ::syneight::diagnostics:: LEVEL ## _LEVEL, \
                                                       SYNEIGHT__BASE_FILE, __FILE__, __LINE__, \
                                                       CATEGORY)
 
#define  SYNEIGHT__INTERNAL__ASSERT_MEMORY_BALANCE1(LEVEL,CATEGORY) \
  ::syneight::memory_monitoring::Guard::assert_balance(::syneight::diagnostics:: LEVEL ## LEVEL, \
						      SYNEIGHT__BASE_FILE, \
						      __FILE__, \
						      __LINE__, \
						      CATEGORY)


#define  SYNEIGHT__INTERNAL__LOG_MEMORY_BALANCE1(LEVEL,CATEGORY) \
  ::syneight::memory_monitoring::Guard::log_balance(::syneight::diagnostics:: LEVEL ## LEVEL, \
						   SYNEIGHT__BASE_FILE, \
						   __FILE__, \
						   __LINE__, \
						   CATEGORY)



////////////////////////////////////////////////////////////////////////////////
//
// Derived Macros
//
////////////////////////////////////////////////////////////////////////////////


#define  SYNEIGHT__INTERNAL__ASSERT_MEMORY_BALANCE(LEVEL) \
  SYNEIGHT__INTERNAL__ASSERT_MEMORY_BALANCE1(LEVEL,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY) 

#define  SYNEIGHT__INTERNAL__LOG_MEMORY_BALANCE(LEVEL) \
  SYNEIGHT__INTERNAL__LOG_MEMORY_BALANCE1(LEVEL,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY) 


#define SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_ENTER(LEVEL,LOGGING,BALANCE) \
  SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_ENTER1(LEVEL,LOGGING,BALANCE,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY)

#define SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_GUARD(LEVEL,LOGGING,BALANCE) \
  SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_GUARD1(LEVEL,LOGGING,BALANCE,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY)

#define SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_ENTER1(LEVEL,LOGGING,BALANCE,CATEGORY)  \
   do { SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_GUARD1(LEVEL,LOGGING,BALANCE,CATEGORY); { (void)0)

#define SYNEIGHT__INTERNAL__MEMORY_ANALYSIS_EXIT }} while(false) 

#endif
// vim:ts=4:sw=4
