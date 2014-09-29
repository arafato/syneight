/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/standard_low_level_exception.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: standard_low_level_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Middle class @ref ::syneight::Standard_Low_Level_Exception.
 *        TODO: What is a middle class? Uwe.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__STANDARD_LOW_LEVEL_EXCEPTION_HPP
#define SYNEIGHT__BASE__EXCEPTION__STANDARD_LOW_LEVEL_EXCEPTION_HPP

#include <syneight/base/exception/low_level_exception.hpp>
#include <syneight/base/exception/standard_exception_aspect.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Standard_Low_Level_Exception 
 *
 * @brief A standard implementation for @ref Low_Level_Exception.
 *
 * @nosubgrouping
 */
class Standard_Low_Level_Exception
    : public Standard_Exception_Aspect<Low_Level_Exception>
{
    typedef Standard_Exception_Aspect<Low_Level_Exception> Super;
    typedef Standard_Low_Level_Exception Self;
public:
    virtual ~Standard_Low_Level_Exception() SYNEIGHT__EXCEPTION_NO_THROW;
    Standard_Low_Level_Exception(Self const & other);
protected:
    Standard_Low_Level_Exception(Source_Location const & source_location,
				 ::std::string const & plain_what);
public:
    virtual char const * plain_what() const;
private:
    ::std::string m_plain_what;
    mutable ::std::string m_buffer;
};

SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
