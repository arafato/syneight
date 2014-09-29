/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/exception/observer_configuration_error.hpp
 *
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: observer_configuration_error.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__OBSERVER_CONFIGURARION_ERROR_HPP
#define SYNEIGHT__BASE__UNITTEST__OBSERVER_CONFIGURATION_ERORR_HPP 

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/exception/standard_unittest_system_exception.hpp>

/**
 *	@todo Find better name, use diagnostics as pattern.
 */

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Observer_Configuration_Error
	: public Standard_Unittest_System_Exception
{
private: 
	typedef Observer_Configuration_Error Self;
	typedef Standard_Unittest_System_Exception Super;

public:
	Observer_Configuration_Error(Source_Location const & source_location,
								::std::string const & detail); 
	Observer_Configuration_Error(Self const & other);	
	~Observer_Configuration_Error() SYNEIGHT__EXCEPTION_NO_THROW;
	
	inline ::std::string const & detail() const; 
	virtual char const * plain_what() const;
	virtual char const * class_name() const;
	
private: 
	::std::string m_detail;
	mutable ::std::string m_buffer; 
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

//vim:ts=4:sw=4
