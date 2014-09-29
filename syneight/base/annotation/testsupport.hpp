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
 * @version $Id: testsupport.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__TESTSUPPORT_HPP
#define SYNEIGHT__ANNOTATION__TESTSUPPORT_HPP

#ifndef SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE
#  error Include the annotations only through the global configuration files.
#elif SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE < 1
#  error Including testsupport annotations while compiling production code
#endif

#ifndef SYNEIGHT__SWITCH__TEST_ANNOTATIONS
#  define SYNEIGHT__SWITCH__TEST_ANNOTATIONS 1
#endif

#include <syneight/base/annotation/production.hpp>

#include <syneight/base/annotation/bits/tests.hpp>

#include <syneight/base/annotation/bits/throw.hpp>

#include <syneight/base/annotation/bits/memory_analysis.hpp>

#endif
// vim:ts=4:sw=4
