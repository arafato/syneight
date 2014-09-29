/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/testable_run_visitor.hpp
 *
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: testable_run_visitor.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Testable_Run_Visitor.
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TESTABLE_RUN_VISITOR_HPP
#define SYNEIGHT__BASE__UNITTEST__TESTABLE_RUN_VISITOR_HPP

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/testable.hpp>
#include <syneight/base/unittest/test_case.hpp>
#include <syneight/base/unittest/test_container.hpp>
#include <syneight/base/unittest/testable_visitor.hpp>

#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Testable_Run_Visitor
	: public Testable_Visitor
{

private:
	typedef Testable_Run_Visitor Self;

/**-----------------------------------------------------------------------
 * @name Constructor and destructor
 * @{
 */
public:
	Testable_Run_Visitor();
	Testable_Run_Visitor(Self const & other);
	virtual ~Testable_Run_Visitor();

	Self * clone() const;

// @}
/**-----------------------------------------------------------------------
 * @name Visit methods
 * @{
 */
public: 
	virtual void visit(Test_Container & test_container);
	virtual void visit(Test_Case & test_case);
// @}

};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
