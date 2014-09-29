/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/preprocessor/bits/emit_parameter.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: emit_parameter.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref SYNEIGHT__BASE__EMIT__PARAMETER and
 * @ref SYNEIGHT__BASE__EMIT__PARAMETER_MAX.
 *
 * Used in syneight/base/util/string.hpp.
 *
 * @note DOCUMENTED
 *
 * @todo test
 */

#ifndef SYNEIGHT__BASE__PREPROCESSOR__BITS__EMIT_PARAMETER_HPP
#define SYNEIGHT__BASE__PREPROCESSOR__BITS__EMIT_PARAMETER_HPP

/**
 * @brief Emits paramter lists where each entry consists of one fixed
 * strings (@a TEXT) which is concatenated with the running id. The id
 * is counted from 0 to @ref SYNEIGHT__BASE__EMIT__PARAMETER_MAX.
 *
 * For example:
 *   SYNEIGHT__BASE__EMIT__PARAMETER(typename T,COUNT)
 * yields 
 *   typename T0, typename T1, ... typename TCOUNT
 */ 
#define SYNEIGHT__BASE__EMIT__PARAMETER(TEXT,COUNT) SYNEIGHT__INTERNAL__EMIT__PARAMETER(TEXT,COUNT)
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER(TEXT,COUNT) SYNEIGHT__INTERNAL__EMIT__PARAMETER ## COUNT (TEXT)

#define SYNEIGHT__INTERNAL__EMIT__PARAMETER10(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER9(TEXT) , TEXT ## 10
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER9(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER8(TEXT) , TEXT ## 9
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER8(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER7(TEXT) , TEXT ## 8
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER7(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER6(TEXT) , TEXT ## 7
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER6(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER5(TEXT) , TEXT ## 6
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER5(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER4(TEXT) , TEXT ## 5
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER4(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER3(TEXT) , TEXT ## 4
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER3(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER2(TEXT) , TEXT ## 3
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER2(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER1(TEXT) , TEXT ## 2
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER1(TEXT) SYNEIGHT__INTERNAL__EMIT__PARAMETER0(TEXT) , TEXT ## 1
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER0(TEXT) TEXT ## 0
#define SYNEIGHT__INTERNAL__EMIT__PARAMETER_1(TEXT) 


/**
 * @brief The maximum count in @ref SYNEIGHT__BASE__EMIT__PARAMETER
 */
#define SYNEIGHT__BASE__EMIT__PARAMETER_MAX 10

#endif

// vim:ts=4:sw=4
