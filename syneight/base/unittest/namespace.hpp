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
 * @version $Id: namespace.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__NAMESPACE_HPP
#define SYNEIGHT__BASE__UNITTEST__NAMESPACE_HPP

#include <syneight/base/root/config.hpp>

#define SYNEIGHT__BEGIN__NAMESPACE__UNITTEST namespace unittest { typedef int USELESS__TYPE__NAMESPACE__UNITTEST
#define SYNEIGHT__END__NAMESPACE__UNITTEST   } void USELESS__FUNCTION__NAMESPACE__UNITTEST (unittest::USELESS__TYPE__NAMESPACE__UNITTEST)

// make sure that the namespace exists
SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
