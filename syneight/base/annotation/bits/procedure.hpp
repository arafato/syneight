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
 * @version $Id: procedure.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__PROCEDURE_HPP
#define SYNEIGHT__ANNOTATION__BITS__PROCEDURE_HPP

#include <syneight/base/annotation/base/block.hpp>

#define SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME (::std::string("[ ")+SYNEIGHT__FUNC_NAME+" ] ")

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__PROCEDURE_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(PROCEDURE,AUD,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__AUD__PROCEDURE_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(PROCEDURE,AUD,(WHAT),(CATEGORY))
#  define SYNEIGHT__AUD__PROCEDURE_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__AUD__PROCEDURE_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(PROCEDURE,AUD,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__AUD__PROCEDURE_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(PROCEDURE,AUD,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__AUD__PROCEDURE_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__AUD__PROCEDURE_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__AUD__PROCEDURE_EXIT                     } while(false)
#  define SYNEIGHT__AUD__PROCEDURE_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__AUD__PROCEDURE_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__PROCEDURE_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(PROCEDURE,DEB,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__DEB__PROCEDURE_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(PROCEDURE,DEB,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT),(CATEGORY))
#  define SYNEIGHT__DEB__PROCEDURE_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__DEB__PROCEDURE_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(PROCEDURE,DEB,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__DEB__PROCEDURE_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(PROCEDURE,DEB,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__DEB__PROCEDURE_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__DEB__PROCEDURE_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__DEB__PROCEDURE_EXIT                     } while(false)
#  define SYNEIGHT__DEB__PROCEDURE_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__DEB__PROCEDURE_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__PROCEDURE_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(PROCEDURE,PRO,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__PRO__PROCEDURE_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(PROCEDURE,PRO,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT),(CATEGORY))
#  define SYNEIGHT__PRO__PROCEDURE_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__PRO__PROCEDURE_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(PROCEDURE,PRO,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__PRO__PROCEDURE_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(PROCEDURE,PRO,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT),(CATEGORY))

#else 

#  define SYNEIGHT__PRO__PROCEDURE_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__PRO__PROCEDURE_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__PRO__PROCEDURE_EXIT                     } while(false)
#  define SYNEIGHT__PRO__PROCEDURE_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__PRO__PROCEDURE_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__PROCEDURE_ENTER(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_ENTER(PROCEDURE,TES,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__TES__PROCEDURE_ENTER1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_ENTER1(PROCEDURE,TES,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT),(CATEGORY))
#  define SYNEIGHT__TES__PROCEDURE_EXIT                     \
     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__TES__PROCEDURE_GUARD(WHAT)              \
     SYNEIGHT__INTERNAL__BLOCK_GUARD(PROCEDURE,TES,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT))
#  define SYNEIGHT__TES__PROCEDURE_GUARD1(WHAT,CATEGORY)    \
     SYNEIGHT__INTERNAL__BLOCK_GUARD1(PROCEDURE,TES,SYNEIGHT__INTERNAL__PROCEDURE_FUNC_NAME+(WHAT),(CATEGORY))

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__PROCEDURE_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__TES__PROCEDURE_ENTER1(WHAT,CATEGORY)    do { ((void)0)
#  define SYNEIGHT__TES__PROCEDURE_EXIT                     } while(false)
#  define SYNEIGHT__TES__PROCEDURE_GUARD(WHAT)              ((void)0)
#  define SYNEIGHT__TES__PROCEDURE_GUARD1(WHAT,CATEGORY)    ((void)0)

#endif

#endif
// vim:ts=4:sw=4
