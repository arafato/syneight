/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/invalid_protocol.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: invalid_protocol.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Middle class @ref ::syneight::Invalid_Protocol.
 *        TODO: What is a middle class? Uwe.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__INVALID_PROTOCOL_HPP
#define SYNEIGHT__BASE__EXCEPTION__INVALID_PROTOCOL_HPP

#include <syneight/base/exception/standard_low_level_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Invalid_Protocol 
 *
 * @brief The exception to be used if a method is called in a
 * situation when the object is not ready. E.g., a method B is called
 * -- but method A must be called before.
 *
 * @nosubgrouping
 */
class Invalid_Protocol
    : public Standard_Low_Level_Exception
{
    typedef Invalid_Protocol Self;
    typedef Standard_Low_Level_Exception Super;
public:
    virtual ~Invalid_Protocol() SYNEIGHT__EXCEPTION_NO_THROW;
    Invalid_Protocol(Self const & other);
    Invalid_Protocol(Source_Location const & source_location,
		     ::std::string const & plain_what);
    virtual char const * class_name() const;
};

SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
