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
 * @version $Id: test_data_source.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__DIAGNOSTICS__DETAIL__TEST_DATA_SOURCE_HPP
#define SYNEIGHT__DIAGNOSTICS__DETAIL__TEST_DATA_SOURCE_HPP

#include <syneight/base/diagnostics/namespace.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;


class Test_Data_Source 
{
public:
	virtual ~Test_Data_Source();

	virtual bool is_initialized() const=0;
	virtual bool exists_entry(::std::string const & id) const =0;
	virtual ::std::string const & get_entry(::std::string const & id) const =0;
	virtual void set_entry(::std::string const & id, ::std::string const & value) =0;
};

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
