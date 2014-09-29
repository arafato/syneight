/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/preprocessor/bits/dec.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: dec.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref SYNEIGHT__BASE__DEC, @ref SYNEIGHT__BASE__DEC_MAX, @ref
 * SYNEIGHT__BASE__DEC_MIN.
 *
 * @note DOCUMENTED
 *
 * @todo test
 */

#ifndef SYNEIGHT__PREPROCESSOR__BITS__DEC_HPP
#define SYNEIGHT__PREPROCESSOR__BITS__DEC_HPP

/**
 * @brief decrements @a COUNT by one. Works on @ref
 * SYNEIGHT__BASE__DEC_MIN <= @a COUNT <= SYNEIGHT__BASE__DEC_MAX.
 */ 
#define SYNEIGHT__BASE__DEC(COUNT) SYNEIGHT__INTERNAL__DEC(COUNT)

#define SYNEIGHT__INTERNAL__DEC(COUNT) SYNEIGHT__INTERNAL__DEC ## COUNT
#define SYNEIGHT__INTERNAL__DEC10 9
#define SYNEIGHT__INTERNAL__DEC9 8
#define SYNEIGHT__INTERNAL__DEC8 7
#define SYNEIGHT__INTERNAL__DEC7 6
#define SYNEIGHT__INTERNAL__DEC6 5
#define SYNEIGHT__INTERNAL__DEC5 4
#define SYNEIGHT__INTERNAL__DEC4 3
#define SYNEIGHT__INTERNAL__DEC3 2
#define SYNEIGHT__INTERNAL__DEC2 1
#define SYNEIGHT__INTERNAL__DEC1 0
#define SYNEIGHT__INTERNAL__DEC0 _1


/**
 * @brief Maximum input for @ref SYNEIGHT__BASE__DEC
 */ 
#define SYNEIGHT__BASE__DEC_MAX 10

/**
 * @brief Minimum input for @ref SYNEIGHT__BASE__DEC
 */
#define SYNEIGHT__BASE__DEC_MIN 0

#endif

// vim:ts=4:sw=4
