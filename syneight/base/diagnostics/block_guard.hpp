/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/block_guard.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: block_guard.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Block_Guard
 *
 * TODO: Long description.
 *
 * @note CLEAN
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__BLOCK_GUARD_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__BLOCK_GUARD_HPP

#include <syneight/base/diagnostics/type.hpp>
#include <syneight/base/diagnostics/level.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
class Category_Handle;

/**
 * @class Block_Guard
 *
 * @brief A Block_Guard is used to establish a logging context. More
 * specifically, a log message on entry and exit of the block is
 * generated. The Block_Guard is thread safe, i.e., each thread
 * maintains its own stack of nested blocks.
 *
 * Aside from logging entry and exit, it is possible to log the
 * entire, current stack trace (i.e., the currently logged blocks) by
 * calling log_stack_tracea.
 *
 * @nosubgrouping
 */
class Block_Guard
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Types
     * @{
     */
private:
    typedef Block_Guard Self;
    // @}
    
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Construction / Destruction
     * @{
     */
private:
    Block_Guard(Self const & other);
    Self & operator=(Self const & other);
public:
    /**
     * @brief The only way of construction. The arguments are
     * identical to the ones of @ref Logging_Facility::log -- with the
     * following exceptions: Two types (@a tyep_enter and @a
     * type_exit) are specified. They are used for generated an @ref
     * Event on entering/exiting the block. If flag @a bool is true,
     * the events are logged. Otherwise, only a stack entry
     * is generated.
     *
     * More specifically, the constructor generates an entry on the
     * thread-specific stack and logs an Event if @ref log is true.
     *
     * @throw never
     */ 
    Block_Guard(bool const log,
		Type_t const type_enter, 
		Type_t const type_exit,
		Level_t const level,
		::std::string const & str_what,
		int const nr_what,
		char const * const base_file_name,
		char const * const file_name,
		int const line,
		Category_Handle * const category_handle);

    /**
     * @brief Removes the topmost entry from the thread-specific stack
     * and logs an event with the exit type (if the flag log was
     * true).
     *
     * @throw never
     */ 
    ~Block_Guard();
    // @}

    
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Stack Global Operations
     * @{
     */
public:
    /**
     * @brief Returns the depth of the stack of the current thread.
     *
     * @throw never
     */ 
    static int stack_depth();

    /**
     * @brief Generates and logs an @ref Event of type @ref
     * STACK_TRACE_TYPE which contains the type enter events of all
     * stack frames (independently of their log flag). The stack trace
     * event has @a level and @a category_handle at the specified @ref
     * Source_Location. The nr_what field of the event is set to 0.
     *
     * @throw never
     */ 
    static void log_stack_trace(Level_t const level,
				char const * const base_file_name,
				char const * const file_name,
				int const line,
				Category_Handle * const category_handle);
    // @}
};

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
