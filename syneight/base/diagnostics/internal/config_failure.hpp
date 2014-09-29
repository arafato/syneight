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
 * @version $Id: config_failure.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__DIAGNOSTICS__DETAIL__CONFIGURE_FAILURE_HPP
#define SYNEIGHT__DIAGNOSTICS__DETAIL__CONFIGURE_FAILURE_HPP

#include <syneight/base/diagnostics/namespace.hpp>

#include <syneight/base/exception/exception.hpp>
#include <syneight/base/exception/standard_exception_aspect.hpp>
#include <syneight/base/exception/source_location.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;



class Configure_Failure 
  : public Standard_Exception_Aspect<Exception>
{
  typedef Standard_Exception_Aspect<Exception> Super;
  /**
   * Exception Class for configuration
   */
public:
  /**
   * Constructor.
   * @param reason String containing the description of the exception.
   * @param source Object of type syneight::Source_Location
   */  
  Configure_Failure(Source_Location const & source_location, 
		    ::std::string const & reason);
  virtual ~Configure_Failure() SYNEIGHT__EXCEPTION_NO_THROW;

  virtual char const * plain_what() const;
    virtual char const * class_name() const;
private:
  ::std::string m_reason;
  mutable ::std::string m_buffer;
};

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
