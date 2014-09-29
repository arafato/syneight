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

#include <syneight/base/unittest/management_facility.hpp>

#include <syneight/base/unittest/kernel/facility_implementation.hpp>
#include <syneight/base/diagnostics/kernel/diagnostics_guard.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

void Management_Facility::set_test_data(Test_Data & test_data)
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	Facility_Implementation::get_instance().
	set_test_data(test_data);
	SYNEIGHT__DIAGNOSTICS_END;
}


void Management_Facility::register_observer(Observer & observer)
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	Facility_Implementation::get_instance().
	register_observer(observer);
	SYNEIGHT__DIAGNOSTICS_END;
}

void Management_Facility::unregister_observer(Observer & observer)
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	Facility_Implementation::get_instance().
	unregister_observer(observer);
	SYNEIGHT__DIAGNOSTICS_END;
}

void Management_Facility::testcase_enter(Test_Result & test_result)
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	Facility_Implementation::get_instance().
	testcase_enter(test_result);
	SYNEIGHT__DIAGNOSTICS_END;
}

void Management_Facility::testcase_exit()
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	Facility_Implementation::get_instance().
	testcase_exit();
	SYNEIGHT__DIAGNOSTICS_END;
}

void Management_Facility::disable_test_observer()
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	Facility_Implementation::get_instance().
	disable_test_observer();
	SYNEIGHT__DIAGNOSTICS_END;
}

void Management_Facility::enable_test_observer()
{
	SYNEIGHT__DIAGNOSTICS_BEGIN;
	Facility_Implementation::get_instance().
	enable_test_observer();
	SYNEIGHT__DIAGNOSTICS_END;
}


SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
