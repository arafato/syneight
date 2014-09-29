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
 * @version $Id: memory_monitoring_facility.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__DIAGNOSTICS__MEMORY_MONITORING_FACILITY_HPP
#define SYNEIGHT__DIAGNOSTICS__MEMORY_MONITORING_FACILITY_HPP

#include <syneight/base/memory_monitoring/tick.hpp>

#include <cstdlib> // for ::std::size_t

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;

class Memory_Monitoring_Facility
{
public:
    /**
     * @brief register an allocation-call
     */
    static void register_allocation(void * const block, ::std::size_t const len);

    /**
     * @brief register a deallocation-call. Returns true if the block
     * should be deallocated. It returns false, if it does not know
     * the block, thus it could be a double-deallocation.
     */
    static bool register_deallocation(void * const block);

    /**
     * @brief reset the complete database
     */
    static void reset();

    /**
     * @brief switch on analysis -- the register calls are ignored
     * until the analysis is switched on. Afterwards, all calls are

     * registered until analysis_off is called. 
     *
     * @a logging indicates whether the allocations/deallocations
     * should be reflected in the log. Multiple calls to analysis_on
     * are allowed, a corresponding counter is increased -- a
     * corresponding number of analysis_off calls is required to
     * switch off the analysis.
     */
    static void analysis_on(bool const logging);

    /**
     * @brief switch off analysis -- the converse to analysis_on. The
     * calls must be symetric to analysis_on (in terms of @a logging
     * and their number).
     */
    static void analysis_off(bool const logging);

    /**
     * @brief each registered allocation is associated with a
     * creation_tick. This methods return the current creation_tick
     * which allows to filter the database on currently allocated
     * blocks.
     */
    static Tick_t creation_tick();

    /**
     * @brief sets @a size to the number of bytes allocated after the
     * creation_tick @a start_from. @a number is the corresponding
     * number of blocks.
     */
    static void balance(Tick_t const start_from,
			::std::size_t & size,
			Tick_t & number);

    /**
     * @brief sets @a size to the total number of bytes allocated
     * (precisely: returns the sum over all registered blocks). @a
     * number is corresponding number of blocks.
     */
    static void balance(::std::size_t & size,
			Tick_t & number);

    
    /**
     * @brief fills the range [@a b, @a e) with the ticks of
     * unallocated blocks. If there are less than (@a e - @a b), then
     * only the first n elements are filled. If n elements are
     * written, then the procedure returns @a b + n.
     */
    static Tick_t* unallocated_blocks(Tick_t const start_from,
				      Tick_t * const b,
				      Tick_t * const e);

};

SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
