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
 * @version $Id: facility.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/facility.hpp>

#include <syneight/base/unittest/kernel/facility_implementation.hpp>
#include <syneight/base/diagnostics/kernel/diagnostics_guard.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

::std::string const & Facility::get_data(::std::string const & id)
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	return Facility_Implementation::get_instance().
	get_data(id);
	SYNEIGHT__DIAGNOSTICS_END;
}


bool Facility::cmp_data(::std::string const & id,
						::std::string const & data)
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	return Facility_Implementation::get_instance().
	cmp_data(id,data);
	SYNEIGHT__DIAGNOSTICS_END;
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
