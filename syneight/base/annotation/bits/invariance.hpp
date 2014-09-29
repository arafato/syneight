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
 * @version $Id: invariance.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__INVARIANCE_HPP
#define SYNEIGHT__ANNOTATION__BITS__INVARIANCE_HPP

#include <syneight/base/annotation/base/invariance.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__INVARIANCE_ENTER              SYNEIGHT__INTERNAL__INVARIANCE_ENTER(AUD)
#  define SYNEIGHT__AUD__INVARIANCE_EXIT               SYNEIGHT__INTERNAL__INVARIANCE_EXIT
#  define SYNEIGHT__AUD__INVARIANCE_GUARD              SYNEIGHT__INTERNAL__INVARIANCE_GUARD(AUD)
#  define SYNEIGHT__AUD__INVARIANCE_ASSERT             SYNEIGHT__INTERNAL__INVARIANCE_ASSERT(AUD)

#else 

#  define SYNEIGHT__AUD__INVARIANCE_ENTER              do { ((void)0)
#  define SYNEIGHT__AUD__INVARIANCE_EXIT               } while(false)
#  define SYNEIGHT__AUD__INVARIANCE_GUARD              ((void)0)
#  define SYNEIGHT__AUD__INVARIANCE_ASSERT             ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__INVARIANCE_ENTER              SYNEIGHT__INTERNAL__INVARIANCE_ENTER(DEB)
#  define SYNEIGHT__DEB__INVARIANCE_EXIT               SYNEIGHT__INTERNAL__INVARIANCE_EXIT
#  define SYNEIGHT__DEB__INVARIANCE_GUARD              SYNEIGHT__INTERNAL__INVARIANCE_GUARD(DEB)
#  define SYNEIGHT__DEB__INVARIANCE_ASSERT             SYNEIGHT__INTERNAL__INVARIANCE_ASSERT(DEB)

#else 

#  define SYNEIGHT__DEB__INVARIANCE_ENTER              do { ((void)0)
#  define SYNEIGHT__DEB__INVARIANCE_EXIT               } while(false)
#  define SYNEIGHT__DEB__INVARIANCE_GUARD              ((void)0)
#  define SYNEIGHT__DEB__INVARIANCE_ASSERT             ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__INVARIANCE_ENTER              SYNEIGHT__INTERNAL__INVARIANCE_ENTER(PRO)
#  define SYNEIGHT__PRO__INVARIANCE_EXIT               SYNEIGHT__INTERNAL__INVARIANCE_EXIT
#  define SYNEIGHT__PRO__INVARIANCE_GUARD              SYNEIGHT__INTERNAL__INVARIANCE_GUARD(PRO)
#  define SYNEIGHT__PRO__INVARIANCE_ASSERT             SYNEIGHT__INTERNAL__INVARIANCE_ASSERT(PRO)

#else 

#  define SYNEIGHT__PRO__INVARIANCE_ENTER              do { ((void)0)
#  define SYNEIGHT__PRO__INVARIANCE_EXIT               } while(false)
#  define SYNEIGHT__PRO__INVARIANCE_GUARD              ((void)0)
#  define SYNEIGHT__PRO__INVARIANCE_ASSERT             ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__INVARIANCE_ENTER              SYNEIGHT__INTERNAL__INVARIANCE_ENTER(TES)
#  define SYNEIGHT__TES__INVARIANCE_EXIT               SYNEIGHT__INTERNAL__INVARIANCE_EXIT
#  define SYNEIGHT__TES__INVARIANCE_GUARD              SYNEIGHT__INTERNAL__INVARIANCE_GUARD(TES)
#  define SYNEIGHT__TES__INVARIANCE_ASSERT             SYNEIGHT__INTERNAL__INVARIANCE_ASSERT(TES)

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__INVARIANCE_ENTER              do { ((void)0)
#  define SYNEIGHT__TES__INVARIANCE_EXIT               } while(false)
#  define SYNEIGHT__TES__INVARIANCE_GUARD              ((void)0)
#  define SYNEIGHT__TES__INVARIANCE_ASSERT             ((void)0)

#endif

#endif
// vim:ts=4:sw=4
