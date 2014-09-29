/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/invalid_category_name.cpp
 *
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: invalid_category_name.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/invalid_category_name.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

Invalid_Category_Name::~Invalid_Category_Name() SYNEIGHT__EXCEPTION_NO_THROW
{
}

Invalid_Category_Name::Invalid_Category_Name(Source_Location const source_location,
					     ::std::string const & name)
    : Super(source_location),
      m_name(name)
{
}

Invalid_Category_Name::Invalid_Category_Name(Self const & other)
    : Super(other),
      m_name(other.m_name)
{
}

char const * Invalid_Category_Name::class_name() const
{
    return "Invalid_Category_Name";
}

char const * Invalid_Category_Name::plain_what() const
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
