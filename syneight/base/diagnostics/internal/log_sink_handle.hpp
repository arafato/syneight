/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file TODO
 *
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: log_sink_handle.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__INTERNAL__LOG_SINK_HANDLE
#define SYNEIGHT__BASE__DIAGNOSTICS__INTERNAL__LOG_SINK_HANDLE

#include <syneight/base/diagnostics/namespace.hpp>

#include <log4cpp/Appender.hh>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;


/**
 * @class Log_Sink_Handle
 *
 * @brief Log_Sink_Handle is the place where the log4cpp
 * component Appender is actually stored with an identifying name. 
 * This class is a record this components.
 *
 * @todo KILL LAYOUT
 *
 * @nosubgrouping
 */
class Log_Sink_Handle
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Construction/Destruction
     * @{
     */
public:
    /**
     * @brief Creates a Log_Sink_Handle object from a a @a
     * appender and a @a layout object and @a name. The @a name of log
     * sink will be identical to the Appender's name.
     *
     * @throw never
     */
    Log_Sink_Handle(::log4cpp::Appender * const appender, 
		    ::std::string const & name);
    
    /**
     * @brief NOOP
     */ 
    ~Log_Sink_Handle();

private:
    typedef Log_Sink_Handle Self;
    /**
     * @brief DISABLED
     */ 
    Log_Sink_Handle(Self const & other);
    /**
     * @brief DISABLED
     */ 
    Self & operator=(Self const &);
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Field Access
     * @{
     */
public:
    /**
     * @brief Returns the name of the Log_Sink_Handle object
     * which is identical to the appender's name.
     *
     * @throw never
     */
    inline ::std::string const & name() const;
  
    /**
     * @brief Returns the log4cpp appender of the
     * Log_Sink_Handle object.
     *
     * @throw never
     */
    inline ::log4cpp::Appender & appender() const;
    // @}
    
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name State 
     * @{
     */
private:
    ::log4cpp::Appender * m_appender; 
    ::std::string m_name; 
    // @}
};

::log4cpp::Appender & Log_Sink_Handle::appender() const
{
    return *m_appender;
}

::std::string const & Log_Sink_Handle::name() const
{
    return m_name;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
