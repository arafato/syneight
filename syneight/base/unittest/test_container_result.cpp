/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/test_container_result.cpp
 *
 * @author TODO
 * @author $Author: esdentem $
 *
 * @version $Id: test_container_result.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/test_container_result.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Test_Container_Result::Test_Container_Result(Level_t level)
	: m_test_level(level)
{
}
Test_Container_Result::~Test_Container_Result()
{
}
Test_Container_Result * Test_Container_Result::clone() const
{
	return new Self(*this);
}

bool Test_Container_Result::is_empty() const
{
	::std::vector<Test_Result const *>::const_iterator begin(m_test_results.begin());
	::std::vector<Test_Result const *>::const_iterator const end(m_test_results.end());
	
	for(;begin != end; ++begin) {
		const bool no_results = (*begin)->is_empty();
		if( !no_results ) return false;
	}
	return true;
}

void Test_Container_Result::add_result(Test_Result const & result)
{
	m_test_results.push_back(&result);
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4

