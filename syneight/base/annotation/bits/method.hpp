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
 * @version $Id: method.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__METHOD_HPP
#define SYNEIGHT__ANNOTATION__BITS__METHOD_HPP

#include <syneight/base/annotation/base/block.hpp>

#include <string>

#define SYNEIGHT__INTERNAL__METHOD_FUNC_NAME (::std::string("[ ") + SYNEIGHT__FUNC_NAME + " ] ")

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__METHOD_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(METHOD,AUD, SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__AUD__METHOD_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(METHOD,AUD,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))
#  define SYNEIGHT__AUD__METHOD_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__AUD__METHOD_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(METHOD,AUD,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__AUD__METHOD_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(METHOD,AUD,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__AUD__METHOD_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__AUD__METHOD_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__AUD__METHOD_EXIT                     } while(false)
#  define SYNEIGHT__AUD__METHOD_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__AUD__METHOD_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__METHOD_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(METHOD,DEB,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__DEB__METHOD_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(METHOD,DEB,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))
#  define SYNEIGHT__DEB__METHOD_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__DEB__METHOD_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(METHOD,DEB,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__DEB__METHOD_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(METHOD,DEB,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__DEB__METHOD_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__DEB__METHOD_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__DEB__METHOD_EXIT                     } while(false)
#  define SYNEIGHT__DEB__METHOD_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__DEB__METHOD_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__METHOD_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(METHOD,PRO,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__PRO__METHOD_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(METHOD,PRO,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))
#  define SYNEIGHT__PRO__METHOD_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__PRO__METHOD_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(METHOD,PRO,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__PRO__METHOD_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(METHOD,PRO,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__PRO__METHOD_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__PRO__METHOD_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__PRO__METHOD_EXIT                     } while(false)
#  define SYNEIGHT__PRO__METHOD_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__PRO__METHOD_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__METHOD_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(METHOD,TES,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__TES__METHOD_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(METHOD,TES,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))
#  define SYNEIGHT__TES__METHOD_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__TES__METHOD_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(METHOD,TES,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT))
#  define SYNEIGHT__TES__METHOD_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(METHOD,TES,SYNEIGHT__INTERNAL__METHOD_FUNC_NAME+(WHAT),(CATEGORY))

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__METHOD_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__TES__METHOD_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__TES__METHOD_EXIT                     } while(false)
#  define SYNEIGHT__TES__METHOD_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__TES__METHOD_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif



#endif
// vim:ts=4:sw=4
