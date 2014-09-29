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
 * @version $Id: test_backend.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__TESTMANAGEMENT__TEST_BACKEND_HPP
#define SYNEIGHT__TESTMANAGEMENT__TEST_BACKEND_HPP

#include <string>
#include <vector>

#include <syneight/base/diagnostics/detail/level.hpp>
#include <syneight/base/unittest/testable.hpp>
#include <syneight/base/unittest/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Runner
{
	
public:
	
	Test_Runner(Level_t Level);
	~Test_Runner();
   	
	/// @brief Recursively run all tests in vector testUnits. 
	void run();
	void add_testable(Testable &test_unit);
	
private: 
		
	::std::vector<Testable> test_units;
};

Test_Runner * create_std_test_runner();

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
