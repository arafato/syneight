/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/env/test_environment.hpp
 *
 * @author Christian Schallhart
 * @author Tobi Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_environment.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Environment.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TEST_ENVIRONMENT_HPP
#define SYNEIGHT__BASE__UNITTEST__TEST_ENVIRONMENT_HPP

#include <syneight/base/unittest/level.hpp>
#include <syneight/base/unittest/testable.hpp>
#include <syneight/base/unittest/test_case.hpp>
#include <syneight/base/unittest/test_container.hpp>
#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/testable_subset_visitor.hpp>
#include <syneight/base/unittest/testable_run_visitor.hpp>
#include <syneight/base/unittest/testable_list_visitor.hpp>

#include <syneight/base/unittest/exception/invalid_name_exception.hpp>

#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/**
 * @class Test_Environment
 * 
 * @brief Contains Testables and iteratively calls their run_test() method. Wrapping is necessary for enter- and exit procedures, 
 * parsing regular expressions x/y/z (in order to run specific test branches) a.m.m.
 *
 * @nosubgrouping
 */
class Test_Environment
{

private: 
	typedef Test_Environment Self;
		
public:
	
	Test_Environment(Level_t const level);
	Test_Environment(Level_t const level, ::std::string & branch_exp);
	Test_Environment(Self const & other);
	~Test_Environment();
   
	Self * clone() const;
	
	/// @brief Recursively run all tests in vector m_test_units. 
	void run();
	/// @brief Append Testable to run. 
	void add_testable(Testable & test_unit);
	
private: 
	/// @brief Runner's enter procedures.
	///    e.g. init timers
	void enter();
	/// @brief Runner's exit procedures. 
	void exit() const;
	/// @brief Vector containing Testables to run. 
	Test_Container * m_test_units;			// THE SUITE
	/// @brief Current Testable selected for run. 
	Testable * m_current_test_unit;			// CURRENT SUITE

	/// @brief Test level to pass to test units. 
	Level_t const m_test_level;
	/// @brief Subset visitor used to resolve a selection of Testables to run. 
	Testable_Subset_Visitor * m_subset_visitor;
	Testable_Run_Visitor * m_run_visitor;
	Testable_List_Visitor * m_list_visitor;
};

Test_Environment * create_std_test_environment();

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
