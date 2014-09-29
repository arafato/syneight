/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/test_case_result.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_case_result.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Case_Result.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TEST_CASE_RESULT_HPP
#define SYNEIGHT__BASE__UNITTEST__TEST_CASE_RESULT_HPP

#include <syneight/base/exception/exception.hpp>


#include <syneight/base/unittest/test_result.hpp>
#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/level.hpp>

#include <vector>
#include <iostream>
#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/**
 * @brief A Test_Result is aggregated to Testables and modified during test runs by adding failures and errors to it.  
 *
 * @nosubgrouping
 */
class Test_Case_Result
	: public Test_Result
{
private:
	typedef Test_Case_Result Self;		
/**---------------------------------------------------------------------------
 * @name Constructor and destructor
 * @{
 */
public:
	Test_Case_Result();
	/// @brief Expects syneight::diagnostics::Level_t as argument (test level to operate on).
	Test_Case_Result(Level_t level);
	virtual ~Test_Case_Result();

	virtual Self * clone() const;
// @}
/**---------------------------------------------------------------------------
 * @name Add-methods
 */
public:
	// NOTE: Passed string references have to be const, as they result from Testable.get_name()
	
	/// @brief Adds Testable to vector of failed Testables for later evaluation. Failed Testables contain at least one assertion with result 'false'. 
	void add_failure(::std::string const & failed_testable_name);
	/// @brief  Adds Testables to vector of errousnous Testables for later evaluation. Errousnous Testables have thrown at least one exception. 
	// 			This method is not to be called by Test_Runners.
	// 			
	// 			Base add_result(Test_Result). This is only needed in Test_Containers, but has to be implemented blank for Test_Result,too, 
	//			resulting from the implementation of run(), where add_result is called in any case. 
	void add_error(::std::string const & err_testable_name);
// @}

/// @brief Whether there are failures / errors to be reported or not.  
	bool is_empty() const;	// returns true if failed_test_units.size() == 0 && err_test_units.size() == 0. 
	
protected:
	
	::std::vector< ::std::string> m_failed_test_units;
	::std::vector< ::std::string> m_err_test_units;
	
	Level_t m_test_level;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
