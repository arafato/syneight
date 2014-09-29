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
 * @version $Id: memory_monitoring_facility_implementation.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/memory_monitoring/kernel/memory_monitoring_facility_implementation.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;

Facility_Implementation * Facility_Implementation::mptr_instance=NULL;


void Facility_Implementation::register_allocation(void * const block, ::std::size_t const len)
{
    // analysis switch
    if(m_analysis_counter > 0)
	{
	    m_memory_map[block] = ::std::make_pair(m_ticks, len);
	    m_ticks++;
	    if(m_logging_counter_true > m_logging_counter_false)
		//logging register allocation (should be done with log when implemented!)
		::std::cout << "Register allocation!" << ::std::endl;
	}
}

bool Facility_Implementation::register_deallocation(void * const block)
{
    // analysis switch
    if(m_analysis_counter > 0) {
	Memory_Map_t::iterator const iter(m_memory_map.find(block));
	if(iter != m_memory_map.end() ) { // block was found
	    m_memory_map.erase(iter);
	    --m_ticks;
	    if(m_logging_counter_true > m_logging_counter_false)
		// logging register deallocation (should be done with log when implemented!)
		::std::cout << "Register deallocation!" << ::std::endl;
	    return true;
	}
	if(m_logging_counter_true > m_logging_counter_false)
	    ::std::cout << "Register deallocation failed!" << ::std::endl;
	return false;
    }
    return true;
}

void Facility_Implementation::reset()
{
    // reset the complete database
    m_memory_map.clear();
}

void Facility_Implementation::analysis_on(bool const logging)
{
    if(logging)
	m_logging_counter_true++;
    else
	m_logging_counter_false++;

    m_analysis_counter++;
   
}

void Facility_Implementation::analysis_off(bool const logging)
{
    if(m_analysis_counter > 0) 
	--m_analysis_counter;

    if(logging && m_logging_counter_true > 0)
	m_logging_counter_true--;

    if(!logging && m_logging_counter_false > 0)
	m_logging_counter_false--;
}

Tick_t Facility_Implementation::creation_tick()
{
    return m_ticks;
}


void Facility_Implementation::balance(Tick_t const start_from,
				      ::std::size_t & size,
				      Tick_t & number)
{
    Memory_Map_t::const_iterator iter(m_memory_map.begin());
   
    // Iterate through the map -- and look for entries with tick>number
    if( !(m_memory_map.size() < start_from) )
	{
	    for(; iter != m_memory_map.end(); iter++)
		{
		    // is tick > number?
		    if(iter->second.first > number && iter->second.first > start_from)
			size += iter->second.second;   
		}
	}
}


void Facility_Implementation::balance(::std::size_t & size,
				      Tick_t & number)
{
    Memory_Map_t::const_iterator iter(m_memory_map.begin());
    
    for(; iter != m_memory_map.end(); iter++)
	{
	    if(iter->second.first > number)  
		size += iter->second.second;	    
	}
}


Tick_t* Facility_Implementation::unallocated_blocks(Tick_t const start_from,
						    Tick_t * const b,
						    Tick_t * const e)
{
    /// @todo

   return new Tick_t();
}



SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
