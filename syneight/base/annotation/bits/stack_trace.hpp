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

#ifndef SYNEIGHT__ANNOTATION__BITS__STACK_TRACE_HPP
#define SYNEIGHT__ANNOTATION__BITS__STACK_TRACE_HPP

#include <syneight/base/annotation/base/stack_trace.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
#  define SYNEIGHT__AUD__LOG_STACK_TRACE             SYNEIGHT__INTERNAL__LOG_STACK_TRACE(AUD)
#  define SYNEIGHT__AUD__LOG_TRACE1(CATEGORY)        SYNEIGHT__INTERNAL__LOG_STACK_TRACE1(AUD,(CATEGORY))
#else 
#  define SYNEIGHT__AUD__LOG_STACK_TRACE             ((void)0)
#  define SYNEIGHT__AUD__LOG_STACK_TRACE1(CATEGORY)  ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0
#  define SYNEIGHT__DEB__LOG_STACK_TRACE             SYNEIGHT__INTERNAL__LOG_STACK_TRACE(DEB)
#  define SYNEIGHT__DEB__LOG_TRACE1(CATEGORY)        SYNEIGHT__INTERNAL__LOG_STACK_TRACE1(DEB,(CATEGORY))
#else 
#  define SYNEIGHT__DEB__LOG_STACK_TRACE             ((void)0)
#  define SYNEIGHT__DEB__LOG_STACK_TRACE1(CATEGORY)  ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1
#  define SYNEIGHT__PRO__LOG_STACK_TRACE             SYNEIGHT__INTERNAL__LOG_STACK_TRACE(PRO)
#  define SYNEIGHT__PRO__LOG_TRACE1(CATEGORY)        SYNEIGHT__INTERNAL__LOG_STACK_TRACE1(PRO,(CATEGORY))
#else 
#  define SYNEIGHT__PRO__LOG_STACK_TRACE             ((void)0)
#  define SYNEIGHT__PRO__LOG_STACK_TRACE1(CATEGORY)  ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1
#  define SYNEIGHT__TES__LOG_STACK_TRACE             SYNEIGHT__INTERNAL__LOG_STACK_TRACE(TES)
#  define SYNEIGHT__TES__LOG_TRACE1(CATEGORY)        SYNEIGHT__INTERNAL__LOG_STACK_TRACE1(TES,(CATEGORY))
#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0
#  define SYNEIGHT__TES__LOG_STACK_TRACE             ((void)0)
#  define SYNEIGHT__TES__LOG_STACK_TRACE1(CATEGORY)  ((void)0)
#endif

#endif
// vim:ts=4:sw=4
