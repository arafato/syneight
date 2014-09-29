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
 * @version $Id: syneight_pattern_layout.cpp 1055 2005-06-07 12:33:52Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/internal/syneight_pattern_layout.hpp>

#include <syneight/base/diagnostics/internal/level_priority.hpp>

#include <log4cpp/Priority.hh>
#include <log4cpp/NDC.hh>

#include <iomanip>
#include <ctime>
#include <cmath>

#ifdef LOG4CPP_HAVE_INT64_T
#ifdef LOG4CPP_HAVE_STDINT_H
#include <stdint.h>
#endif // LOG4CPP_HAVE_STDINT_H

#ifdef LOG4CPP_MISSING_INT64_OSTREAM_OP
/* workaround suggested at:
   http://support.microsoft.com/default.aspx?scid=kb;EN-US;q168440
*/

#include <stdio.h>
 
std::ostream& operator<<(std::ostream& os, int64_t i) {
    char buf[20];
    ::sprintf(buf,"%I64d", i);
    return os << buf;
}
#endif // LOG4CPP_MISSING_INT64_OSTREAM_OP
#endif // LOG4CPP_HAVE_INT64_T


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

struct StringLiteralComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    StringLiteralComponent(const std::string& literal) :
	_literal(literal) {
    }
    
    virtual void append(::std::ostringstream& out, ::log4cpp::LoggingEvent const & event) {
	out << _literal;
    }
    
private:
    ::std::string _literal;
};

struct CategoryNameComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    CategoryNameComponent(std::string specifier) {
	if (specifier == "") {
	    _precision = -1;
	} else {
#ifdef LOG4CPP_HAVE_SSTREAM 
	    std::istringstream s(specifier);
#else
	    std::istrstream s(specifier.c_str());
#endif
	    s >> _precision;
	}
    }

    virtual void append(::std::ostringstream& out, ::log4cpp::LoggingEvent const & event) {
	if (_precision == -1) {
	    out << event.categoryName;
	} else {
	    std::string::size_type begin = std::string::npos;
	    for(int i = 0; i < _precision; i++) {
		begin = event.categoryName.rfind('.', begin - 2);
		if (begin == std::string::npos) {
		    begin = 0;
		    break;
		}
		begin++;
	    }
	    out << event.categoryName.substr(begin);
	}
    }

private:
    int _precision;
};

struct MessageComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    virtual void append(::std::ostringstream& out,
			::log4cpp::LoggingEvent const & event) {
	out << event.message;
    }
};

struct NDCComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    virtual void append(::std::ostringstream& out,
			::log4cpp::LoggingEvent const & event) {
	out << event.ndc;
    }
};

struct PriorityComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    virtual void append(::std::ostringstream& out,
			::log4cpp::LoggingEvent const & event) {
	out << level_to_string(internal::priority_to_level(event.priority));
    }
};

struct ThreadNameComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    virtual void append(::std::ostringstream& out,
			::log4cpp::LoggingEvent const & event) {
	out << event.threadName;
    }
};

struct ProcessorTimeComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    virtual void append(::std::ostringstream& out,
			::log4cpp::LoggingEvent const & event) {
	out << ::clock();
    }
};

struct TimeStampComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    static const char* const FORMAT_ISO8601;
    static const char* const FORMAT_ABSOLUTE;
    static const char* const FORMAT_DATE;

    TimeStampComponent(::std::string timeFormat) {
	if ((timeFormat == "") || (timeFormat == "ISO8601")) {
	    timeFormat = FORMAT_ISO8601;
	} else if (timeFormat == "ABSOLUTE") {
	    timeFormat = FORMAT_ABSOLUTE;
	} else if (timeFormat == "DATE") {
	    timeFormat = FORMAT_DATE;
	}
	std::string::size_type pos = timeFormat.find("%l");
	if (pos == std::string::npos) {
	    _printMillis = false;
	    _timeFormat1 = timeFormat; 
	} else {
	    _printMillis = true;
	    _timeFormat1 = timeFormat.substr(0, pos);
	    _timeFormat2 = timeFormat.substr(pos + 2);
	}
    }

    virtual void append(std::ostringstream& out, ::log4cpp::LoggingEvent const & event) {
	struct tm *currentTime;
	time_t t = event.timeStamp.getSeconds();
	currentTime = std::localtime(&t);
	char formatted[100];
	std::string timeFormat;
	if (_printMillis) {
	    std::ostringstream formatStream;
	    formatStream << _timeFormat1 
			 << std::setw(3) << std::setfill('0')
			 << event.timeStamp.getMilliSeconds()
			 << _timeFormat2;
	    timeFormat = formatStream.str();
	} else {
	    timeFormat = _timeFormat1;
	}
	std::strftime(formatted, sizeof(formatted), timeFormat.c_str(), currentTime);
	out << formatted;
    }

