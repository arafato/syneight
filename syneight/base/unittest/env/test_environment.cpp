/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/env/test_environment.cpp
 *
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_environment.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#include <syneight/base/unittest/env/test_environment.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Test_Environment::Test_Environment(Level_t const level)
	: m_test_level(level)
{
	// init Branch_Parser with wildcard * (matchall)
	m_subset_visitor = new Testable_Subset_Visitor();
	m_run_visitor = new Testable_Run_Visitor();
	m_list_visitor = new Testable_List_Visitor();
}
Test_Environment::Test_Environment(Level_t const level, ::std::string & branch_exp)
	: m_test_level(level)
{	
	// e.g. if branch expression is x/y/z, x is used here, 
	// y/z is to be submitted to assigned Testables in m_test_units. 
	m_subset_visitor = new Testable_Subset_Visitor(branch_exp);
	m_run_visitor = new Testable_Run_Visitor();
	m_list_visitor = new Testable_List_Visitor();
}
Test_Environment::Test_Environment(Self const & other)
	: m_test_level(other.m_test_level),
	  m_subset_visitor(other.m_subset_visitor)
{
	
}

Test_Environment::~Test_Environment()
{
}

Test_Environment * Test_Environment::clone() const
{
	return new Self(*this);
}

void Test_Environment::run()
{
	enter();

	m_current_test_unit->accept_visitor(*m_run_visitor);
	m_current_test_unit->accept_visitor(*m_list_visitor);
//	m_current_test_unit->accept_visitor(*m_stats_visitor);
	
	exit();
}

void Test_Environment::add_testable(Testable & test_unit)
{
	m_test_units->add_testable(test_unit);
}

void Test_Environment::enter()
{
	m_current_test_unit = m_subset_visitor->get_subset();
}
void Test_Environment::exit() const
{
	// TODO
}

// Declared outside of class for evident reasons: 
Test_Environment * create_std_test_environment()
{
	// set to audit level by default: 
	return new Test_Environment(Level_t(6));
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
