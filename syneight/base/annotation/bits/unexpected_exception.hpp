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

#ifndef SYNEIGHT__ANNOTATION__BITS__UNEXPECTED_EXCEPTION_HPP
#define SYNEIGHT__ANNOTATION__BITS__UNEXPECTED_EXCEPTION_HPP

#include <syneight/base/annotation/base/unexpected_exception.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
#  define SYNEIGHT__AUD__UNEXPECTED_EXCEPTION       SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(AUD,1)
#  define SYNEIGHT__AUD__UNEXPECTED_EXCEPTION_DROP  SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(AUD,0)
#else 
#  define SYNEIGHT__AUD__UNEXPECTED_EXCEPTION       ((void)0)
#  define SYNEIGHT__AUD__UNEXPECTED_EXCEPTION_DROP  ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0
#  define SYNEIGHT__DEB__UNEXPECTED_EXCEPTION       SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(DEB,1)
#  define SYNEIGHT__DEB__UNEXPECTED_EXCEPTION_DROP  SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(DEB,0)
#else 
#  define SYNEIGHT__DEB__UNEXPECTED_EXCEPTION       ((void)0)
#  define SYNEIGHT__DEB__UNEXPECTED_EXCEPTION_DROP  ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1
#  define SYNEIGHT__PRO__UNEXPECTED_EXCEPTION       SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(PRO,1)
#  define SYNEIGHT__PRO__UNEXPECTED_EXCEPTION_DROP  SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(PRO,0)
#else 
#  define SYNEIGHT__PRO__UNEXPECTED_EXCEPTION       ((void)0)
#  define SYNEIGHT__PRO__UNEXPECTED_EXCEPTION_DROP  ((void)0)
#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1
#  define SYNEIGHT__TES__UNEXPECTED_EXCEPTION       SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(TES,1)
#  define SYNEIGHT__TES__UNEXPECTED_EXCEPTION_DROP  SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(TES,0)
#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0
#  define SYNEIGHT__TES__UNEXPECTED_EXCEPTION       ((void)0)
#  define SYNEIGHT__TES__UNEXPECTED_EXCEPTION_DROP  ((void)0)
#endif

#endif
// vim:ts=4:sw=4
