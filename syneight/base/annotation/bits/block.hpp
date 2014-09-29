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
 * @version $Id: block.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__BLOCK_HPP
#define SYNEIGHT__ANNOTATION__BITS__BLOCK_HPP

#include <syneight/base/annotation/base/block.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__BLOCK_ENTER(WHAT)              SYNEIGHT__INTERNAL__BLOCK_ENTER(BLOCK,AUD,(WHAT))
#  define SYNEIGHT__AUD__BLOCK_ENTER1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_ENTER1(BLOCK,AUD,(WHAT),(CATEGORY))
#  define SYNEIGHT__AUD__BLOCK_EXIT                     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__AUD__BLOCK_GUARD(WHAT)              SYNEIGHT__INTERNAL__BLOCK_GUARD(BLOCK,AUD,(WHAT))
#  define SYNEIGHT__AUD__BLOCK_GUARD1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_GUARD1(BLOCK,AUD,(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__AUD__BLOCK_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__AUD__BLOCK_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__AUD__BLOCK_EXIT                     } while(false)
#  define SYNEIGHT__AUD__BLOCK_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__AUD__BLOCK_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__BLOCK_ENTER(WHAT)              SYNEIGHT__INTERNAL__BLOCK_ENTER(BLOCK,DEB,(WHAT))
#  define SYNEIGHT__DEB__BLOCK_ENTER1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_ENTER1(BLOCK,DEB,(WHAT),(CATEGORY))
#  define SYNEIGHT__DEB__BLOCK_EXIT                     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__DEB__BLOCK_GUARD(WHAT)              SYNEIGHT__INTERNAL__BLOCK_GUARD(BLOCK,DEB,(WHAT))
#  define SYNEIGHT__DEB__BLOCK_GUARD1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_GUARD1(BLOCK,DEB,(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__DEB__BLOCK_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__DEB__BLOCK_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__DEB__BLOCK_EXIT                     } while(false)
#  define SYNEIGHT__DEB__BLOCK_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__DEB__BLOCK_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__BLOCK_ENTER(WHAT)              SYNEIGHT__INTERNAL__BLOCK_ENTER(BLOCK,PRO,(WHAT))
#  define SYNEIGHT__PRO__BLOCK_ENTER1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_ENTER1(BLOCK,PRO,(WHAT),(CATEGORY))
#  define SYNEIGHT__PRO__BLOCK_EXIT                     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__PRO__BLOCK_GUARD(WHAT)              SYNEIGHT__INTERNAL__BLOCK_GUARD(BLOCK,PRO,(WHAT))
#  define SYNEIGHT__PRO__BLOCK_GUARD1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_GUARD1(BLOCK,PRO,(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__PRO__BLOCK_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__PRO__BLOCK_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__PRO__BLOCK_EXIT                     } while(false)
#  define SYNEIGHT__PRO__BLOCK_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__PRO__BLOCK_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__BLOCK_ENTER(WHAT)              SYNEIGHT__INTERNAL__BLOCK_ENTER(BLOCK,TES,(WHAT))
#  define SYNEIGHT__TES__BLOCK_ENTER1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_ENTER1(BLOCK,TES,(WHAT),(CATEGORY))
#  define SYNEIGHT__TES__BLOCK_EXIT                     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__TES__BLOCK_GUARD(WHAT)              SYNEIGHT__INTERNAL__BLOCK_GUARD(BLOCK,TES,(WHAT))
#  define SYNEIGHT__TES__BLOCK_GUARD1(WHAT,CATEGORY)    SYNEIGHT__INTERNAL__BLOCK_GUARD1(BLOCK,TES,(WHAT),(CATEGORY))

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__BLOCK_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__TES__BLOCK_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__TES__BLOCK_EXIT                     } while(false)
#  define SYNEIGHT__TES__BLOCK_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__TES__BLOCK_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

#endif
// vim:ts=4:sw=4
