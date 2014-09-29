/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/memory_monitoring/memory_operators.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: memory_operators.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief The standard new/delete operators for memory monitoring.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__MEMORY_MONITORING__MEMORY_OPERATORS_HPP
#define SYNEIGHT__BASE__MEMORY_MONITORING__MEMORY_OPERATORS_HPP

#include <syneight/diagsnotics/memory_monitoring_facility.hpp>

#include <cstdlib>     // for ::std::size_t
#include <new>

void* operator new(::std::size_t const len) 
    throw(::std::bad_alloc)
{ 
    void* const result(::std::malloc(len));
    ::syneight::memory_monitoring::Memory_Monitoring_Facility::register_allocation(result,len);
    return result; 
}

void operator delete(void * const p,::std::size_t const len) 
{ 
    if(p==NULL) return;
    if(::syneight::memory_monitoring::Memory_Monitoring_Facility::register_deallocation(p))
	::std::free(p); 
}
void operator delete(void * const p) 
    throw()
{ 
    if(p==NULL) return;
    if(::syneight::memory_monitoring::Memory_Monitoring_Facility::register_deallocation(p))
	::std::free(p); 
}

void* operator new[](::std::size_t const len) 
    throw(::std::bad_alloc)
{ 
    void* const result(::std::malloc(len));
    ::syneight::memory_monitoring::Memory_Monitoring_Facility::register_allocation(result,len);
    return result; 
}
void operator delete[](void * const p,::std::size_t const len) 
{ 
    if(p==NULL) return;
    if(::syneight::memory_monitoring::Memory_Monitoring_Facility::register_deallocation(p))
	::std::free(p); 
}
void operator delete[](void * const p) 
    throw()
{ 
    if(p==NULL) return;
    if(::syneight::memory_monitoring::Memory_Monitoring_Facility::register_deallocation(p))
	::std::free(p); 
}


#endif
// vim:ts=4:sw=4
