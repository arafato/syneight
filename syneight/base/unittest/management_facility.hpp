/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/management_facility.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: management_facility.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Management_Facility.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Test. Improve documentation -- note that there are new exceptions
 * (at the moment there are throw 42s).
 */

#ifndef SYNEIGHT__BASE__UNITTEST__MANAGEMENT_FACILITY_HPP
#define SYNEIGHT__BASE__UNITTEST__MANAGEMENT_FACILITY_HPP

#include <syneight/base/diagnostics/namespace.hpp>
#include <syneight/base/unittest/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
class Observer;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;

SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Data;
class Test_Result;

/**
 * @class Management_Facility
 *
 * @brief "of static character"
 *
 * @nosubgrouping
 *
 * @todo exceptions
 */
class Management_Facility
{
private:
	Management_Facility();
	friend class To_Avoid_Compiler_Errors;
	typedef ::syneight::diagnostics::Observer Observer;

public:
	/**
	 * @brief Sets the @ref Test_Data to be by the @ref Test_Facility
	 */ 
	static void set_test_data(Test_Data & test_data);

	/**
	 * @brief Registers an @ref Observer which will only be called for
	 * test-relevant @ref Event s.
	 */ 
	static void register_observer(Observer & observer);

	/**
	 * @brief Unregisters an @ref Observer previously registered with
	 * @ref register_observer.
	 */
	static void unregister_observer(Observer & observer);

	/**
	 * @brief Must be called on entering a new test case. The @a
	 * test_result will be filled with all test relevant events and
	 * with a test verdict. When the test case is finished, @ref
	 * testcase_exit must be called.
	 */
	static void testcase_enter(Test_Result & test_result);
	/**
	 * @brief It must be called to end a testcase.
	 */
	static void testcase_exit();

	/**
	 * @brief After calling this method, the @ref Test_Facility and
	 * Test_Management_Facility will ignore all occurring events. 
	 *
	 * @todo more
	 */
	static void disable_test_observer();
	/**
	 * @brief To switch on again the listening to the event stream.
	 */
	static void enable_test_observer();
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
