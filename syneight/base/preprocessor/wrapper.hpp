/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/preprocessor/bits/wrapper.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: wrapper.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Adaption of the preprocessor. Currently, there is @ref
 * SYNEIGHT__BASE_FILE, and @ref SYNEIGHT__FUNC_NAME.
 *
 * Currently, this file ASSUMES that it is compiled with GCC.
 *
 * @note DOCUMENTED
 *
 * @todo Check for compiler/preprocessor.
 */

#ifndef SYNEIGHT__BASE__PREPROCESSOR__WRAPPER_HPP
#define SYNEIGHT__BASE__PREPROCESSOR__WRAPPER_HPP

/**
 * @brief The base file of the current preprocessing, i.e., the cpp
 * file which is currently processed. Thus, this macro can be used to
 * identify the cpp file where an error occured, even if the code has
 * been written in some hpp file.
 *
 * If the base file is not accessible, then SYNEIGHT__BASE_FILE
 * evaluates to "".
 */
#ifndef SYNEIGHT__BASE_FILE
#  define SYNEIGHT__BASE_FILE __BASE_FILE__
#endif

/**
 * @brief Pretty printed function name. Might expand within int main()
 * {} to "int main()". Supported by most compilers (this is not a true
 * pre-processor directive: It must be supported by the compiler).
 *
 * If the function is not accessible, then SYNEIGHT__FUNC_NAME
 * evaluates to "".
 */
#ifndef SYNEIGHT__FUNC_NAME
#  define SYNEIGHT__FUNC_NAME __PRETTY_FUNCTION__
#endif

#endif
// vim:ts=4:sw=4
