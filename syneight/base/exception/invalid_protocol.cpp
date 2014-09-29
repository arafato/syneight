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
 * @version $Id: invalid_protocol.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/exception/invalid_protocol.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

Invalid_Protocol::~Invalid_Protocol() SYNEIGHT__EXCEPTION_NO_THROW
{
}

Invalid_Protocol::Invalid_Protocol(Self const & other)
    : Super(other)
{
}

Invalid_Protocol::Invalid_Protocol(Source_Location const & source_location,
				   ::std::string const & plain_what)
    : Super(source_location,plain_what)
{
}

char const * Invalid_Protocol::class_name() const
{
    return "Invalid_Protocol";
}

SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
