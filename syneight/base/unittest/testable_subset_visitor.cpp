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
 * @version $Id: testable_subset_visitor.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/testable_subset_visitor.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Testable_Subset_Visitor::Testable_Subset_Visitor()
	: m_branch_expression("*")
{
	m_subset_name = static_cast< ::std::string>("/");
	m_subset = new Test_Container(m_subset_name, Level_t(6));
}
Testable_Subset_Visitor::Testable_Subset_Visitor(::std::string const & branch_expression)
	: m_branch_expression(branch_expression)
{
	m_subset_name = static_cast< ::std::string>("/");
	m_subset = new Test_Container(m_subset_name, Level_t(6));
}
Testable_Subset_Visitor::Testable_Subset_Visitor(Self const & other)
	: m_branch_expression(other.m_branch_expression),
	  m_subset(other.m_subset)
{
}

Testable_Subset_Visitor * Testable_Subset_Visitor::clone() const
{
	return new Self(*this);
}

void Testable_Subset_Visitor::visit(Test_Container & test_container)
{
	::std::string testable_name( test_container.get_name() );
	
	if(match_pattern(testable_name)) {
	//	m_subset.push_back(&test_container);
		m_subset->add_testable(test_container);
		test_container.accept_visitor(*this);
	}
}
void Testable_Subset_Visitor::visit(Test_Case & test_case)
{
	::std::string testable_name(test_case.get_name());

	if(match_pattern(testable_name)) {
	//	m_subset.push_back(&test_case);
		m_subset->add_testable(test_case);
	}
}

Test_Container * Testable_Subset_Visitor::get_subset() const
{
	return m_subset;
}

bool Testable_Subset_Visitor::match_pattern(::std::string const & pattern) const
{
	return ::boost::spirit::parse(  pattern.c_str(),
									( +::boost::spirit::alnum_p >>
									*('/' >> +::boost::spirit::alnum_p) ) |
									::boost::spirit::ch_p('*')
								 ).full; // XXX Does this compile?
}


SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
