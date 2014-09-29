/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/observer_configuration_error.cpp
 *
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: observer_configuration_error.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/observer_configuration_error.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

Observer_Configuration_Error::~Observer_Configuration_Error() SYNEIGHT__EXCEPTION_NO_THROW
{
}

Observer_Configuration_Error::Observer_Configuration_Error(Source_Location const source_location,
							   ::std::string const & name)
    : Super(source_location),
      m_name(name)
{
}

Observer_Configuration_Error::Observer_Configuration_Error(Self const & other)
    : Super(other),
      m_name(other.m_name)
{
}

char const * Observer_Configuration_Error::class_name() const
{
    return "Observer_Configuration_Error";
}

char const * Observer_Configuration_Error::plain_what() const
{
    m_buffer = class_name();
    m_buffer += ": ";
    m_buffer += name();
    m_buffer += " ";
    
    return m_buffer.c_str();
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
