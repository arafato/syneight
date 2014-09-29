/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/block_guard.cpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: block_guard.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Block_Guard
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Make thread-safe.
 */

#include <syneight/base/diagnostics/block_guard.hpp>

#include <syneight/base/diagnostics/kernel/diagnostics_guard.hpp>
#include <syneight/base/diagnostics/kernel/block_stack.hpp>
#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

Block_Guard::Block_Guard(bool const log,
			 Type_t const type_enter, 
			 Type_t const type_exit,
			 Level_t const level,
			 ::std::string const & str_what,
			 int const nr_what,
			 char const * const base_file_name,
			 char const * const file_name,
			 int const line,
			 Category_Handle * const category_handle)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Block_Stack::instance().push(log,
				 type_enter,
				 type_exit,
				 level,
				 str_what,
				 nr_what,
				 base_file_name,
				 file_name,
				 line,
				 category_handle);
    SYNEIGHT__DIAGNOSTICS_END;
}

Block_Guard::~Block_Guard()
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Block_Stack::instance().pop();
    SYNEIGHT__DIAGNOSTICS_END;
}


int Block_Guard::stack_depth()
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Block_Stack::instance().size();
    SYNEIGHT__DIAGNOSTICS_END;
}

void Block_Guard::log_stack_trace(Level_t const level,
				  char const * const base_file_name,
				  char const * const file_name,
				  int const line,
				  Category_Handle * const category_handle)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Facility_Implementation::instance().log
	  (category_handle,
	   level, 
	   STACK_TRACE_TYPE,
	   Block_Stack::instance().stack_trace(),
	   0,
	   base_file_name,
	   file_name,
	   line);
    SYNEIGHT__DIAGNOSTICS_END;
}



SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
