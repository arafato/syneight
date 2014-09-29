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
 * @version $Id: production.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

/**
 * @attention SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE must be
 * set. This switch controls the selection of the annotation/interfaces. For
 * example, bits/trace.hpp will not define the TEST_TRACE macros, if
 * SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE is smaller than 2.
 */

#ifndef SYNEIGHT__ANNOTATION__PRODUCTION_HPP
#define SYNEIGHT__ANNOTATION__PRODUCTION_HPP

#ifndef SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE
#  error Include the annotation/interfaces only through the global configuration files.
#endif

// traces /////////////////////////////////////////////////////////////////////
#include <syneight/base/annotation/bits/trace.hpp>
#include <syneight/base/annotation/bits/binary_trace.hpp>

// blocks /////////////////////////////////////////////////////////////////////
#include <syneight/base/annotation/bits/block.hpp>
#include <syneight/base/annotation/bits/method.hpp>
#include <syneight/base/annotation/bits/procedure.hpp>

// logging the stack trace ////////////////////////////////////////////////////
#include <syneight/base/annotation/bits/stack_trace.hpp>

// checking ///////////////////////////////////////////////////////////////////
#include <syneight/base/annotation/bits/check.hpp>

// asserting //////////////////////////////////////////////////////////////////
#include <syneight/base/annotation/bits/assert.hpp>
#include <syneight/base/annotation/bits/assert_log.hpp>
#include <syneight/base/annotation/bits/nothrow.hpp>
#include <syneight/base/annotation/bits/unexpected_exception.hpp>

// calling an invariance check ////////////////////////////////////////////////
#include <syneight/base/annotation/bits/invariance.hpp>

// modifiers for other annotations ////////////////////////////////////////////
#include <syneight/base/annotation/bits/rel_modifier.hpp>



#endif
// vim:ts=4:sw=4
