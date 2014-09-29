/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/init.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: init.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::init
 *
 * TODO: Long description.
 *
 * @note CLEAN
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__INIT_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__INIT_HPP

#include <syneight/base/diagnostics/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

/**
 * @brief This procedure is called when the @ref Logging_Facility or
 * @ref Logging_Management_Facility is used for the first time. NEVER
 * call this procedure directly.
 *
 * @throw never -- if it does, the process will exit.
 */ 
void init(::std::string & log_sink_file_name,
	  ::std::vector<Observer*> & observers);

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
