/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/detail/observer.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: observer.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Interface @ref ::syneight::diagnostics::Observer.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGSNOTICS__DETAIL__OBSERVER_HPP
#define SYNEIGHT__BASE__DIAGSNOTICS__DETAIL__OBSERVER_HPP

#include <syneight/base/diagnostics/level.hpp>
#include <syneight/base/diagnostics/type.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

class Event;

/**
 * @class Observer
 *
 * @brief An Observer is used to observe the @ref Event stream of
 * ::syneight::diagnostics.
 *
 * @todo more documentation
 *
 * @nosubgrouping
 */

class Observer
{
public:
    virtual ~Observer();

    virtual void log(Event const & event)=0;
    virtual void close()=0;
};

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
