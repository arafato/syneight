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
 * @version $Id: tests.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__TESTS_HPP
#define SYNEIGHT__ANNOTATION__BITS__TESTS_HPP

#include <syneight/base/annotation/bits/assert.hpp>
#include <syneight/base/annotation/bits/rel_modifier.hpp>

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TEST(COND) \
     SYNEIGHT__TES__ASSERT(SYNEIGHT__INTERNAL__PARAM__TEST_ERROR_EXCEPTION_TYPE,COND)
#  define SYNEIGHT__TEST__REL(OP1,REL,OP2) \
     SYNEIGHT__REL(SYNEIGHT__TES__ASSERT1, \
                  SYNEIGHT__INTERNAL__PARAM__TEST_ERROR_EXCEPTION_TYPE,\
                  (OP1),REL,(OP2))

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TEST(COND)       ((void)0)
#  define SYNEIGHT__TEST__REL(OP1,REL,OP2) ((void)0)

#endif

#endif
// vim:ts=4:sw=4
