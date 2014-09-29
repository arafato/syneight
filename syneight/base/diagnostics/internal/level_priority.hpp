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
 * @version $Id: level_priority.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__DETAIL__LEVEL_PRIORITY_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__DETAIL__LEVEL_PRIORITY_HPP

#include <syneight/base/diagnostics/level.hpp>

#include <log4cpp/Priority.hh>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

inline ::log4cpp::Priority::Value level_to_priority(Level_t const level)
{
    return level*128;
}

inline Level_t priority_to_level(::log4cpp::Priority::Value const value)
{
    return static_cast <Level_t> (value / 128);
}


SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif 
// vim:ts=4:sw=4
