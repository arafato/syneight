/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/memory_monitoring/type.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: type.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief The @ref ::syneight::diagnostics::Type_t constants used by
 * syneight::memory_monitoring.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__MEMORY_MONITORING__TYPE_HPP
#define SYNEIGHT__BASE__MEMORY_MONITORING__TYPE_HPP

#include <syneight/base/memory_monitoring/namespace.hpp>

#include <syneight/base/diagnostics/type.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;

extern diagnostics::Type_t const MEMORY_LEAK_TYPE;
extern diagnostics::Type_t const MEMORY_ANTI_LEAK_TYPE;
extern diagnostics::Type_t const MEMORY_UNEXPECTED_DEALLOCATION;
extern diagnostics::Type_t const MEMORY_ANALYSIS_ENTER_TYPE;
extern diagnostics::Type_t const MEMORY_ANALYSIS_EXIT_TYPE;
extern diagnostics::Type_t const MEMORY_BALANCE_TYPE;

SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
