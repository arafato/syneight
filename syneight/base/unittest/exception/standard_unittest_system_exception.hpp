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
 * @version $Id: standard_unittest_system_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__STANDARD_UNITTEST_SYSTEM_EXCEPTION_HPP
#define SYNEIGHT__BASE__UNITTEST__STANDARD_UNITTEST_SYSTEM_EXCEPTION_HPP

#include <syneight/base/exception/standard_exception_aspect.hpp>
#include <syneight/base/unittest/exception/unittest_system_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/**
 * @class Standard_Unittest_System_Exception
 *
 * @brief Standard implemention of @ref Unittest_System_Exception
 */
typedef Standard_Exception_Aspect<Unittest_System_Exception>  Standard_Unittest_System_Exception;


SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
