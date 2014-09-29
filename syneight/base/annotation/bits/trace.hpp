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

#ifndef SYNEIGHT__ANNOTATION__BITS__TRACE_HPP
#define SYNEIGHT__ANNOTATION__BITS__TRACE_HPP

#include <syneight/base/annotation/base/trace.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
#  define SYNEIGHT__AUD__TRACE(WHAT)                 SYNEIGHT__INTERNAL__TRACE(TRACE,AUD,(WHAT))
#  define SYNEIGHT__AUD__TRACE1(WHAT,CATEGORY)       SYNEIGHT__INTERNAL__TRACE1(TRACE,AUD,(WHAT),(CATEGORY))
#  define SYNEIGHT__AUD__TRACE_NR(WHAT,NR)           SYNEIGHT__INTERNAL__TRACE_NR(TRACE,AUD,(WHAT),(NR))
#  define SYNEIGHT__AUD__TRACE_NR1(WHAT,NR,CATEGORY) SYNEIGHT__INTERNAL__TRACE_NR1(TRACE,AUD,(WHAT),(NR),(CATEGORY))
#else 
#  define SYNEIGHT__AUD__TRACE(WHAT)                 ((void)0)
#  define SYNEIGHT__AUD__TRACE1(WHAT,CATEGORY)       ((void)0)
#  define SYNEIGHT__AUD__TRACE_NR(WHAT,NR)           ((void)0)
#  define SYNEIGHT__AUD__TRACE_NR1(WHAT,NR,CATEGORY) ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0
#  define SYNEIGHT__DEB__TRACE(WHAT)                 SYNEIGHT__INTERNAL__TRACE(TRACE,DEB,(WHAT))
#  define SYNEIGHT__DEB__TRACE1(WHAT,CATEGORY)       SYNEIGHT__INTERNAL__TRACE1(TRACE,DEB,(WHAT),(CATEGORY))
#  define SYNEIGHT__DEB__TRACE_NR(WHAT,NR)           SYNEIGHT__INTERNAL__TRACE_NR(TRACE,DEB,(WHAT),(NR))
#  define SYNEIGHT__DEB__TRACE_NR1(WHAT,NR,CATEGORY) SYNEIGHT__INTERNAL__TRACE_NR1(TRACE,DEB,(WHAT),(NR),(CATEGORY))
#else 
#  define SYNEIGHT__DEB__TRACE(WHAT)                 ((void)0)
#  define SYNEIGHT__DEB__TRACE1(WHAT,CATEGORY)       ((void)0)
#  define SYNEIGHT__DEB__TRACE_NR(WHAT,NR)           ((void)0)
#  define SYNEIGHT__DEB__TRACE_NR1(WHAT,NR,CATEGORY) ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__TRACE(WHAT)                 SYNEIGHT__INTERNAL__TRACE(TRACE,PRO,(WHAT))
#  define SYNEIGHT__EME__TRACE(WHAT)                 SYNEIGHT__INTERNAL__TRACE(TRACE,EME,(WHAT))
#  define SYNEIGHT__ALE__TRACE(WHAT)                 SYNEIGHT__INTERNAL__TRACE(TRACE,ALE,(WHAT))

#  define SYNEIGHT__PRO__TRACE1(WHAT,CATEGORY)       SYNEIGHT__INTERNAL__TRACE1(TRACE,PRO,(WHAT),(CATEGORY))
#  define SYNEIGHT__ALE__TRACE1(WHAT,CATEGORY)       SYNEIGHT__INTERNAL__TRACE1(TRACE,ALE,(WHAT),(CATEGORY))
#  define SYNEIGHT__EME__TRACE1(WHAT,CATEGORY)       SYNEIGHT__INTERNAL__TRACE1(TRACE,EME,(WHAT),(CATEGORY))

#  define SYNEIGHT__PRO__TRACE_NR(WHAT,NR)           SYNEIGHT__INTERNAL__TRACE_NR(TRACE,PRO,(WHAT),(NR))
#  define SYNEIGHT__EME__TRACE_NR(WHAT,NR)           SYNEIGHT__INTERNAL__TRACE_NR(TRACE,EME,(WHAT),(NR))
#  define SYNEIGHT__ALE__TRACE_NR(WHAT,NR)           SYNEIGHT__INTERNAL__TRACE_NR(TRACE,ALE,(WHAT),(NR))

#  define SYNEIGHT__PRO__TRACE_NR1(WHAT,NR,CATEGORY) SYNEIGHT__INTERNAL__TRACE_NR1(TRACE,PRO,(WHAT),(NR),(CATEGORY))
#  define SYNEIGHT__ALE__TRACE_NR1(WHAT,NR,CATEGORY) SYNEIGHT__INTERNAL__TRACE_NR1(TRACE,ALE,(WHAT),(NR),(CATEGORY))
#  define SYNEIGHT__EME__TRACE_NR1(WHAT,NR,CATEGORY) SYNEIGHT__INTERNAL__TRACE_NR1(TRACE,EME,(WHAT),(NR),(CATEGORY))

#else 

#  define SYNEIGHT__PRO__TRACE(WHAT)              ((void)0)
#  define SYNEIGHT__ALE__TRACE(WHAT)              ((void)0)
#  define SYNEIGHT__EME__TRACE(WHAT)              ((void)0)

#  define SYNEIGHT__PRO__TRACE1(WHAT,CATEGORY)    ((void)0)
#  define SYNEIGHT__ALE__TRACE1(WHAT,CATEGORY)    ((void)0)
#  define SYNEIGHT__EME__TRACE1(WHAT,CATEGORY)    ((void)0)

#  define SYNEIGHT__PRO__TRACE_NR(WHAT,NR)           ((void)0)
#  define SYNEIGHT__EME__TRACE_NR(WHAT,NR)           ((void)0)
#  define SYNEIGHT__ALE__TRACE_NR(WHAT,NR)           ((void)0)

#  define SYNEIGHT__PRO__TRACE_NR1(WHAT,NR,CATEGORY) ((void)0)
#  define SYNEIGHT__ALE__TRACE_NR1(WHAT,NR,CATEGORY) ((void)0)
#  define SYNEIGHT__EME__TRACE_NR1(WHAT,NR,CATEGORY) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1
#  define SYNEIGHT__TES__TRACE(WHAT)                 SYNEIGHT__INTERNAL__TRACE(TRACE,TES,(WHAT))
#  define SYNEIGHT__TES__TRACE1(WHAT,CATEGORY)       SYNEIGHT__INTERNAL__TRACE1(TRACE,TES,(WHAT),(CATEGORY))
#  define SYNEIGHT__TES__TRACE_NR(WHAT,NR)           SYNEIGHT__INTERNAL__TRACE_NR(TRACE,TES,(WHAT),(NR))
#  define SYNEIGHT__TES__TRACE_NR1(WHAT,NR,CATEGORY) SYNEIGHT__INTERNAL__TRACE_NR1(TRACE,TES,(WHAT),(NR),(CATEGORY))
#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0
#  define SYNEIGHT__TES__TRACE(WHAT)                 ((void)0)
#  define SYNEIGHT__TES__TRACE1(WHAT,CATEGORY)       ((void)0)
#  define SYNEIGHT__TES__TRACE_NR(WHAT,NR)           ((void)0)
#  define SYNEIGHT__TES__TRACE_NR1(WHAT,NR,CATEGORY) ((void)0)
#endif

#endif
// vim:ts=4:sw=4
