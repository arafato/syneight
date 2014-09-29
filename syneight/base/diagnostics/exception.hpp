/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/exception.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Exception
 *
 * TODO: Long description.
 *
 * @note CLEAN
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__EXCEPTION_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__EXCEPTION_HPP

#include <syneight/base/exception/exception.hpp>
#include <syneight/base/diagnostics/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

/**
 * @class Exception
 *
 * @brief The base class for exceptions within ::syneight::diagnostics
 *
 * @nosubgrouping
 */

class Exception
    : public ::syneight::Exception
{
public:
    virtual ~Exception() SYNEIGHT__EXCEPTION_NO_THROW;
};

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
