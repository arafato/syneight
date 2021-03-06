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
 * @version $Id: syneight_simple_layout.cpp 1055 2005-06-07 12:33:52Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/internal/syneight_simple_layout.hpp>

#include <syneight/base/diagnostics/internal/level_priority.hpp>

#include <syneight/base/util/string.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

Syneight_Simple_Layout::Syneight_Simple_Layout() 
{
}

Syneight_Simple_Layout::~Syneight_Simple_Layout() 
{
}

::std::string Syneight_Simple_Layout::format(const ::log4cpp::LoggingEvent& event) 
{
    char const * const priorityName(level_to_string(priority_to_level(event.priority)));
    return baseutil::to_string(priorityName," - ",event.message,'\n');
}


SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
