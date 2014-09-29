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
 * @version $Id: testable_run_visitor.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/testable_run_visitor.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Testable_Run_Visitor::Testable_Run_Visitor()
{

}
Testable_Run_Visitor::Testable_Run_Visitor(Self const & other)
{
}
Testable_Run_Visitor::~Testable_Run_Visitor()
{
}

Testable_Run_Visitor * Testable_Run_Visitor::clone() const
{
	return new Self(*this);
}

void Testable_Run_Visitor::visit(Test_Container & test_container)
{
	test_container.run_test();
}
void Testable_Run_Visitor::visit(Test_Case & test_case)
{
	test_case.run_test();
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
