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
 * @version $Id: standard_low_level_exception.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/exception/standard_low_level_exception.hpp>
#include <syneight/base/exception/standard_exception_aspect.impl.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

Standard_Low_Level_Exception::~Standard_Low_Level_Exception() SYNEIGHT__EXCEPTION_NO_THROW
{
}

Standard_Low_Level_Exception::Standard_Low_Level_Exception(Source_Location const & source_location,
							   ::std::string const & plain_what)
    : Super(source_location),
      m_plain_what(plain_what)
{
}

Standard_Low_Level_Exception::Standard_Low_Level_Exception(Self const & other)
    : Super(other),
      m_plain_what(other.m_plain_what)
{
}

char const * Standard_Low_Level_Exception::plain_what() const
{
    m_buffer=class_name();
    m_buffer+=": ";
    m_buffer+=m_plain_what;
    return m_buffer.c_str();
}

SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
