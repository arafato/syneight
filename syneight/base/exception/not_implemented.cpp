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
 * @version $Id: not_implemented.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/exception/not_implemented.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

Not_Implemented::~Not_Implemented() SYNEIGHT__EXCEPTION_NO_THROW
{
}

Not_Implemented::Not_Implemented(Self const & other)
    : Super(other)
{
}

Not_Implemented::Not_Implemented(Source_Location const & source_location,
				 ::std::string const & plain_what)
    : Super(source_location,plain_what)
{
}

char const * Not_Implemented::class_name() const
{
    return "Not_Implemented";
}

SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
