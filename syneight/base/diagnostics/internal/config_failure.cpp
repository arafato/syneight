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
 * @version $Id: config_failure.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/internal/config_failure.hpp>

#include <syneight/base/exception/standard_exception_aspect.impl.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;


Configure_Failure::Configure_Failure(Source_Location const & source_location, 
				     ::std::string const & reason)
  : Super(source_location), 
    m_reason(reason)
{  
}

Configure_Failure::~Configure_Failure() SYNEIGHT__EXCEPTION_NO_THROW
{
}

char const * Configure_Failure::plain_what() const
{
  m_buffer=class_name()+ ::std::string(": ");
  m_buffer+=m_reason;
  return m_buffer.c_str();
}

char const * Configure_Failure::class_name() const
{
    return "Configure_Failure";
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
