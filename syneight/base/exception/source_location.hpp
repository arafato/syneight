/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/source_location.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: source_location.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Class @ref ::syneight::Source_Location,
 * macro @ref SYNEIGHT__SOURCE_LOCATION.
 *
 * TODO: Long description.
 *
 * @note This component is stable -- well, it has to be tested.
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__SOURCE_LOCATION_HPP
#define SYNEIGHT__BASE__EXCEPTION__SOURCE_LOCATION_HPP

#include <syneight/base/root/config.hpp>

#include <syneight/base/preprocessor/wrapper.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Source_Location
 *
 * @brief A source location is represented by a file, base_file and a
 * line number. This information is generated with the __FILE__ , @ref
 * SYNEIGHT__INTERNAL__PARAM__BASE_FILE , and the __LINE__ macros. To
 * generate a Source_Location which corresponds to the current
 * position, use @ref SYNEIGHT__SOURCE_LOCATION.
 *
 * Source_Location is a Recrod-Class, i.e., it is a compound for its
 * fields, not more, not less.
 *
 * @nosubgrouping
 */

class Source_Location
{
private:
    typedef Source_Location Self;
public:
    Source_Location(char const * const file,
		    char const * const base_file,
		    int const line);
    inline ~Source_Location();
    Source_Location(Self const & other);
    Self & operator=(Self const & other);
    bool operator==(Self const & other) const;
		
    inline char const * file() const;
    inline char const * base_file() const;
    inline int line() const;
private:
    char const * m_file;
    char const * m_base_file;
    int m_line;
};

Source_Location::~Source_Location()
{
}

char const * Source_Location::file() const
{
    return m_file;
}

char const * Source_Location::base_file() const
{
    return m_base_file;
}

int Source_Location::line() const
{
    return m_line;
}


::std::ostream & operator<<(::std::ostream & stream, 
			    Source_Location const & sl);


inline bool operator!=(Source_Location const & lhs,
		       Source_Location const & rhs)
{
    return !lhs.operator==(rhs);
}



SYNEIGHT__END__NAMESPACE__SYNEIGHT;


/**
 * @brief A @ref ::syneight::Source_Location object which represents
 * the current source location.
 */ 
#define SYNEIGHT__SOURCE_LOCATION ::syneight::Source_Location(__FILE__,SYNEIGHT__BASE_FILE,__LINE__)

#endif
 
// vim:ts=4:sw=4
