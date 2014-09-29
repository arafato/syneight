/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/memory_monitoring/namespace.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: namespace.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief The namespace ::syneight::memory_monitoring.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__MEMORY_MONITORING__NAMESPACE_HPP
#define SYNEIGHT__BASE__MEMORY_MONITORING__NAMESPACE_HPP

#include <syneight/base/root/config.hpp>

#define SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING namespace memory_monitoring {
#define SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING   }

// make sure that the namespace exists
SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
