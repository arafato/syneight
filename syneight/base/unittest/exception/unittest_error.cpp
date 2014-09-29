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
 * @version $Id: unittest_error.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/exception/unittest_error.hpp>

#include <syneight/base/exception/standard_exception_aspect.impl.hpp>

template class ::syneight::Standard_Exception_Aspect< ::syneight::unittest::Unittest_Exception>;

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Unittest_Error::Unittest_Error(Source_Location const & source_location,
							   ::std::string const & what) 
	: Standard_Exception_Aspect<Unittest_Exception>(source_location), 
	  m_what(what)
{
}

Unittest_Error::~Unittest_Error() SYNEIGHT__EXCEPTION_NO_THROW
{
}

char const * Unittest_Error::plain_what() const
{
	m_buffer=class_name()+ ::std::string(": '");
	m_buffer+=m_what;
	m_buffer+='\'';
	return m_buffer.c_str();
}

char const * Unittest_Error::class_name() const
{
	return "Unittest_Error";
}


SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
