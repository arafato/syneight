/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/standard_exception.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: standard_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Standard_Exception
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__STANDARD_EXCEPTION_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__STANDARD_EXCEPTION_HPP

#include <syneight/base/exception/standard_exception_aspect.hpp>
#include <syneight/base/diagnostics/exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

/**
 * @class Standard_Exception
 *
 * @brief Standard implemention of @ref Exception
 */
typedef ::syneight::Standard_Exception_Aspect<Exception>  Standard_Exception;


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
