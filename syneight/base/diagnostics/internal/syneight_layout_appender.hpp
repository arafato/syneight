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
 * @version $Id: syneight_layout_appender.hpp 1055 2005-06-07 12:33:52Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__DIAGNOSTICS__DETAIL__SYNEIGHT_LAYOUT_APPENDER_HPP
#define SYNEIGHT__DIAGNOSTICS__DETAIL__SYNEIGHT_LAYOUT_APPENDER_HPP

#include <syneight/base/diagnostics/namespace.hpp>

#include <log4cpp/Layout.hh>
#include <log4cpp/LayoutAppender.hh>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

class Syneight_Layout_Appender
    : public ::log4cpp::LayoutAppender
{
public:
    inline Syneight_Layout_Appender(::std::string const & str) 
	: ::log4cpp::LayoutAppender(str)
    {
    }
    
    /**@brief Returns the Layout of the Appender */
    ::log4cpp::Layout * get_layout();
};


SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
