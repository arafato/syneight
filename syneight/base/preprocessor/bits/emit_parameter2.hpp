/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/preprocessor/bits/emit_parameter2.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: emit_parameter2.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref SYNEIGHT__BASE__EMIT__PARAMETER2 and
 * @ref SYNEIGHT__BASE__EMIT__PARAMETER2_MAX.
 *
 * Used in syneight/base/util/string.hpp.
 *
 * @note DOCUMENTED
 *
 * @todo test
 */

#ifndef SYNEIGHT__BASE__PREPROCESSOR__BITS__EMIT_PARAMETER2_HPP
#define SYNEIGHT__BASE__PREPROCESSOR__BITS__EMIT_PARAMETER2_HPP

/**
 * @brief Emits paramter lists where each entry consists of two fixed
 * strings (@a PRE and @a POST) which are both concatenated with the
 * running id. The id is counted from 0 to @ref
 * SYNEIGHT__BASE__EMIT__PARAMETER2_MAX.
 *
 * For example:
 *   SYNEIGHT__BASE__EMIT__PARAMETER2(T,COUNT,const & t) 
 * yields 
 *   T0 const & t0, T1 const & t1, .... TCOUNT const & tCOUNT
 */ 
#define SYNEIGHT__BASE__EMIT__PARAMETER2(PRE,COUNT,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_(PRE,COUNT,POST)
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_(PRE,COUNT,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_ ## COUNT (PRE,POST)

#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_10(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_9(PRE,POST) , PRE ## 10 POST ## 10
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_9(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_8(PRE,POST) , PRE ## 9 POST ## 9
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_8(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_7(PRE,POST) , PRE ## 8 POST ## 8
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_7(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_6(PRE,POST) , PRE ## 7 POST ## 7
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_6(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_5(PRE,POST) , PRE ## 6 POST ## 6
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_5(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_4(PRE,POST) , PRE ## 5 POST ## 5
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_4(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_3(PRE,POST) , PRE ## 4 POST ## 4
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_3(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_2(PRE,POST) , PRE ## 3 POST ## 3
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_2(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_1(PRE,POST) , PRE ## 2 POST ## 2
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_1(PRE,POST) SYNEIGHT__INTERNAL__EMIT__PARAMETER2_0(PRE,POST) , PRE ## 1 POST ## 1
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2_0(PRE,POST) PRE ## 0 POST ## 0
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2__1(PRE,POST) 

/**
 * @brief The maximum count in @ref SYNEIGHT__BASE__EMIT__PARAMETER2
 */ 
#define SYNEIGHT__BASE__EMIT__PARAMETER2_MAX 10

#endif

// vim:ts=4:sw=4
