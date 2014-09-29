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
 * @version $Id: rel_modifier.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__REL_MODIFIER_HPP
#define SYNEIGHT__ANNOTATION__BITS__REL_MODIFIER_HPP

#include <syneight/base/util/string.hpp>

// SYNEIGHT__REL(SYNEIGHT__AUD_ASSERT,Invalid_Range,min,<=,max);

#define SYNEIGHT__REL(MACRO,NAME,OP1,REL,OP2) \
     MACRO(NAME,\
          ((OP1) REL (OP2)), \
          "(" #OP1 ")" #REL "(" #OP2 ") evaluates to (" \
           + ::syneight::baseutil::to_string((OP1),")",#REL,"(",(OP2),")"))


#endif
// vim:ts=4:sw=4
