/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/testable_const_visitor.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: testable_const_visitor.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Testable_Const_Visitor.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TESTABLE_CONST_VISITOR_HPP
#define SYNEIGHT__BASE__UNITTEST__TESTABLE_CONST_VISITOR_HPP

#include <syneight/base/unittest/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Container;
class Test_Case;

class Testable_Const_Visitor
{
public:
	virtual ~Testable_Const_Visitor();
	
	virtual void visit(Test_Container const & test_container)=0;
	virtual void visit(Test_Case const & test_case)=0;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#endif
// vim:ts=4:sw=4
