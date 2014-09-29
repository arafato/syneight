/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/log_sink.cpp
 *
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: log_sink.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note M1
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/log_sink.hpp>

#include <syneight/base/diagnostics/invalid_log_sink_handle_name.hpp>
#include <syneight/base/diagnostics/invalid_log_sink_name.hpp>
#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>
#include <syneight/base/diagnostics/internal/log_sink_handle.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

/**
 * @class Log_Sink_Manager
 *
 * @brief Stores all through a config file configured @ref Log_Sink
 * objects.
 *
 * Log_Sink_Manager is used internally by @ref Log_Sink and holds
 * all ever configured Log_Sinks in a map of type @ref Log_Sink_Map_t.
 *
 * It consists of two patterns. A Singelton and a Flyweight.
 * Only Log Sinks that have an association (both names are identical) with a 
 * @ref Log_Sink_Handle object can be created. In other words, you can't create a 
 * Log_Sink on the fly that wasn't preconfigured before and thus hasn't an entry 
 * in neither the Log_Sink_Manager nor the Facility_Implementation. 
 * That is why it is not exactly a Flyweight pattern.
 *
 * @nosubgrouping
 */

class Log_Sink_Manager
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Singelton
     * @{
     */
private:
    typedef Log_Sink_Manager Self;
    friend class To_Avoid_Compiler_Errors;
    static Self * m_instance;

    Log_Sink_Manager();
    ~Log_Sink_Manager();
    Log_Sink_Manager(Self const & other);
    Self & operator=(Self const & other);
public:
    inline static Self & instance();
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Flyweight, almost: We have a preconfigured set of Log_Sinks 
     * @{
     */
public:
    /**
     * @brief Returns a @ref Log_Sink object with @a name if it is in the set
     * of preconfigured Log_Sinks.
     *
     * If a Log_Sink with @a name is not found in the Log_Sink_Manager's map, 
     * this method checks if a @ref Log_Sink_Handle with @name exists in 
     * @ref Facility_Implementation. If a valid handle is found a new Log_Sink object
     * will be created and added to the Log_Sink_Manager. 
     *
     * @throw Invalid_Log_Sink_Name
     */ 
    Log_Sink & log_sink(::std::string const & name);
private:
    typedef ::std::map < ::std::string, Log_Sink* > Log_Sink_Map_t;
    Log_Sink_Map_t m_log_sink_map;
    // @}
};

Log_Sink_Manager * Log_Sink_Manager::m_instance = NULL;


Log_Sink_Manager::Log_Sink_Manager()
{
}


Log_Sink_Manager & Log_Sink_Manager::instance()
{
    if (m_instance == NULL)
	m_instance = new Self;
    return *m_instance;
}

Log_Sink & Log_Sink_Manager::log_sink(::std::string const & name)
{
    Log_Sink_Map_t::const_iterator const iter(m_log_sink_map.find(name));
    if (iter == m_log_sink_map.end()) {
	try {
	    Log_Sink_Handle * const handle(Facility_Implementation::instance().log_sink(name));
	    // throws only above
	    return *(m_log_sink_map[name] = new Log_Sink(handle));
	} 
	catch(Invalid_Log_Sink_Handle_Name & e) {
	    throw Invalid_Log_Sink_Name(SYNEIGHT__SOURCE_LOCATION,
					::std::string("'" + name + "' is not a registered Log_Sink object!"));
	}
    }
    return *(iter->second);
}

SYNEIGHT__END__NAMESPACE__INTERNAL;

////////////////////////////////////////////////////////////////////////////////

Log_Sink::Log_Sink(Log_Sink_Handle * const handle)
    : m_handle(handle)
{
}

Log_Sink & Log_Sink::instance(::std::string const & name)
{
    return (Log_Sink_Manager::instance().log_sink(name));
}

::std::string const & Log_Sink::name() const
{
    return (m_handle->name());
}

Facility_Implementation::Log_Sink_Names_t const & Log_Sink::names()
{
    return (Facility_Implementation::instance().log_sink_names());
}

Log_Sink::~Log_Sink()
{
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
