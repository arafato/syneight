/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/preprocessor/bits/for_0_to.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: for_0_to.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref SYNEIGHT__BASE__FOR_0_TO, @ref SYNEIGHT__BASE__FOR_0_TO_MAX.
 *
 * @note DOCUMENTED
 *
 * @todo test
 */

#ifndef SYNEIGHT__BASE__PREPROCESSOR__BITS__FOR_0_TO_HPP
#define SYNEIGHT__BASE__PREPROCESSOR__BITS__FOR_0_TO_HPP

/**
 * @brief Executes a macro (@a A) iteratively with argurment 0 to @a
 * COUNT. 0<= @a COUNT must be <= @ref SYNEIGHT__BASE__FOR_0_TO_MAX
 *
 * For example:
 *    SYNEIGHT__BASE__FOR_0_TO(A,COUNT) 
 * yileds:
 *   A(0) ... A(COUNT)
 */ 
#define SYNEIGHT__BASE__FOR_0_TO(MACRO,COUNT) SYNEIGHT__INTERNAL__FOR_0_TO(MACRO,COUNT)
#define SYNEIGHT__INTERNAL__FOR_0_TO(MACRO,COUNT) SYNEIGHT__INTERNAL__FOR_0_TO_##COUNT(MACRO)

#define SYNEIGHT__INTERNAL__FOR_0_TO_10(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_9(MACRO) MACRO(10)
#define SYNEIGHT__INTERNAL__FOR_0_TO_9(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_8(MACRO) MACRO(9)
#define SYNEIGHT__INTERNAL__FOR_0_TO_8(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_7(MACRO) MACRO(8)
#define SYNEIGHT__INTERNAL__FOR_0_TO_7(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_6(MACRO) MACRO(7)
#define SYNEIGHT__INTERNAL__FOR_0_TO_6(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_5(MACRO) MACRO(6)
#define SYNEIGHT__INTERNAL__FOR_0_TO_5(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_4(MACRO) MACRO(5)
#define SYNEIGHT__INTERNAL__FOR_0_TO_4(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_3(MACRO) MACRO(4)
#define SYNEIGHT__INTERNAL__FOR_0_TO_3(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_2(MACRO) MACRO(3)
#define SYNEIGHT__INTERNAL__FOR_0_TO_2(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_1(MACRO) MACRO(2)
#define SYNEIGHT__INTERNAL__FOR_0_TO_1(MACRO) SYNEIGHT__INTERNAL__FOR_0_TO_0(MACRO) MACRO(1)
#define SYNEIGHT__INTERNAL__FOR_0_TO_0(MACRO) MACRO(0)
#define SYNEIGHT__INTERNAL__FOR_0_TO__1(MACRO)

/**
 * @brief maximum count for @ref SYNEIGHT__BASE__FOR_0_TO
 */ 
#define SYNEIGHT__BASE__FOR_0_TO_MAX 10

#endif

// vim:ts=4:sw=4
