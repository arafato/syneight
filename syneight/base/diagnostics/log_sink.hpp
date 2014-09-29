/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/log_sink.hpp
 *
 * @author Christian Schallhart
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: log_sink.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Log_Sink
 *
 * TODO: Long description.
 *
 * @note M1 / DOCUMENTED
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__LOG_SINK
#define SYNEIGHT__BASE__DIAGNOSTICS__LOG_SINK

#include <syneight/base/diagnostics/namespace.hpp>

#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;
class Log_Sink_Manager;
SYNEIGHT__END__NAMESPACE__INTERNAL;

class Log_Sink_Handle;

/**
 * @class Log_Sink
 *
 * @brief A Log_Sink is an abstract logging target which is used by
 * the by the rest of the diagnostics framework to designate logging
 * targets such as syslogd, files, or stdout. 
 *
 * The only property known to the clients of the diagnostics
 * framework is the name of a Log_Sink.
 *
 * @todo 
 *
 * @nosubgrouping
 */
class Log_Sink
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Creation
     * @{
     */
private:
    typedef internal::Log_Sink_Manager Log_Sink_Manager;
    friend class Log_Sink_Manager;
    typedef Log_Sink Self;

    /**
     * @brief DISABLED
     */ 
    ~Log_Sink();
    /**
     * @brief DISABLED
     */ 
    Log_Sink();    
    /**
     * @brief DISABLED
     */ 
    Self & operator=(Self const & other);

    /**
     * @brief Constructs a new @ref Log_Sink object with
     * a pointer @a handle to @ref Log_Sink_Handle object.
     * 
     * @note The new @ref Log_Sink object will not be registred
     * in the Log_Sink_Map of @ref Log_Sink_Manager.
     *
     * @attention To be used only by the @ref Log_Sink_Manager
     *
     * @todo
     *
     * @throw
     */
    explicit Log_Sink(Log_Sink_Handle * const handle);       
public:
    /**
     * @brief Returns an instance of a Log_Sink object with @a name. 
     *
     * @pre @a name is element of names()
     *
     * @throw Invalid_Log_Sink_Name
     */
    static Log_Sink & instance(::std::string const & name);

    /**
     * @brief Returns an instance of a Log_Sink object with @a handle.
     *
     * @pre @a handle != NULL
     *
     * @pre [UNCHECKED] @a handle must valid, i.e., it must be the
     * result of a call to handle() and the configuration of the
     * log_sinks must not be altered ever since.
     *
     * @throw Invalid_Argument
     */
    static Log_Sink & instance(Log_Sink_Handle * const handle);
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Properties
     * @{
     */
public:
    /**
     * @brief Returns the name of the Log_Sink object. The name of a
     * Log_Sink is unique.
     *
     * @throw never
     */
    ::std::string const & name() const;


    /**
     * @brief Returns the handle of the Log_Sink.
     *
     * @throw never
     */ 
    inline Log_Sink_Handle * handle();

    /**
     * @brief Returns the handle of the Log_Sink.
     *
     * @throw never
     */ 
    inline Log_Sink_Handle const * handle() const;


    typedef ::std::vector< ::std::string> Log_Sink_Names_t;

    /**
     * @brief Returns all registered @ref Log_Sink objects as a vector
     * of ::std::string (@ref Log_Sink_Names_t).
     *
     * @note The registered Log_Sink objects are configured by the
     * @ref Management_Facility.
     *
     * @throw never
     */
    static Log_Sink_Names_t const & names();
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Log_Sink Insulated State
     * @{
     */
private:
    Log_Sink_Handle * m_handle;
    // @}
};


Log_Sink_Handle * Log_Sink::handle() 
{
    return m_handle;
}


Log_Sink_Handle const * Log_Sink::handle() const
{
    return m_handle;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
