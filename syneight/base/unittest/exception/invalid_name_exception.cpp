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
 * @version $Id: invalid_name_exception.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/exception/invalid_name_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Invalid_Name_Exception::Invalid_Name_Exception(Source_Location const & source,
											  ::std::string const & given_name) 
	: Standard_Unittest_System_Exception(source)
{
	m_given_name = given_name;
}
Invalid_Name_Exception::~Invalid_Name_Exception() SYNEIGHT__EXCEPTION_NO_THROW
{

}

char const * Invalid_Name_Exception::plain_what() const 
{
	m_buffer=class_name()+ ::std::string(": '");
	m_buffer += m_given_name; 
	m_buffer += "' not a valid name for a Testable (Already used by parent container?)";
	return m_buffer.c_str();
};

char const * Invalid_Name_Exception::class_name() const 
{
	return "Invalid_Name_Exception";
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
