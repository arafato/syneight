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
 * @version $Id: test_case.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/test_case.hpp>

#include <syneight/base/unittest/testable_visitor.hpp>
#include <syneight/base/unittest/testable_const_visitor.hpp>
#include <syneight/base/unittest/exception/invalid_name_exception.hpp>

#include <boost/spirit/core.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Test_Case::~Test_Case()
{	
}

Test_Case::Test_Case(::std::string const & name, Level_t level, int timeout)
	: m_run(false),
	  m_test_result(new Test_Case_Result(level)),
	  m_test_level(level),
	  m_test_name(name),
	  m_test_timeout(timeout)
{
	// in case of invalid name
	if (!check_name(name)) {
	// throw exception in case of invalid name: 
		throw Invalid_Name_Exception(SYNEIGHT__SOURCE_LOCATION,name);
	}
}

Test_Case::Test_Case(Self const & other)
	: m_run(other.m_run),
	  m_test_result(other.m_test_result),
	  m_test_level(other.m_test_level),
	  m_test_name(other.m_test_name),
	  m_test_timeout(other.m_test_timeout)
{
}

Test_Case * Test_Case::clone() const
{
	return new Self(*this);
}

void Test_Case::set_result(Test_Case_Result & result)
{
	m_test_result = &result;
}

Test_Case_Result & Test_Case::test_result()
{
	return *(m_test_result);
}

Test_Case_Result const & Test_Case::test_result() const
{
	return *(m_test_result);
}

::std::string const & Test_Case::get_name() const
{
	return m_test_name;
}

void Test_Case::accept_visitor(Testable_Visitor & testable_visitor)
{
	testable_visitor.visit(*this);
}

void Test_Case::accept_visitor(Testable_Const_Visitor & testable_visitor) const
{
	testable_visitor.visit(*this);
}

void Test_Case::run_test()
{
	// Put assertions here.
	// In case of a failed assertion, call m_test_result.add_failure(ASSERTION_NAME)
	// in order to fill the test unit's Test_Case_Result.
	// add_error is to be called in Test_Container and Test_Runner, as this handles exceptions only.
}

void Test_Case::break_test()
{
	m_run = true;
}

void Test_Case::set_timeout(unsigned int timeout)
{
	m_test_timeout = timeout;
}

int Test_Case::get_timeout() const
{
	return m_test_timeout;
}
Level_t Test_Case::get_test_level() const
{
	return m_test_level;
}

bool Test_Case::check_name(::std::string const &name) const
{
	return ::boost::spirit::parse( name.c_str(),
					// Allow:
					// abc_def__ghi, 123_xyz
					// Disallow:
					// _abc, abc_
					( +::boost::spirit::alnum_p >>
					*('_' >> *::boost::spirit::alnum_p) >>
					+::boost::spirit::alnum_p)
					).full;	
}

bool Test_Case::is_atomic() const
{
	return true;
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


// vim:ts=4:sw=4
