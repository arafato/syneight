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
 * @version $Id: block.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__BLOCK_HPP
#define SYNEIGHT__ANNOTATION__BASE__BLOCK_HPP

#include <syneight/base/annotation/config.hpp>
#include <syneight/base/diagnostics/block_guard.hpp>


////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////


#define  SYNEIGHT__INTERNAL__BLOCK_GUARD1(TYPE,LEVEL,WHAT,CATEGORY) \
  ::syneight::diagnostics::Block_Guard \
  syneight_reserved_name_internal_block_guard(true, \
                                             ::syneight::diagnostics:: TYPE ## _ENTER_TYPE, \
                                             ::syneight::diagnostics:: TYPE ## _EXIT_TYPE, \
                                             ::syneight::diagnostics:: LEVEL ## _LEVEL,\
                                             WHAT, \
					     SYNEIGHT__PARAM__STD_NR_WHAT, \
                                             SYNEIGHT__BASE_FILE,\
                                             __FILE__, \
					     __LINE__, \
					     CATEGORY)

////////////////////////////////////////////////////////////////////////////////
//
// Derived Macros
//
////////////////////////////////////////////////////////////////////////////////


#define SYNEIGHT__INTERNAL__BLOCK_ENTER(TYPE,LEVEL,WHAT) \
  SYNEIGHT__INTERNAL__BLOCK_ENTER1(TYPE,LEVEL,WHAT,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY)

#define SYNEIGHT__INTERNAL__BLOCK_GUARD(TYPE,LEVEL,WHAT) \
  SYNEIGHT__INTERNAL__BLOCK_GUARD1(TYPE,LEVEL,WHAT,SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY)

#define SYNEIGHT__INTERNAL__BLOCK_ENTER1(TYPE,LEVEL,WHAT,CATEGORY)  \
   do { SYNEIGHT__INTERNAL__BLOCK_GUARD1(TYPE,LEVEL,WHAT,CATEGORY); { ((void)0)

#define SYNEIGHT__INTERNAL__BLOCK_EXIT }} while(false) 

#endif
// vim:ts=4:sw=4
