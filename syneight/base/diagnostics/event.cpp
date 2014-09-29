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
 * @version $Id: event.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/event.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

Event::Event(Category_Handle const * const category_handle,
	     Level_t const level,
	     Type_t const type,
	     ::std::string const & what,
	     int const nr_what,
	     char const * const base_file_name,
	     char const * const file_name,
	     int const line)
    : m_category_handle(category_handle),
      m_level(level),
      m_type(type),
      m_str_what(what),
      m_nr_what(nr_what),
      m_source_location(file_name,base_file_name,line)
{
}

Event::Event(Category_Handle const * const category_handle,
	     Level_t const level,
	     Type_t const type,
	     ::std::string const & what,
	     int const nr_what,
	     Source_Location const & source_location)
    : m_category_handle(category_handle),
      m_level(level),
      m_type(type),
      m_str_what(what),
      m_nr_what(nr_what),
      m_source_location(source_location)
{
}


Event::Event(Self const & other)
    : m_category_handle(other.m_category_handle),
      m_level(other.m_level),
      m_type(other.m_type),
      m_str_what(other.m_str_what),
      m_nr_what(other.m_nr_what),
      m_source_location(other.m_source_location)
{
}

Event & Event::operator=(Self const & other)
{
    m_category_handle=other.m_category_handle;
    m_level=other.m_level;
    m_type=other.m_type;
    m_str_what=other.m_str_what;
    m_nr_what=other.m_nr_what;
    m_source_location=other.m_source_location;
    return *this;
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
