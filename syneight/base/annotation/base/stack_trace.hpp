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
 * @version $Id: stack_trace.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__STACK_TRACE_HPP
#define SYNEIGHT__ANNOTATION__BASE__STACK_TRACE_HPP

#include <syneight/base/annotation/config.hpp>
#include <syneight/base/diagnostics/block_guard.hpp>


////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////


#define  SYNEIGHT__INTERNAL__LOG_STACK_TRACE1(LEVEL,CATEGORY) \
  ::syneight::diagnostics::Block_Guard::log_stack_trace(::syneight::diagnostics:: LEVEL ## _LEVEL,\
						       SYNEIGHT__BASE_FILE,\
						       __FILE__, \
						       __LINE__, \
						       CATEGORY)

////////////////////////////////////////////////////////////////////////////////
//
// Derived Macros
//
////////////////////////////////////////////////////////////////////////////////


#define SYNEIGHT__INTERNAL__LOG_STACK_TRACE(LEVEL) \
  SYNEIGHT__INTERNAL__LOG_STACK_TRACE1(LEVEL,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY)


#endif
// vim:ts=4:sw=4
