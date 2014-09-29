/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/facility.cpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: facility.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Facility
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/facility.hpp>

#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>
#include <syneight/base/diagnostics/kernel/diagnostics_guard.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

void Facility::log(Category_Handle * const category_handle,
			   Level_t const level,
			   Type_t const type,
			   ::std::string const & what,
			   int const nr_what,
			   char const * const base_file_name,
			   char const * const file_name,
			   int const line)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Facility_Implementation::instance().
	log(category_handle,
	    level,
	    type,
	    what,
	    nr_what,
	    base_file_name,
	    file_name,
	    line);
    SYNEIGHT__DIAGNOSTICS_END;
}

void Facility::log(Category_Handle * const category_handle,
			   Level_t const level,
			   Type_t const type,
			   ::std::string const & what,
			   int const nr_what,
			   Source_Location const & source_location)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Facility_Implementation::instance().
	log(category_handle,
	    level,
	    type,
	    what,
	    nr_what,
	    source_location);
    SYNEIGHT__DIAGNOSTICS_END;
}


void Facility::panic_log(Category_Handle * const category_handle,
				 Level_t const level,
				 Type_t const type,
				 ::std::string const & what,
				 int const nr_what,
				 char const * const base_file_name,
				 char const * const file_name,
				 int const line)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Facility_Implementation::instance().
	panic_log(category_handle,
		  level,
		  type,
		  what,
		  nr_what,
		  base_file_name,
		  file_name,
		  line);
    SYNEIGHT__DIAGNOSTICS_END;
}

void Facility::panic_log(Category_Handle * const category_handle,
				 Level_t const level,
				 Type_t const type,
				 ::std::string const & what,
				 int const nr_what,
				 Source_Location const & source_location)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Facility_Implementation::instance().
	panic_log(category_handle,
		  level,
		  type,
		  what,
		  nr_what,
		  source_location);
    SYNEIGHT__DIAGNOSTICS_END;
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
