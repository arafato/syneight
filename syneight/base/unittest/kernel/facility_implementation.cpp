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
 * @version $Id: facility_implementation.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/kernel/facility_implementation.hpp>

#include <algorithm>

/// @todo fill register_observer and unregister_observer

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Facility_Implementation::Facility_Implementation()
	: m_test_data(NULL)
{
}

void Facility_Implementation::set_test_data(Test_Data & test_data)
{
	m_test_data=&test_data;
}

bool Facility_Implementation::is_observing()
{
	return m_is_observing;
}

void Facility_Implementation::register_observer(Observer & observer)
{
	Observers_t::const_iterator const iter(::std::find(m_observers.begin(),
													   m_observers.end(),
													   &observer));
	if (iter != m_observers.end())
	throw Observer_Configuration_Error(SYNEIGHT__SOURCE_LOCATION,
									   ::std::string("Observer already registered."));
	m_observers.push_back(&observer);
	m_is_observing = true;
}

void Facility_Implementation::unregister_observer(Observer & observer)
{
	Observers_t::iterator iter(::std::find(m_observers.begin(),
									 			 m_observers.end(),
												 &observer));
	if(iter == m_observers.end())
	throw Observer_Configuration_Error(SYNEIGHT__SOURCE_LOCATION,
									   ::std::string("Unregistration of unregistered observer."));
	m_observers.erase(iter);
	m_is_observing = m_observers.size() != 0;
}

void Facility_Implementation::testcase_enter(Test_Result & test_result)
{
	if(m_test_observer!=NULL) 
	throw Observer_Configuration_Error(SYNEIGHT__SOURCE_LOCATION, ::std::string("No m_test_observer set. "));
	delete m_test_observer;
	m_test_observer=NULL;
	m_test_observer=new Test_Observer(test_result,m_observers);
	::syneight::diagnostics::Facility_Implementation::instance().register_observer(*m_test_observer);
}

void Facility_Implementation::testcase_exit()
{
	if(m_test_observer==NULL) 
	throw Observer_Configuration_Error(SYNEIGHT__SOURCE_LOCATION, ::std::string("No m_test_observer set. "));
	::syneight::diagnostics::Facility_Implementation::instance().unregister_observer(*m_test_observer);
	delete m_test_observer;
	m_test_observer=NULL;
}

void Facility_Implementation::disable_test_observer()
{
	if(m_test_observer==NULL)
	throw Observer_Configuration_Error(SYNEIGHT__SOURCE_LOCATION, ::std::string("No m_test_observer set. "));
	::syneight::diagnostics::Facility_Implementation::instance().unregister_observer(*m_test_observer);
}

void Facility_Implementation::enable_test_observer()
{
	if(m_test_observer==NULL)
	throw Observer_Configuration_Error(SYNEIGHT__SOURCE_LOCATION, ::std::string("No m_test_observer set. ")); 
	::syneight::diagnostics::Facility_Implementation::instance().register_observer(*m_test_observer);
}

::std::string const & Facility_Implementation::get_data(::std::string const & id)
{
	return m_test_data->get(id);
}

bool Facility_Implementation::cmp_data(::std::string const & id, ::std::string const & data)
{
	return m_test_data->compare(id,data);
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
