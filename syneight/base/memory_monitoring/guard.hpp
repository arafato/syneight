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
 * @version $Id: guard.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__MEMORY_MONITORING__MEMORY_MONITORING_GUARD_HPP
#define SYNEIGHT__BASE__MEMORY_MONITORING__MEMORY_MONITORING_GUARD_HPP

#include <syneight/base/diagnostics/level.hpp>
#include <syneight/base/memory_monitoring/tick.hpp>

#include <cstdlib>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
class Category_Handle;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;

SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;



/// @todo check thread consistency...

class Guard
{
private:
    typedef Guard Self;
    typedef ::syneight::diagnostics::Level_t Level_t;
    typedef ::syneight::diagnostics::Category_Handle Category_Handle;
private:
    Guard(Self const & other);
    Self & operator=(Self const & other);
public:
    Guard(bool const logging,
	  bool const balance, 
	  Level_t const level,
	  char const * const base_file_name,
	  char const * const file_name,
	  int const line,
	  Category_Handle * const category_handle);
    ~Guard();
    
    static void balance(::std::size_t & size,Tick_t & number);
    static void total_balance(::std::size_t & size,Tick_t & number);
    
    static void assert_balance(Level_t const level,
			       char const * const base_file_name,
			       char const * const file_name,
			       int const line,
			       Category_Handle * const category_handle);
    
    
    static void log_balance(Level_t const level,
			    char const * const base_file_name,
			    char const * const file_name,
			    int const line,
			    Category_Handle * const category_handle);
    
    static void log_total_balance(Level_t const level,
				  char const * const base_file_name,
				  char const * const file_name,
				  int const line,
				  Category_Handle * const category_handle);
};
    
SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
