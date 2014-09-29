/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/low_level_exception.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: low_level_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Interface @ref ::syneight::Low_Level_Exception.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__LOW_LEVEL_EXCEPTION_HPP
#define SYNEIGHT__BASE__EXCEPTION__LOW_LEVEL_EXCEPTION_HPP

#include <syneight/base/exception/exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Low_Level_Exception 
 *
 * @brief Interface for all low-level exceptions, i.e., exceptions
 * which are used when no further context is knwon or when the error
 * situation is only checked for in @ref AUD_LEVEL and @ref DEB_LEVEL. 
 *
 * For example @ref Invalid_Argument is ued in all error situations,
 * where an invalid argument has been used. If the reason for the
 * invalid argument can occur at PRO_LEVEL you either @arg catch the
 * exeption an rethrow a more helpful exception at a level where you
 * have all the information for doing so, or @arg you will throw a
 * more helpful exception right away.
 *
 * A Low_Level_Exception always takes a string which is used for the
 * contents of @ref Exception::plain_what: class_name()+":
 * "+argument=plain_what. This string is given as consturctor argument
 * in all derviations.
 *
 * @nosubgrouping
 */
class Low_Level_Exception
    : public Exception
{
public:
    virtual ~Low_Level_Exception() SYNEIGHT__EXCEPTION_NO_THROW;
};

SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
