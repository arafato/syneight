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
 * @version $Id: filter_test_data.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__UNITTEST__ENV__FILTER_TEST_DATA_HPP
#define SYNEIGHT__UNITTEST__ENV__FILTER_TEST_DATA_HPP

#include <syneight/base/unittest/env/test_data.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Filter_Test_Data :
	public Test_Data
{
public:
	Filter_Test_Data();
	virtual ~Filter_Test_Data();

	void attach(::std::string const & prefix, Test_Data * const backend);
	inline Test_Data * backend() const { return m_backend; }
	inline ::std::string const & prefix() const { return m_prefix; }

	virtual ::std::string const & get(::std::string const & id) const;
	virtual bool compare(::std::string const & id,::std::string const & data);

private:
	::std::string m_prefix;
	Test_Data * m_backend;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
