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
 * @version $Id: syneight_basic_layout.hpp 1055 2005-06-07 12:33:52Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__DIAGNOSTICS__DETAIL__SYNEIGHT_BASIC_LAYOUT_HPP
#define SYNEIGHT__DIAGNOSTICS__DETAIL__SYNEIGHT_BASIC_LAYOUT_HPP

#include <syneight/base/diagnostics/namespace.hpp>

#include <log4cpp/BasicLayout.hh>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

/**
 * Syneight_Basic_Layout is used internally and has the
 * same functionality as BasicLayout.
 * It is used to log with Level_t names. Therefore it has to be
 * in namespace log4cpp.
 **/
class Syneight_Basic_Layout 
    : public ::log4cpp::BasicLayout 
{
public:
    virtual ~Syneight_Basic_Layout();
    Syneight_Basic_Layout();
    
    /**
     * Formats the LoggingEvent in BasicLayout style:<br>
     * "timeStamp priority category ndc: message"
     **/
    virtual ::std::string format(::log4cpp::LoggingEvent const & event);
};

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif 
// vim:ts=4:sw=4
