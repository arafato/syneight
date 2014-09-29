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
 * @version $Id: test_data_adaptor.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__UNITTEST__ENV__TEST_SYSTEM__TEST_DATA_ADAPTOR_HPP
#define SYNEIGHT__UNITTEST__ENV__TEST_SYSTEM__TEST_DATA_ADAPTOR_HPP

#include <syneight/base/unittest/env/test_data.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Data_Source;

class Test_Data_Adaptor :
	public Test_Data
{
public:
	virtual ~Test_Data_Adaptor();
	virtual void attach(Test_Data_Source * const backend) =0;
	virtual Test_Data_Source* backend() const=0;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
