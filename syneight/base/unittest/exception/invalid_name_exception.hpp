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
 * @version $Id: invalid_name_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__INVALID_NAME_EXCEPTION_HPP
#define SYNEIGHT__BASE__UNITTEST__INVALID_NAME_EXCEPTION_HPP

#include <syneight/base/unittest/exception/standard_unittest_system_exception.hpp>

#include <string>
#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/**
 * @brief 
 *
 * @nosubgrouping
 */
class Invalid_Name_Exception 
	: public Standard_Unittest_System_Exception
{
public: 
	virtual ~Invalid_Name_Exception() SYNEIGHT__EXCEPTION_NO_THROW;
	Invalid_Name_Exception(Source_Location const & source_location, 
						   ::std::string const & given_name); 
	virtual char const * plain_what() const;
	virtual char const * class_name() const;
private: 
	::std::string m_given_name;
	mutable ::std::string m_buffer;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
