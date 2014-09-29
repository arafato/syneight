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
 * @version $Id: test_case_result.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/test_case_result.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Test_Case_Result::Test_Case_Result()
	: m_test_level(Level_t(6))
{
}
Test_Case_Result::Test_Case_Result(Level_t level)
	: m_test_level(level)
{
}
Test_Case_Result::~Test_Case_Result()
{
}

Test_Case_Result * Test_Case_Result::clone() const
{
	return new Self(*this);
}

void Test_Case_Result::add_failure(::std::string const & failed_testable_name)
{
	m_failed_test_units.push_back(failed_testable_name);
}
void Test_Case_Result::add_error(::std::string const & err_testable_name)
{
	m_err_test_units.push_back(err_testable_name);
}

bool Test_Case_Result::is_empty() const
{
	return (m_failed_test_units.size() == 0 && m_err_test_units.size() == 0);
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4

