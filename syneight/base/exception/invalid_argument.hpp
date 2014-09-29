/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/invalid_argument.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: invalid_argument.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Middle class @ref ::syneight::Invalid_Argument.
 *        TODO: What is a middle class? Uwe.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__INVALID_ARGUMENT_HPP
#define SYNEIGHT__BASE__EXCEPTION__INVALID_ARGUMENT_HPP

#include <syneight/base/exception/standard_low_level_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Invalid_Argument 
 *
 * @brief The exception to be used if an argument is invalid. Please
 * note that Invalid_Argument is a @ref Low_Level_Exception -- and
 * thus its use is restricted.
 *
 * @nosubgrouping
 */
class Invalid_Argument
    : public Standard_Low_Level_Exception
{
    typedef Invalid_Argument Self;
    typedef Standard_Low_Level_Exception Super;
public:
    virtual ~Invalid_Argument() SYNEIGHT__EXCEPTION_NO_THROW;
    Invalid_Argument(Self const & other);
    Invalid_Argument(Source_Location const & source_location,
		     ::std::string const & plain_what);
    virtual char const * class_name() const;
};

SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
