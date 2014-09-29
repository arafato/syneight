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
 * @version $Id: test_observer.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/kernel/test_observer.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Test_Observer::Test_Observer(Test_Result & test_result,
				 Observers_t const & observers)
{
}


Test_Observer::~Test_Observer()
{
}

void Test_Observer::log(Event const & event)
{
	// determine whether the Event is an error 
	//   OR
	// whether the Event is of Level_t TES

	// If yes, the event is "test-relevant".
	//	 store the event in the Test_Result
	//	 change the test verdict is necessary

#if 0

	// What is an error?
	if(type==FAILED_ASSERT_TYPE 
	   || (type==FAILED_CHECK_TYPE
	   && level > test_level)) { // huh where to get (in Test_Result)
	// error
	}
	else if(type==FAILED_CHECK_TYPE && level==TES_LEVEL){
	// inconclusive
	}

	if(level==TES_LEVEL) {
	// test relevant
	}

#endif
}


SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