private:
    std::string _timeFormat1;
    std::string _timeFormat2;
    bool _printMillis;
};

const char* const TimeStampComponent::FORMAT_ISO8601 = "%Y-%m-%d %H:%M:%S,%l";
const char* const TimeStampComponent::FORMAT_ABSOLUTE = "%H:%M:%S,%l";
const char* const TimeStampComponent::FORMAT_DATE = "%d %b %Y %H:%M:%S,%l";

struct SecondsSinceEpochComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    virtual void append(::std::ostringstream& out, ::log4cpp::LoggingEvent const & event) {
	out << event.timeStamp.getSeconds();
    }
};

struct MillisSinceEpochComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    virtual void append(std::ostringstream& out, ::log4cpp::LoggingEvent const & event) {
#ifdef LOG4CPP_HAVE_INT64_T
	int64_t t = event.timeStamp.getSeconds() -
	    ::log4cpp::TimeStamp::getStartTime().getSeconds();
	t *= 1000;
	t += event.timeStamp.getMilliSeconds() -
	    ::log4cpp::TimeStamp::getStartTime().getMilliSeconds();
            
	out << t;
#else
	double t = event.timeStamp.getSeconds() -
	    ::log4cpp::TimeStamp::getStartTime().getSeconds();
	t *= 1000;
	t += event.timeStamp.getMilliSeconds() -
	    ::log4cpp::TimeStamp::getStartTime().getMilliSeconds();
            
	out << std::setiosflags(std::ios::fixed)
	    << std::setprecision(0) << t;
#endif
    }
};

struct FormatModifierComponent 
    : public ::log4cpp::PatternLayout::PatternComponent 
{
    FormatModifierComponent(::log4cpp::PatternLayout::PatternComponent* component,
			    int minWidth, int maxWidth) :
	_component(component) , 
	_minWidth(std::abs(minWidth)),
	_maxWidth(maxWidth),
	_alignLeft(minWidth < 0) {
    }

    virtual ~FormatModifierComponent() {
	delete _component;
    }

    virtual void append(::std::ostringstream& out, ::log4cpp::LoggingEvent const & event) {
	std::ostringstream s;
	_component->append(s, event);
	std::string msg = s.str();
	if (_maxWidth > 0) {
	    msg.erase(_maxWidth);
	}
	int fillCount = _minWidth - msg.length();
	if (fillCount > 0) {
	    if (_alignLeft) {
		out << msg << std::string(fillCount, ' ');
	    } else {
		out << std::string(fillCount, ' ') << msg;
	    }
	} else {
	    out << msg;
	}
    }

private:
    ::log4cpp::PatternLayout::PatternComponent* _component;
    int _minWidth;
    int _maxWidth;
    bool _alignLeft;
};


const char* const Syneight_Pattern_Layout::DEFAULT_CONVERSION_PATTERN = "%m%n";
const char* const Syneight_Pattern_Layout::SIMPLE_CONVERSION_PATTERN = "%p - %m%n";
const char* const Syneight_Pattern_Layout::BASIC_CONVERSION_PATTERN = "%R %p %c %x: %m%n";
const char* const Syneight_Pattern_Layout::TTCC_CONVERSION_PATTERN = "%r [%t] %p %c %x - %m%n";


Syneight_Pattern_Layout::Syneight_Pattern_Layout() {
    try {
	setConversionPattern(DEFAULT_CONVERSION_PATTERN);
    } catch(::log4cpp::ConfigureFailure& e) {
	/// @todo explain? Why do we drop this exception silently?
    }
}

