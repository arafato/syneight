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
 * @version $Id: category_handle.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/internal/category_handle.hpp>

#include <syneight/base/diagnostics/internal/syneight_basic_layout.hpp>

#include <iostream>
#include <log4cpp/OstreamAppender.hh>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

Category_Handle * get_category(::std::string const & ref_name)
{
	::log4cpp::Category * category;
	if (  (category = ::log4cpp::Category::exists(ref_name)) != 0) {
			return to_diagnostics(*category);
	} else {
		::log4cpp::Category & cat = ::log4cpp::Category::getInstance(ref_name);
		
		cat.setAdditivity(false);
		::log4cpp::Layout * layout = new internal::Syneight_Basic_Layout();
		::log4cpp::Appender * appender = new ::log4cpp::OstreamAppender("OstreamAppender", &std::cout);
		appender->setLayout(layout);
		cat.setAppender(appender);
		return to_diagnostics(cat);
	}
}

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
