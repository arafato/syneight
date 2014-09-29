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
 * @version $Id: unittest_error.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TEST_ERROR_HPP
#define SYNEIGHT__BASE__UNITTEST__TEST_ERROR_HPP

#include <syneight/base/unittest/exception/unittest_exception.hpp>
#include <syneight/base/exception/standard_exception_aspect.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Unittest_Error
  : public Standard_Exception_Aspect<Unittest_Exception>
{
public:
	virtual ~Unittest_Error() SYNEIGHT__EXCEPTION_NO_THROW;
	Unittest_Error(Source_Location const & source_location, 
		   ::std::string const & what); 
	virtual char const * plain_what() const;
	virtual char const * class_name() const;
private:
	::std::string m_what;
	mutable ::std::string m_buffer;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