Syneight_Pattern_Layout::~Syneight_Pattern_Layout() {
    clearConversionPattern();
}

void Syneight_Pattern_Layout::clearConversionPattern() {
    for(ComponentVector::const_iterator i = _components.begin();
	i != _components.end(); ++i) {
	delete (*i);
    }
    _components.clear();
    _conversionPattern = "";
}

void Syneight_Pattern_Layout::setConversionPattern(::std::string const & conversionPattern) 
    throw(::log4cpp::ConfigureFailure) 
{
#ifdef LOG4CPP_HAVE_SSTREAM 
    std::istringstream conversionStream(conversionPattern);
#else
    std::istrstream conversionStream(conversionPattern.c_str());
#endif
    std::string literal;

    char ch;
    PatternLayout::PatternComponent* component = NULL;
    int minWidth = 0;
    int maxWidth = 0;
    clearConversionPattern();
    while (conversionStream.get(ch)) {
	if (ch == '%') {
	    // readPrefix;
	    {
		char ch2;
		conversionStream.get(ch2);
		if ((ch2 == '-') || ((ch2 >= '0') && (ch2 <= '9'))) {
		    conversionStream.putback(ch2);
		    conversionStream >> minWidth;
		    conversionStream.get(ch2);
		} 
		if (ch2 == '.') {
		    conversionStream >> maxWidth;
		} else {
		    conversionStream.putback(ch2);
		}                        
	    }
	    if (!conversionStream.get(ch)) {
		std::ostringstream msg;
		msg << "unterminated conversion specifier in '" << conversionPattern << "' at index " << conversionStream.tellg();
		throw ::log4cpp::ConfigureFailure(msg.str());
	    }
	    std::string specPostfix = "";
	    // read postfix
	    {
		char ch2;
		if (conversionStream.get(ch2)) {
		    if (ch2 == '{') {
			while(conversionStream.get(ch2) && (ch2 != '}'))
			    specPostfix += ch2;
		    } else {
			conversionStream.putback(ch2);
		    }
		}
	    }
	    switch (ch) {
                case '%':
                    literal += ch;
                    break;
                case 'm':
                    component = new MessageComponent();
                    break;
                case 'n':
                    {
                        std::ostringstream endline;
                        endline << std::endl;
                        literal += endline.str();
                    }
                    break;
                case 'c':
                    component = new CategoryNameComponent(specPostfix);
                    break;
                case 'd':
                    component = new TimeStampComponent(specPostfix);
                    break;
                case 'p':
                    component = new PriorityComponent();
                    break;
                case 'r':
                    component = new MillisSinceEpochComponent();
                    break;
                case 'R':
                    component = new SecondsSinceEpochComponent();
                    break;
                case 'u':
                    component = new ProcessorTimeComponent();
                    break;
                case 'x':
                    component = new NDCComponent();
                    break;
                default:
                    std::ostringstream msg;
                    msg << "unknown conversion specifier '" << ch << "' in '" << conversionPattern << "' at index " << conversionStream.tellg();
                    throw ::log4cpp::ConfigureFailure(msg.str());                    
	    }
	    if (component) {
		if (!literal.empty()) {
		    _components.push_back(new StringLiteralComponent(literal));
		    literal = "";
		}
		if ((minWidth != 0) || (maxWidth != 0)) {
		    component = new FormatModifierComponent(component, minWidth, maxWidth);
		    minWidth = maxWidth = 0;
		}
		_components.push_back(component);
		component = NULL;
	    }
	} else {
	    literal += ch;
	}
    }
    if (!literal.empty()) {
	_components.push_back(new StringLiteralComponent(literal));
    }

    _conversionPattern = conversionPattern;
}

::std::string Syneight_Pattern_Layout::getConversionPattern() const {
    return _conversionPattern;
}

::std::string Syneight_Pattern_Layout::format(::log4cpp::LoggingEvent const & event) {
    std::ostringstream message;
    
    for(ComponentVector::const_iterator i = _components.begin();
	i != _components.end(); ++i) {
	(*i)->append(message, event);
    }

    return message.str();
}


SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
