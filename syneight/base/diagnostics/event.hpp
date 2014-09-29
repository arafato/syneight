/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/event.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: event.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Event
 *
 * TODO: Long description.
 *
 * @note CLEAN
 *
 * @todo Add test. Fix the thread/process issue.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__EVENT_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__EVENT_HPP

#include <syneight/base/exception/source_location.hpp>

#include <syneight/base/diagnostics/level.hpp>
#include <syneight/base/diagnostics/type.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

class Category_Handle;

/**
 * @class Event
 *
 * @brief For each call to @ref Logging_Facility::log an Event is
 * created. This event is then given to each registered @ref
 * Observer. This class is record-class, i.e., is a container for its
 * fields.
 *
 * None of the methods throws.
 *
 * @todo What about time? What about process and thread?
 *
 * @nosubgrouping
 */ 
class Event
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Types
     * @{
     */
private:
    typedef Event Self;
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Creation/Destruction
     * @{
     */
public:
    Event(Category_Handle const * const category_handle,
	  Level_t const level,
	  Type_t const type,
	  ::std::string const & what,
	  int const nr_what,
	  char const * const base_file_name,
	  char const * const file_name,
	  int const line);
    Event(Category_Handle const * const category_handle,
	  Level_t const level,
	  Type_t const type,
	  ::std::string const & what,
	  int const nr_what,
	  Source_Location const & source_location);
    Event(Self const & other);
    Event & operator=(Self const & other);
    inline ~Event();
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Access
     * @{
     */
public:
    inline Category_Handle const * category_handle() const;
    inline Level_t level() const;
    inline Type_t type() const;
    inline ::std::string const & str_what() const;
    inline int nr_what() const;
    inline Source_Location const & source_location() const;
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name State
     * @{
     */
private:
    Category_Handle const * m_category_handle;
    Level_t m_level;
    Type_t m_type;
    ::std::string m_str_what;
    int m_nr_what;
    Source_Location m_source_location;
    // @}
};


Event::~Event()
{
}

Category_Handle const * Event::category_handle() const
{
    return m_category_handle;
}

Level_t Event::level() const 
{
    return m_level;
}

Type_t Event::type() const
{
    return m_type;
}

::std::string const & Event::str_what() const
{
    return m_str_what;
}

int Event::nr_what() const
{
    return m_nr_what;
}

Source_Location const & Event::source_location() const
{
    return m_source_location;
}



SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
