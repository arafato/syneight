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
 * @version $Id: syneight_pattern_layout.hpp 1055 2005-06-07 12:33:52Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__DETAIL__SYNEIGHT_PATTERN_LAYOUT_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__DETAIL__SYNEIGHT_PATTERN_LAYOUT_HPP

#include <syneight/base/diagnostics/namespace.hpp>

#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Configurator.hh> // for ConfigureFailure

#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;


/**
 * PatternLayout is a simple fixed format Layout implementation. 
 **/

/**
 * Syneight_Pattern_Layout is used internally and has the
 * same functionality as PatternLayout.
 * It is used to log with Level_t names. Therefore it has to be
 * in namespace log4cpp.
 **/
class Syneight_Pattern_Layout 
    : public ::log4cpp::PatternLayout 
{
public:
    virtual ~Syneight_Pattern_Layout();    
    Syneight_Pattern_Layout();

    static char const * const DEFAULT_CONVERSION_PATTERN;
    static char const * const SIMPLE_CONVERSION_PATTERN;
    static char const * const BASIC_CONVERSION_PATTERN;
    static char const * const TTCC_CONVERSION_PATTERN;
    
    // NOTE: All double percentage signs ('%%') followed by a character
    //       in the following comments should actually be a single char.
    //       The doubles are included so that doxygen will print them correctly.
    /**
     * Formats the LoggingEvent in the style set by
     * the setConversionPattern call. By default, set
     * to "%%m%%n"
     **/
    virtual std::string format(::log4cpp::LoggingEvent const & event);
    
    /**
     * Sets the format of log lines handled by this
     * PatternLayout. By default, set to "%%m%%n".<br>
     * Format characters are as follows:<br>
     * <li><b>%%%%</b> - a single percent sign</li>
     * <li><b>%%c</b> - the category</li>
     * <li><b>%%d</b> - the date\n
     *  Date format: The date format character may be followed by a date format 
     *  specifier enclosed between braces. For example, %%d{%%H:%%M:%%S,%%l} or %%d{%%d %%m %%Y %%H:%%M:%%S,%%l}.
     *  If no date format specifier is given then the following format is used:
     *  "Wed Jan 02 02:03:55 1980". The date format specifier admits the same syntax 
     *  as the ANSI C function strftime, with 1 addition. The addition is the specifier
     *  %%l for milliseconds, padded with zeros to make 3 digits.</li>
     * <li><b>%%m</b> - the message</li>
     * <li><b>%%n</b> - the platform specific line separator</li>
     * <li><b>%%p</b> - the priority</li>
     * <li><b>%%r</b> - milliseconds since this layout was created.</li>
     * <li><b>%%R</b> - seconds since Jan 1, 1970</li>
     * <li><b>%%u</b> - clock ticks since process start</li>
     * <li><b>%%x</b> - the NDC</li>
     * @param conversionPattern the conversion pattern
     * @exception ConfigureFailure if the pattern is invalid
     **/
    virtual void setConversionPattern(std::string const & conversionPattern) throw(::log4cpp::ConfigureFailure);
    
    virtual std::string getConversionPattern() const;
    
    virtual void clearConversionPattern();    
    
private:
    typedef std::vector<PatternComponent*> ComponentVector; 
    ComponentVector _components;
    
    std::string _conversionPattern;
};        


SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif 
// vim:ts=4:sw=4
