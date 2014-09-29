/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/type.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: type.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief The @ref ::syneight::diagnostics::Type_t constants used by
 * ::syneight::unittest.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TYPE_HPP
#define SYNEIGHT__BASE__UNITTEST__TYPE_HPP

#include <syneight/base/unittest/namespace.hpp>

#include <syneight/base/diagnostics/type.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

extern diagnostics::Type_t const TESTCASE_ENTER_TYPE;
extern diagnostics::Type_t const TESTCASE_EXIT_TYPE;
extern diagnostics::Type_t const TESTCASE_TIMEOUT_TYPE;

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
