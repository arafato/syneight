/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/test_management_facility_implementation.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: facility_implementation.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Management_Facility_Implementation.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Test. Unknown_Test_Data_Id must be implemented and derived from
 * Unittest_Error.
 */

#ifndef SYNEIGHT__BASE__UNITTEST__DETAIL__FACILITY_IMPLEMENTATION_HPP
#define SYNEIGHT__BASE__UNITTEST__DETAIL__FACILITY_IMPLEMENTATION_HPP

#include <syneight/base/diagnostics/namespace.hpp>
#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/kernel/test_observer.hpp>
#include <syneight/base/unittest/env/test_data.hpp>
#include <syneight/base/unittest/exception/observer_configuration_error.hpp>

#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
class Observer;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;

SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Data;
class Test_Result;
class Test_Observer;

class Facility_Implementation
{
////////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Type
	 * @{
	 */
private:
	typedef Facility_Implementation Self;
	typedef ::syneight::diagnostics::Observer Observer;
	// @}


////////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Singelton
	 * @{
	 */
private:
	Facility_Implementation();
	friend class To_Avoid_Compiler_Errors;
public:
	inline static Self & get_instance();
private:
	static Facility_Implementation * m_instance;
	// @}

////////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Management_Facility interface
	 *
	 * @brief The same as in @ref Management_Facility BUT WITHOUT usage of
	 * the @ref SYNEIGHT__DIAGNOSTICS_BEGIN macro.
	 * 
	 * @{
	 */
public:
	/**
	 * @brief @a test_data is set to be the new @ref Test_Data to be
	 * used by the get_data and cmp_data calls.
	 */ 
	void set_test_data(Test_Data & test_data);
	
	bool is_observing();
	
	void register_observer(Observer & observer);
	void unregister_observer(Observer & observer);

	void testcase_enter(Test_Result & test_result);
	void testcase_exit();

	void disable_test_observer();
	void enable_test_observer();
	// @}


////////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Test_Facility interface
	 *
	 * @brief The same as in @ref Test_Facility BUT WITHOUT usage of
	 * the @ref SYNEIGHT__DIAGNOSTICS_BEGIN macro.
	 * 
	 * @{
	 */
public:
	::std::string const & get_data(::std::string const & id);
	bool cmp_data(::std::string const & id, ::std::string const & data);
	// @}


////////////////////////////////////////////////////////////////////////////////
	/**
	 * @name State
	 * @{
	 */
private:
	bool m_is_observing;
	Test_Data * m_test_data;
	Test_Observer * m_test_observer;
	typedef ::std::vector<Observer*> Observers_t;
	Observers_t m_observers;
};

Facility_Implementation & Facility_Implementation::get_instance()
{
	if(m_instance==NULL)
	m_instance=new Facility_Implementation();
	return *m_instance;
}
	// @}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
