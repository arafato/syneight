/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/not_implemented.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: not_implemented.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Middle class @ref ::syneight::Not_Implemented.
 *        TODO: What is a middle class.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__NOT_IMPLEMENTED_HPP
#define SYNEIGHT__BASE__EXCEPTION__NOT_IMPLEMENTED_HPP

#include <syneight/base/exception/standard_low_level_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Not_Implemented 
 *
 * @brief The exception to be used if a feature is not implemented.
 *
 * @nosubgrouping
 */
class Not_Implemented
    : public Standard_Low_Level_Exception
{
    typedef Not_Implemented Self;
    typedef Standard_Low_Level_Exception Super;
public:
    virtual ~Not_Implemented() SYNEIGHT__EXCEPTION_NO_THROW;
    Not_Implemented(Self const & other);
    Not_Implemented(Source_Location const & source_location,
		    ::std::string const & plain_what);
    virtual char const * class_name() const;
};

SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
