/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/exception/violated_invariacne.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: violated_invariacne.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Middle class @ref ::syneight::Violated_Invariacne.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__EXCEPTION__VIOLATED_INVARIACNE_HPP
#define SYNEIGHT__BASE__EXCEPTION__VIOLATED_INVARIACNE_HPP

#include <syneight/base/exception/standard_low_level_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;

/**
 * @class Violated_Invariacne 
 *
 * @brief The exception to be used if a loop-, class-, or other
 * invariance is violated.
 *
 * @nosubgrouping
 */
class Violated_Invariacne
    : public Standard_Low_Level_Exception
{
    typedef Violated_Invariacne Self;
    typedef Standard_Low_Level_Exception Super;
public:
    virtual ~Violated_Invariacne() SYNEIGHT__EXCEPTION_NO_THROW;
    Violated_Invariacne(Self const & other);
    Violated_Invariacne(Source_Location const & source_location,
			::std::string const & plain_what);
    virtual char const * class_name() const;
};

SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
