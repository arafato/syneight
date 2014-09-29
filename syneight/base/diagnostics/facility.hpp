/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/facility.hpp
 *
 * @author Oliver Arafat
 * @author Christian Schallhart
 * @author $Author: (local) $
 *
 * @version $Id: facility.hpp 1053M 2007-12-02 16:32:12Z (local) $
 *
 * @brief @ref ::syneight::diagnostics::Facility
 *
 * TODO: Long description.
 *
 * @note CLEAN
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__FACILITY_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__FACILITY_HPP

#include <syneight/base/diagnostics/level.hpp>
#include <syneight/base/diagnostics/type.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

class Source_Location;

SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

class Category_Handle;

/**
 * @class Facility
 *
 * @brief The Facility is used to log events. The
 * configuration of the <base/diagnostics> framework is accessible
 * through the @ref Management_Facility.
 *
 * A client of the Facility should not rely on the fact that
 * some event have been logged, i.e., a client should be completely
 * functional without sending any log messages.
 *
 * @note Possible expansion: add a log method which allows to specify
 * the complete @ref Event (including time, process and thread
 * id). This could be useful to integrate <base/diagnostics> into other
 * libraries.
 *
 * @note All calls to the Facility and the @ref
 * Logging_Management_Facility are mutexed
 *
 * @nosubgrouping
 */ 
class Facility
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Disable Instantiation
     * @{
     */ 
private:
    Facility();
    friend class To_Avoid_Compiler_Errors;
    // @}


    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Logging
     * @{
     */ 
public:
    /**
     * @brief Logs an event. The agruments of this call will be used
     * to build @ref Event (see the definition of this class for the
     * meaning of the different arguments of this call). The
     * constructed event will be processed as configured by @ref
     * Logging_Management_Facility.
     *
     * @note The time, process and thread-id of the @ref Event will be
     * determined implicitly.
     *
     * @note Logging is serialized, i.e., calls to log are mutexted
     * (actually with all calls to the Facility and the @ref
     * Logging_Management_Facility are mutexed).
     *
     * @throw never
     */ 
    static void log(Category_Handle * const category_handle,
		    Level_t const level,
		    Type_t const type,
		    ::std::string const & what,
		    int const nr_what,
		    char const * const base_file_name,
		    char const * const file_name,
		    int const line);

    /**
     * @brief Same as normal log -- but the last three arguments are
     * assembled to a @ref Source_Location.
     */ 
    static void log(Category_Handle * const category_handle,
		    Level_t const level,
		    Type_t const type,
		    ::std::string const & what,
		    int const nr_what,
		    Source_Location const & source_location);
    

    /**
     * @brief Logs an event to the panic log. The panic log is a last
     * resort -- it is used when the usual log method cannot be used
     * (i.e., within the log method) or when the backend of
     * <base/diagnostics> is suspicious to work incorrectly. Arguments
     * are identical to the usual log-call. The processing of panic
     * log events is configured by @ref Logging_Management_Facility.
     *
     * @note Logging is serialized, i.e., calls to log are mutexted
     * (actually with all calls to the Facility and the @ref
     * Logging_Management_Facility are mutexed).
     *
     * @throw never
     */ 
    static void panic_log(Category_Handle * const category_handle,
			  Level_t const level,
			  Type_t const type,
			  ::std::string const & what,
			  int const nr_what,
			  char const * const base_file_name,
			  char const * const file_name,
			  int const line);


    /**
     * @brief Same as normal panic_log -- but the last three arguments are
     * assembled to a @ref Source_Location
     */ 
    static void panic_log(Category_Handle * const category_handle,
			  Level_t const level,
			  Type_t const type,
			  ::std::string const & what,
			  int const nr_what,
			  Source_Location const & source_location);
    // @}
};

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
