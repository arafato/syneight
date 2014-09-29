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
 * @version $Id: standard_exception_aspect.impl.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__STANDARD_EXCEPTION_ASPECT_IMPL_HPP
#define SYNEIGHT__BASE__EXCEPTION__STANDARD_EXCEPTION_ASPECT_IMPL_HPP

#include <syneight/base/exception/standard_exception_aspect.hpp>

#include <syneight/base/util/string.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

template<typename BASE>
Standard_Exception_Aspect<BASE>::~Standard_Exception_Aspect() SYNEIGHT__EXCEPTION_NO_THROW
{
}

template<typename BASE>
char const * Standard_Exception_Aspect<BASE>::what() const SYNEIGHT__EXCEPTION_NO_THROW
{
    m_buffer= ::syneight::baseutil::to_string(plain_what()," at ",m_source_location);
    return m_buffer.c_str();
}


template<typename BASE>
Source_Location const & Standard_Exception_Aspect<BASE>::source_location() const
{
    return m_source_location;
}

// Using the Source_Location as parameter is a bit inefficient --
// since it must be constructed and is copied afterwards. However, it
// is easier to read and should be executed seldomly. Thus we prefer
// the more readable variant.
template<typename BASE>
Standard_Exception_Aspect<BASE>::Standard_Exception_Aspect(Source_Location const & source_location)
    : m_source_location(source_location)
{
}

template<typename BASE>
Standard_Exception_Aspect<BASE>::Standard_Exception_Aspect(Self const & other)
    : m_source_location(other.m_source_location)
{
}


SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
