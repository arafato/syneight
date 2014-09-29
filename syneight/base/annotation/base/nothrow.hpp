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
 * @version $Id: nothrow.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__NOTHROW_HPP
#define SYNEIGHT__ANNOTATION__BASE__NOTHROW_HPP

#include <syneight/base/annotation/base/unexpected_exception.hpp>

////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////

#define SYNEIGHT__INTERNAL__NOTHROW_ENTER do { try {

#define SYNEIGHT__INTERNAL__NOTHROW_EXIT(LEVEL,RETHROW) \
    } \
    SYNEIGHT__INTERNAL__UNEXPECTED_EXCEPTION(LEVEL,RETHROW); \
  } while(false) 

#endif
// vim:ts=4:sw=4
