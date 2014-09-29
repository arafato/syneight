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
 * @version $Id: nothrow.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__NOTHROW_HPP
#define SYNEIGHT__ANNOTATION__BITS__NOTHROW_HPP

#include <syneight/base/annotation/base/nothrow.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__NOTHROW_ENTER             SYNEIGHT__INTERNAL__NOTHROW_ENTER
#  define SYNEIGHT__AUD__NOTHROW_EXIT              SYNEIGHT__INTERNAL__NOTHROW_EXIT(AUD,1)
#  define SYNEIGHT__AUD__NOTHROW_EXIT_DROP         SYNEIGHT__INTERNAL__NOTHROW_EXIT(AUD,0)

#else 

#  define SYNEIGHT__AUD__NOTHROW_ENTER             do { ((void)0)
#  define SYNEIGHT__AUD__NOTHROW_EXIT              } while(false)
#  define SYNEIGHT__AUD__NOTHROW_EXIT_DROP         } while(false)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__NOTHROW_ENTER             SYNEIGHT__INTERNAL__NOTHROW_ENTER
#  define SYNEIGHT__DEB__NOTHROW_EXIT              SYNEIGHT__INTERNAL__NOTHROW_EXIT(DEB,1)
#  define SYNEIGHT__DEB__NOTHROW_EXIT_DROP         SYNEIGHT__INTERNAL__NOTHROW_EXIT(DEB,0)

#else 

#  define SYNEIGHT__DEB__NOTHROW_ENTER             do { ((void)0)
#  define SYNEIGHT__DEB__NOTHROW_EXIT              } while(false)
#  define SYNEIGHT__DEB__NOTHROW_EXIT_DROP         } while(false)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__NOTHROW_ENTER             SYNEIGHT__INTERNAL__NOTHROW_ENTER
#  define SYNEIGHT__PRO__NOTHROW_EXIT              SYNEIGHT__INTERNAL__NOTHROW_EXIT(PRO,1)
#  define SYNEIGHT__PRO__NOTHROW_EXIT_DROP         SYNEIGHT__INTERNAL__NOTHROW_EXIT(PRO,0)

#else 

#  define SYNEIGHT__PRO__NOTHROW_ENTER             do { ((void)0)
#  define SYNEIGHT__PRO__NOTHROW_EXIT              } while(false)
#  define SYNEIGHT__PRO__NOTHROW_EXIT_DROP         } while(false)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__NOTHROW_ENTER             SYNEIGHT__INTERNAL__NOTHROW_ENTER
#  define SYNEIGHT__TES__NOTHROW_EXIT              SYNEIGHT__INTERNAL__NOTHROW_EXIT(TES,1)
#  define SYNEIGHT__TES__NOTHROW_EXIT_DROP         SYNEIGHT__INTERNAL__NOTHROW_EXIT(TES,0)

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__NOTHROW_ENTER             do { ((void)0)
#  define SYNEIGHT__TES__NOTHROW_EXIT              } while(false)
#  define SYNEIGHT__TES__NOTHROW_EXIT_DROP         } while(false)

#endif

#endif
// vim:ts=4:sw=4
