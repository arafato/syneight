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
 * @version $Id: violated_invariacne.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/exception/violated_invariacne.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

Violated_Invariacne::~Violated_Invariacne() SYNEIGHT__EXCEPTION_NO_THROW
{
}

Violated_Invariacne::Violated_Invariacne(Self const & other)
    : Super(other)
{
}

Violated_Invariacne::Violated_Invariacne(Source_Location const & source_location,
					 ::std::string const & plain_what)
    : Super(source_location,plain_what)
{
}

char const * Violated_Invariacne::class_name() const
{
    return "Violated_Invariacne";
}

SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
