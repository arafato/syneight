/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/management_facility.hpp
 *
 * @author Oliver Arafat
 * @author Christian Schallhart
 * @author $Author: (local) $
 *
 * @version $Id: management_facility.hpp 1053M 2007-12-02 16:32:48Z (local) $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGSNOTICS__MANAGEMENT_FACILITY_HPP
#define SYNEIGHT__BASE__DIAGSNOTICS__MANAGEMENT_FACILITY_HPP

#include <syneight/base/diagnostics/level.hpp>
#include <syneight/base/diagnostics/type.hpp>

#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

class Category_Handle;
class Observer;

/**
 * @class Management_Facility
 *
 * @brief The Management_Facility is used to configure the
 * logging process. Logging itself is done with the @ref
 * Facility.
 *
 * The Management_Facility is seperated from the Facility, since we
 * want to avoid to expose the management interface to components
 * which are only using the logging facilities. Note, that every
 * component outside syneight/base is used including the @ref Facility
 * -- thus keeping it minimal is crucial.
 *
 * @note If one of the methods throws, it will send a corresponding
 * log message throgh @ref Facility::panic_log.
 *
 * @nosubgrouping
 */
class Management_Facility
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Disable Instantiation
     * @{
     */
private:
    Management_Facility();
    friend class To_Avoid_Compiler_Errors;
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Initialization
     * @{
     */
public:
    /**
     * @brief
     *
     * @attention This method is not thread safe. It has be called
     * before spawning any thread
     * 
     */ 
    static void init();
    // @}


    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Access Category
     * @{
     */
public:
    /**
     * @brief KILL? returns the Category for @a name. If the Category for @a
     * name does not exist, it is created on the fly. In the latter
     * case it will have no specific configuration, i.e., it will 
     * have the same as its parent.
     *
     * Note that @a name has to follow a specific format. In
     * particular, @a name is formated as (::<NAME>)*|::, where <NAME>
     * can be any alpha-numerical string with underscores. Thus, "::"
     * (root), "::X", "::X", "::X::Y" are valid names. "", "::X::",
     * "::Y-X" are invalid.
     *
     * If called with "::X::Y", then the method returns the category
     * of name "Y", which is child of category "X", which is child of
     * the root category.
     *
     * @throw Invalid_Category_Name
     */ 
    static Category_Handle * category(::std::string const & name);
    
    /**
     * @brief KILL? returns a child category of @a root with @a name.
     *
     * Equivalent to calling category(<name of @a root> + "::" + @a
     * name).
     *
     * @throw Invalid_Category_Name
     * @throw Invalid_Argument
     */
    static Category_Handle * category(Category_Handle * const root,
				      ::std::string const & name);
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Configure Log_Sinks
     *
     * @brief Note that a Log_Sink is an abstract logging target,
     * i.e., something to log into. No property except the name of a
     * Log_Sink is programmatically accessible. The actual
     * configuration of Log_Sinks are loaded from a file before using
     * them. Thus, Log_Sink-Names should be standardized within a
     * code-base, i.e., there should be Log_Sinks such as "syslog",
     * "local_file" etc.
     *
     * @{
     */
public:
    typedef ::std::vector< ::std::string> Log_Sink_Names_t;

    /**
     * @brief Loads the config file @a name and configures 
     * categories and log sinks according to the configuration
     * file. The path to the config file may be included in @name.
     *
     * During the configuration a temporary file be created in
     * the /tmp directory. After configuration is completed it will
     * be deleted.
     *
     * @throw Configure_Failure
     */
    static void load_config(::std::string const & name);

    /**
     * @brief Returns the names as a vector of all configured @ref
     * Log_Sink objects available.
     *
     * @throw never 
     */
    static Log_Sink_Names_t const & log_sink_names();
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Configure Oberser
     * @{
     */
public:
    /**
     * @brief Registers an observer within the diagnostics framework,
     * i.e., any @Event generated by ::syneight::diagnostics in the
     * future will be sent to @a observer.
     *
     * @pre observer is registered already
     *
     * @throw Observer_Configuration_Error
     */ 
    static void register_observer(Observer & observer);

    /**
     * @brief Unregisters an observer within the diagnostics
     * framework, i.e., any @Event generated by ::syneight::diagnostics
     * in the future will not be sent to @a observer.
     *
     * @pre observer has been registered 
     *
     * @throw Observer_Configuration_Error
     */
    static void unregister_observer(Observer & observer);
    // @}
};

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
