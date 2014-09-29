/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/detail/test_observer.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_observer.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Observer.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__DETAIL__TEST_OBSERVER_HPP
#define SYNEIGHT__BASE__UNITTEST__DETAIL__TEST_OBSERVER_HPP

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/diagnostics/kernel/observer.hpp>

#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Result;

/**
 * @class 
 *
 * @brief
 *
 * @nosubgrouping
 */
class Test_Observer
	: public ::syneight::diagnostics::Observer
{
	typedef ::syneight::diagnostics::Event Event;
	typedef ::std::vector< ::syneight::diagnostics::Observer*> Observers_t;
public:
	virtual ~Test_Observer();
	Test_Observer(Test_Result & test_result, Observers_t const & observers);

	virtual void log(Event const & event);
	virtual void close();
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
