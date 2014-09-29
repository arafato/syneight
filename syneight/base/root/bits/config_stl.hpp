/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/root/bits/config_stl.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: config_stl.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief This file should come with some configuration of the STL. It
 * is only a todo container -- the clay and dust that is to say.
 *
 * In particular, it should allow to switch the default allocator of
 * the STL such that if we use memory analysis, then memory buffering
 * should be disabled.
 *
 * @note Just a place holder
 *
 * @todo Make this work.
 */

#ifndef SYNEIGHT__BASE__ROOT__BITS__CONFIG_STL_HPP
#define SYNEIGHT__BASE__ROOT__BITS__CONFIG_STL_HPP

#ifndef SYNEIGHT__SWITCH__DEBUG_ALLOCATOR
#  define SYNEIGHT__SWITCH__DEBUG_ALLOCATOR 0
#endif


////////////////////////////////////////////////////////////////////////////////
// 
// Configuring the STL
//
////////////////////////////////////////////////////////////////////////////////


/// @todo do something sensible

#if 0
#if SYNEIGHT__SWITCH__DEBUG_ALLOCATOR == 1 
//#  if GCC version > ?
#    if 1
#    ifdef __STL_CONIFG_H 
#      error You have to include syneight/root/config_stl.hpp before including any stl headers
#    endif
#    define __STL_DEFAULT_ALLOCATOR(TP) __allocator< TP, 
#  endif
#endif
#endif

#endif

// vim:ts=4:sw=4
