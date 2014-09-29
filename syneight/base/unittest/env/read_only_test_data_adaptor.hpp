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
 * @version $Id: read_only_test_data_adaptor.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo Document the code.
 */

#ifndef SYNEIGHT__DIAGNOSTICS__DETAIL__READ_ONLY_TEST_DATA_ADAPTOR_HPP
#define SYNEIGHT__DIAGNOSTICS__DETAIL__READ_ONLY_TEST_DATA_ADAPTOR_HPP

#include <syneight/diagnostics/env/test_data_adaptor.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGSNOTICS;

class Read_Only_Test_Data_Adaptor :
	public Test_Data_Adaptor
{
public:
	Read_Only_Test_Data_Adaptor();
	virtual ~Read_Only_Test_Data_Adaptor();

	virtual void attach(Test_Data_Source * const backend);	// attach TD-Source to test data. 
	virtual Test_Data_Source* backend() const;	

	virtual ::std::string const & get(::std::string const & id) const;
	virtual bool compare(::std::string const & id,::std::string const & data);
};


SYNEIGHT__END__NAMESPACE__DIAGSNOTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
