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
 * @version $Id: source_location.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/exception/source_location.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

Source_Location::Source_Location(char const * const file,
				 char const * const base_file,
				 int const line)
    : m_file(file),
      m_base_file(base_file),
      m_line(line)
{
}

Source_Location::Source_Location(Self const & other)
    : m_file(other.m_file),
      m_base_file(other.m_base_file),
      m_line(other.m_line)
{
}

Source_Location & Source_Location::operator=(Self const & other)
{
    m_file=other.m_file;
    m_base_file=other.m_base_file;
    m_line=other.m_line;
    return *this;
}

bool Source_Location::operator==(Self const & other) const
{
    return m_line==other.m_line
	&& m_file==other.m_file
	&& m_base_file==other.m_base_file;
}


::std::ostream & operator<<(::std::ostream & stream, Source_Location const & sl)
{
    return stream << "[ " << sl.file()
		  << " at " << sl.line()
		  << " in base " << sl.base_file()
		  << " ]";
}

SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
