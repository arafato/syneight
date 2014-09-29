/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/exception.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Interface @ref ::syneight::Exception.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__EXCEPTION_HPP
#define SYNEIGHT__BASE__EXCEPTION__EXCEPTION_HPP

#include <syneight/base/exception/exception_no_throw.hpp>

#include <exception>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

class Source_Location;


/**
 * @class Exception
 *
 * @brief The interface for exceptions within syneight. Derived from
 * ::std::exception. 
 *
 * @note the @ref what method inherited from ::std::exception is has
 * to return a string equal to ::baseutil::to_string(@ref
 * plain_what()," : ",@ref source_location()).
 *
 * @nosubgrouping
 */
class Exception
    : public ::std::exception
{
public:
    virtual ~Exception() SYNEIGHT__EXCEPTION_NO_THROW;

    /**
     * @brief The usual what string, i.e., this string should describe
     * the complete contents (ideally) of the exception in human
     * readable fashion -- without the description of the source
     * location.
     *
     * @throw never
     */ 
    virtual char const * plain_what() const =0;

    /**
     * @brief The @ref Source_Location where the exception has been
     * thrown.
     *
     * @throw never
     */
    virtual Source_Location const & source_location() const=0;


    /**
     * @brief Returns the name of the class (qualified with the
     * namespace / but without the leading ::syneight)
     *
     * @throw never
     */ 
    virtual char const * class_name() const =0;
};

SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
