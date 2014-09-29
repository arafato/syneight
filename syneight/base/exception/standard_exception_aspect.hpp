/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/standard_exception_aspect.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: standard_exception_aspect.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Aspect @ref ::syneight::Standard_Exception_Aspect.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__STANDARD_EXCEPTION_ASPECT_HPP
#define SYNEIGHT__BASE__EXCEPTION__STANDARD_EXCEPTION_ASPECT_HPP

#include <syneight/base/exception/exception_no_throw.hpp>
#include <syneight/base/exception/source_location.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Standard_Exception_Aspect
 *
 * @brief This apsect provides the implementation for the methods what
 * (of ::std::exception) and source_location (@ref Exception). The
 * methods plain_what and class_name remain pure virtual.
 *
 * @nosubgrouping
 */
template<typename BASE>
class Standard_Exception_Aspect
    : public BASE
{
private:
    typedef Standard_Exception_Aspect Self;

public:
    virtual ~Standard_Exception_Aspect() SYNEIGHT__EXCEPTION_NO_THROW;
protected:
    Standard_Exception_Aspect(Self const & other);
    explicit Standard_Exception_Aspect(Source_Location const & source_location); 

public:
    virtual char const * what() const SYNEIGHT__EXCEPTION_NO_THROW;
    virtual char const * plain_what() const =0;
    virtual Source_Location const & source_location() const;

private:
    Source_Location m_source_location;
    mutable ::std::string m_buffer;

};


SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
