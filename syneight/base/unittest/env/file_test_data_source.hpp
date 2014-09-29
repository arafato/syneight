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
 * @version $Id: file_test_data_source.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__DIAGNOSTICS__DETAIL__FILE_TEST_DATA_SOURCE_HPP
#define SYNEIGHT__DIAGNOSTICS__DETAIL__FILE_TEST_DATA_SOURCE_HPP

#include <syneight/base/unittest/env/test_data_source.hpp>

#include <map>
#include <string>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

class File_Test_Data_Source :
	public Test_Data_Source
{
private:
	typedef ::std::map< ::std::string, ::std::string> Data_t;
	typedef File_Test_Data_Source Self;
private:
	File_Test_Data_Source(Self const &);
	Self & operator=(Self const &);
public:
	virtual ~File_Test_Data_Source();
	File_Test_Data_Source();
	void init(::std::string const & file_name);
	void load(::std::string const & file_name);
	void save(::std::string const & file_name);
	bool is_modified() const;
	::std::string const & file_name() const;
public:
	virtual bool is_initialized() const;
	virtual bool exists_entry(::std::string const & id) const;
	virtual ::std::string const & get_entry(::std::string const & id) const;
	virtual void set_entry(::std::string const & id, ::std::string const & value);
};


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
