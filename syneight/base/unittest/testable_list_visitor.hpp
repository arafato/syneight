/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/testable_list_visitor.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: testable_list_visitor.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Testable_List_Visitor.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TESTABLE_LIST_VISITOR_HPP
#define SYNEIGHT__BASE__UNITTEST__TESTABLE_LIST_VISITOR_HPP

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/testable.hpp>
#include <syneight/base/unittest/test_case.hpp>
#include <syneight/base/unittest/test_container.hpp>
#include <syneight/base/unittest/testable_visitor.hpp>

#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Testable_List_Visitor
	: public Testable_Visitor
{

private:
	typedef Testable_List_Visitor Self;

/**-----------------------------------------------------------------------
 * @name Constructor and destructor
 * @{
 */
public:
	Testable_List_Visitor();
	Testable_List_Visitor(Self const & other);
	virtual ~Testable_List_Visitor();

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

public: 
	Test_Container & get_subset() const;
	void list();
	
private:
	Test_Container * m_subset;
	::std::vector< ::std::string*> m_pattern;
	::std::string m_branch_expression;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
