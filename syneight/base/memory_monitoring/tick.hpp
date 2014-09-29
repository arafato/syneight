/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/memory_monitoring/tick.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: tick.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__MEMORY_MONITORING__TICK_HPP
#define SYNEIGHT__BASE__MEMORY_MONITORING__TICK_HPP

#include <syneight/base/memory_monitoring/namespace.hpp>

#include <cstdlib> // for ::std::size_t

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;

/**
 * @brief This type is used to cound memory allocations.
 */
typedef ::std::size_t Tick_t;

SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
