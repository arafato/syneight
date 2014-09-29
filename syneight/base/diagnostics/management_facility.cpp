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
 * @version $Id: management_facility.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/management_facility.hpp>

#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>
#include <syneight/base/diagnostics/kernel/diagnostics_guard.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

void Management_Facility::init()
{
    return Facility_Implementation::instance().
	init();
}

void Management_Facility::load_config(::std::string const & name)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::instance().
	load_config(name);
    SYNEIGHT__DIAGNOSTICS_END;
}
    

Management_Facility::Log_Sink_Names_t const & Management_Facility::log_sink_names()
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::instance().
	log_sink_names();
    SYNEIGHT__DIAGNOSTICS_END;
}


Category_Handle * Management_Facility::category(::std::string const & name) 
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::instance().
	category(name);
    SYNEIGHT__DIAGNOSTICS_END;
}

Category_Handle * Management_Facility::category(Category_Handle * const root,
						 ::std::string const & name)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::instance().
	category(root,name);
    SYNEIGHT__DIAGNOSTICS_END;
}

void Management_Facility::register_observer(Observer & observer) 
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::instance().
	register_observer(observer);
    SYNEIGHT__DIAGNOSTICS_END;
}

void Management_Facility::unregister_observer(Observer & observer) 
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::instance().
	unregister_observer(observer);
    SYNEIGHT__DIAGNOSTICS_END;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
