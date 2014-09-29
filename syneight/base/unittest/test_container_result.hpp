/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/test_container_result.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_container_result.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Container_Result.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TEST_CONTAINER_RESULT_HPP
#define SYNEIGHT__BASE__UNITTEST__TEST_CONTAINER_RESULT_HPP

#include <syneight/base/exception/exception.hpp>

#include <syneight/base/unittest/test_result.hpp>
#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/level.hpp>

#include <vector>
#include <iostream>
#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/// @brief: Derived from Test_Result, a Test_Container_Result collects failed Test_Results. 
class Test_Container_Result 
	: public Test_Result
{
private:
	typedef Test_Container_Result Self;
/**---------------------------------------------------------------------------
 * @name Constructor and destructor 
 * @{
 */
public:
	/// @brief Expects syneight::diagnostics::Level_t as argument (test level to operate on)
	Test_Container_Result(Level_t level);
	~Test_Container_Result();

	Self * clone() const;
	
	bool is_empty() const;
	void add_result(Test_Result const & result);
// @}
protected:
	Level_t m_test_level;
	::std::vector<Test_Result const *> m_test_results;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
