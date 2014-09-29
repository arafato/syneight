/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/test_result.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_result.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Result.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TESTRESULT_HPP
#define SYNEIGHT__BASE__UNITTEST__TESTRESULT_HPP

#include <syneight/base/unittest/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/// @brief: Test_Result collects results of failed Testables. Base Class for Test_Case_Result and Test_Container_Result
class Test_Result 
{
/**---------------------------------------------------------------------------
 * @name Constructor and destructor 
 * @{
 */
private: 
	typedef Test_Result Self;
		
public:
	
	virtual ~Test_Result();
	virtual Self * clone() const =0;

	virtual bool is_empty() const =0;
// @}
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
