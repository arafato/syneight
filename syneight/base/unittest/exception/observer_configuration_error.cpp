/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/exception/observer_configuration_error.cpp
 *
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: observer_configuration_error.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/exception/observer_configuration_error.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Observer_Configuration_Error::Observer_Configuration_Error(Source_Location const & source_location,
														   ::std::string const & detail)
	: Super(source_location),
	  m_detail(detail)
{
}
Observer_Configuration_Error::Observer_Configuration_Error(Self const & other)
	: Super(other),
	  m_detail(other.m_detail)
{
}
Observer_Configuration_Error::~Observer_Configuration_Error() SYNEIGHT__EXCEPTION_NO_THROW
{
}

::std::string const & Observer_Configuration_Error::detail() const
{
	return m_detail;
}

char const * Observer_Configuration_Error::plain_what() const
{
	m_buffer  = class_name();
	m_buffer += ": ";
	m_buffer += m_detail;
	m_buffer += " ";
	
	return m_buffer.c_str();
}

char const * Observer_Configuration_Error::class_name() const
{
	return "Observer_Configuration_Error";
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
