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
 * @version $Id: testable_list_visitor.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/testable_list_visitor.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Testable_List_Visitor::Testable_List_Visitor()
{

}
Testable_List_Visitor::Testable_List_Visitor(Self const & other)
	: m_subset(other.m_subset)
{
}
Testable_List_Visitor::~Testable_List_Visitor()
{
}

Testable_List_Visitor * Testable_List_Visitor::clone() const
{
	return new Self(*this);
}

void Testable_List_Visitor::visit(Test_Container & test_container)
{
	// m_subset.push_back(&test_container);
	m_subset->add_testable(test_container);
	test_container.accept_visitor(*this);
}
void Testable_List_Visitor::visit(Test_Case & test_case)
{
	// m_subset.push_back(&test_case);
	m_subset->add_testable(test_case);
}

void Testable_List_Visitor::list()
{
	// blank so far. 
}

Test_Container & Testable_List_Visitor::get_subset() const
{
	return *m_subset;
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
