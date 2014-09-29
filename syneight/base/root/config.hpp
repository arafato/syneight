/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/root/config.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: config.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Includes adaptors for the preprocessor, namespace macros and
 * configures the current environment, i.e., this file is not used to
 * wrap or adapt given libraries but to CONFIGURE these
 * libraries. This file MUST BE INCLUDED BEFORE including any other
 * syneight file.
 *
 * Currently, the following configurations are done by this library:
 * @arg classical configure-generated config.h 
 * @arg namespace marcros
 * @arg preprocessor wrappers
 * @arg stl configuration
 *
 * We use this config file to have a central configuration file for
 * all libraries which syneight is depending on. Since this file must
 * be included before including any other syneight file (i.e., it is
 * included by any other syneight file first -- directly or
 * indirectly), it can be used to place compile-time switches for used
 * libraries. 
 *
 * This file is defines the following macros as part of its interface:
 * @arg @ref SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE
 * @arg @ref SYNEIGHT__BASE__GENERIC_END_NAMESPACE
 * @arg @ref SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT
 * @arg @ref SYNEIGHT__END__NAMESPACE__SYNEIGHT
 * @arg @ref SYNEIGHT__BEGIN__NAMESPACE__INTERNAL
 * @arg @ref SYNEIGHT__END__NAMESPACE__INTERNAL
 * @arg @ref SYNEIGHT__BEGIN__NAMESPACE__UNNAMED
 * @arg @ref SYNEIGHT__END__NAMESPACE__UNNAMED
 *
 * For example, it can be used to switch the default allocator of an
 * STL implementation.
 *
 * @note DOCUMENTED -- NO TEST
 */

#ifndef SYNEIGHT__BASE__ROOT__CONFIG_HPP
#define SYNEIGHT__BASE__ROOT__CONFIG_HPP

#if HAVE_CONFIG_H
#  include <syneight/base/root/bits/config.h>
#endif

#include <syneight/base/root/bits/namespace.hpp>
#include <syneight/base/root/bits/config_stl.hpp>

#endif

// vim:ts=4:sw=4
