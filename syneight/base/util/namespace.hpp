/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/util/namespace.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: namespace.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Namespaces ::syneight::baseutil and ::syneight::baseutil::internal.
 *
 * @note DOCUMENTED
 */

#ifndef SYNEIGHT__BASE__UTIL__NAMESPACE_HPP
#define SYNEIGHT__BASE__UTIL__NAMESPACE_HPP

#include <syneight/base/root/config.hpp>

#define SYNEIGHT__BEGIN__NAMESPACE__BASEUTIL SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE(baseutil)
#define SYNEIGHT__END__NAMESPACE__BASEUTIL   SYNEIGHT__BASE__GENERIC_END_NAMESPACE(baseutil)

// make sure that the namespace exists
SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__BASEUTIL;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__BASEUTIL;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
