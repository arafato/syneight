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
 * @version $Id: memory_monitoring_facility.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/memory_monitoring/memory_monitoring_facility.hpp>

#include <syneight/base/memory_monitoring/kernel/memory_monitoring_facility_implementation.hpp>
#include <syneight/base/diagnostics/kernel/diagnostics_guard.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;


void Memory_Monitoring_Facility::register_allocation(void * const block, ::std::size_t const len)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	register_allocation(block,len);
    SYNEIGHT__DIAGNOSTICS_END;
}

bool Memory_Monitoring_Facility::register_deallocation(void * const block)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	register_deallocation(block);
    SYNEIGHT__DIAGNOSTICS_END;
}

void Memory_Monitoring_Facility::reset()
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	reset();
    SYNEIGHT__DIAGNOSTICS_END;
}

void Memory_Monitoring_Facility::analysis_on(bool const logging)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	analysis_on(logging);
    SYNEIGHT__DIAGNOSTICS_END;
}

void Memory_Monitoring_Facility::analysis_off(bool const logging)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	analysis_off(logging);
    SYNEIGHT__DIAGNOSTICS_END;
}

Tick_t Memory_Monitoring_Facility::creation_tick()
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	creation_tick();
    SYNEIGHT__DIAGNOSTICS_END;
}


void Memory_Monitoring_Facility::balance(Tick_t const start_from,
					 ::std::size_t & size,
					 Tick_t & number)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	balance(start_from,
		size,
		number);
    SYNEIGHT__DIAGNOSTICS_END;
}


void Memory_Monitoring_Facility::balance(::std::size_t & size,
	     Tick_t & number)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	balance(size,number);
    SYNEIGHT__DIAGNOSTICS_END;
}


Tick_t* Memory_Monitoring_Facility::unallocated_blocks(Tick_t const start_from,
						       Tick_t * const b,
						       Tick_t * const e)
{
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    return Facility_Implementation::get_instance().
	unallocated_blocks(start_from,b,e);
    SYNEIGHT__DIAGNOSTICS_END;
}



SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
