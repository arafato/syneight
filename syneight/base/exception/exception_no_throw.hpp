/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/exception_no_throw.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: exception_no_throw.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Macro @ref SYNEIGHT__EXCEPTION_NO_THROW.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__EXCEPTION__EXCEPTION_NO_THROW_HPP
#define SYNEIGHT__EXCEPTION__EXCEPTION_NO_THROW_HPP

#include <syneight/base/root/config.hpp>

/** 
 * @todo This switch has to use a definition out of config.h generated
 * by autoconf @todo document.
 */
#ifndef SYNEIGHT__SWITCH__EXCEPTION_NO_THROW
/**
 *  @brief This switch must be set to 1 if the std library and the
 *  compiler forces us to use throw() declrations
 */
#  define SYNEIGHT__SWITCH__EXCEPTION_NO_THROW 1
#endif


#if SYNEIGHT__SWITCH__EXCEPTION_NO_THROW == 1
/**
 * @brief replaces the throw() declaration in the destructor and the
 * what method of exceptions.
 */
#  define SYNEIGHT__EXCEPTION_NO_THROW throw()
#else 
#  define SYNEIGHT__EXCEPTION_NO_THROW 
#endif

#endif
// vim:ts=4:sw=4
