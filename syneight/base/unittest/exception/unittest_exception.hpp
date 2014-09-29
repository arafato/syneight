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
 * @version $Id: unittest_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__UNITTEST_EXCEPTION_HPP
#define SYNEIGHT__BASE__UNITTEST__UNITTEST_EXCEPTION_HPP

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/exception/exception.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/**
 * @class Unittest_Exception
 *
 * @brief The interface to all exceptions of the unittest
 * environment. It has two derived classes: First, there is @ref
 * Unittest_Error which represents an actual error of a test case. Second,
 * there is @ref Unittest_System_Exception. If thrown, some fault
 * condition internally to unittest has occurred.
 *
 * @nosubgrouping
 */

class Unittest_Exception 
	: public Exception 
{
public:
	virtual ~Unittest_Exception() SYNEIGHT__EXCEPTION_NO_THROW;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
