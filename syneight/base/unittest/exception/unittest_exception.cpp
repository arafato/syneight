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
 * @version $Id: unittest_exception.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/exception/unittest_exception.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Unittest_Exception::~Unittest_Exception() SYNEIGHT__EXCEPTION_NO_THROW
{
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#if 0
Unittest_Exception::Unittest_Exception(Source_Location &source) 
	: m_source(source)
{
}



	virtual char const * plain_what() const
	{
	::std::string what;
	what = to_string();
	what += ": ";
	what += m_source.print();

	return what.c_str();
	}

	virtual Source_Location const & source_location() const
	{
	return m_source;
	}

	virtual char const * source_location_as_string() const
	{
	return m_source.print().c_str();
	}
  
private: 
	Source_Location m_source;
  
#endif
// vim:ts=4:sw=4
