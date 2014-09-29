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
 * @version $Id: unittest.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__UNITTEST_HPP
#define SYNEIGHT__ANNOTATION__UNITTEST_HPP

#ifndef SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE
#  error Include the annotations only through the global configuration files.
#elif SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE != 2
#  error Including unittest annotations while not compiling a test driver
#endif

#include <syneight/base/annotation/testsupport.hpp>

#include <syneight/base/annotation/bits/testcase.hpp>

#if SYNEIGHT__SWITCH__MEMORY_ANALYSIS == 1
#  include <syneight/base/diagnostics/memory_operators.hpp>
#endif

/// @todo include test management

#endif
// vim:ts=4:sw=4
