/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/observer_configuration_error.hpp
 *
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: observer_configuration_error.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Observer_Configuration_Error
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__OBSERVER_CONFIGURATION_ERROR_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__OBSERVER_CONFIGURATION_ERROR_HPP

#include <syneight/base/diagnostics/exception.hpp>
#include <syneight/base/diagnostics/namespace.hpp>
#include <syneight/base/diagnostics/standard_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

/**
 * @class Observer_Configuration_Error
 *
 * @brief The exception to be used if there is either a double registration of
 * an observer or if a to be unregistered observer is not registered.
 *
 * @nosubgrouping
 */
class Observer_Configuration_Error
    : public Standard_Exception
{
    typedef Observer_Configuration_Error Self;
    typedef Standard_Exception Super;
public:
    virtual ~Observer_Configuration_Error() SYNEIGHT__EXCEPTION_NO_THROW;

    Observer_Configuration_Error(Source_Location const source_location,
			  ::std::string const & name);
    
    Observer_Configuration_Error(Self const & other);
    
    inline ::std::string const & name() const;

    virtual char const * class_name() const;

    virtual char const * plain_what() const;
  
  ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name State
     * @{
     */
private:
    ::std::string m_name;
    mutable ::std::string m_buffer;
    // @}
};

/////////////////////////////////////////////////////////////////////
inline ::std::string const & Observer_Configuration_Error::name() const
{
    return m_name;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
