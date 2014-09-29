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
 * @version $Id: testcase.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__TESTCASE_HPP
#define SYNEIGHT__ANNOTATION__BITS__TESTCASE_HPP

#include <syneight/base/annotation/base/block.hpp>

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__TESTCASE_ENTER(WHAT)              SYNEIGHT__INTERNAL__BLOCK_ENTER(TESTCASE,TES,(WHAT))
#  define SYNEIGHT__TES__TESTCASE_EXIT                     SYNEIGHT__INTERNAL__BLOCK_EXIT
#  define SYNEIGHT__TES__TESTCASE_GUARD(WHAT)              SYNEIGHT__INTERNAL__BLOCK_GUARD(TESTCASE,TES,(WHAT))

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__TESTCASE_ENTER(WHAT)              do { ((void)0)
#  define SYNEIGHT__TES__TESTCASE_EXIT                     } while(false)
#  define SYNEIGHT__TES__TESTCASE_GUARD(WHAT)              ((void)0)

#endif



#endif
// vim:ts=4:sw=4
