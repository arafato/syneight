/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/root/bits/namespace.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: namespace.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief The namespaces ::syneight, ::syneight::internal, and unamed.
 *
 * @note DOCUMENTED -- NO TEST
 */

#ifndef SYNEIGHT__BASE__ROOT__BITS__NAMESPACE_HPP
#define SYNEIGHT__BASE__ROOT__BITS__NAMESPACE_HPP

#include <syneight/base/root/bits/generic_namespace_macros.hpp>

#define SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE(syneight)
#define SYNEIGHT__END__NAMESPACE__SYNEIGHT   SYNEIGHT__BASE__GENERIC_END_NAMESPACE(syneight)

#define SYNEIGHT__BEGIN__NAMESPACE__INTERNAL SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE(internal)
#define SYNEIGHT__END__NAMESPACE__INTERNAL   SYNEIGHT__BASE__GENERIC_END_NAMESPACE(internal)

// Make sure that the namespace exists.
SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#define SYNEIGHT__BEGIN__NAMESPACE__UNNAMED namespace { 
#define SYNEIGHT__END__NAMESPACE__UNNAMED   }

#endif
// vim:ts=4:sw=4
