/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/preprocessor/arith.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: arith.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Arithmetic macros.
 *
 * All arithmetic macros work on very limited ranges. Usually, they only
 * work on positive integers up to some constant.
 * If negative numbers are supported, then they are represented as _X
 * for -X.
 *
 * The arithmetic macros: 
 *
 * @arg @ref SYNEIGHT__BASE_DEC with range @ref SYNEIGHT__BASE__DEC_MAX
 * and @ref SYNEIGHT__BASE__DEC_MIN
 *
 * @note DOCUMENTED
 */

#ifndef SYNEIGHT__BASE__PREPROCESSOR__ARITH_HPP
#define SYNEIGHT__BASE__PREPROCESSOR__ARITH_HPP

#include <syneight/base/preprocessor/bits/dec.hpp>

#endif
// vim:ts=4:sw=4
