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
 * @author $Author: fuchsto $
 *
 * @version $Id: test_container.cpp 1058 2005-06-09 11:25:54Z fuchsto $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/test_container.hpp>

#include <syneight/base/unittest/exception/invalid_name_exception.hpp>
#include <syneight/base/unittest/testable_visitor.hpp>
#include <syneight/base/unittest/testable_const_visitor.hpp>

#include <boost/spirit/core.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;


/**-------------------------------------------------------------------------------- 
 *	@name Constructors and destructors
 *	@{
 */

Test_Container::~Test_Container()
{
	delete &m_test_units;
}

Test_Container * Test_Container::clone() const
{
	return new Self(*this);
}

/// @brief: sets m_run = false and valid name (no / allowed) */
Test_Container::Test_Container(::std::string &name, Level_t level) 
{
	// in case of invalid name
	if (!check_name(name)) throw Invalid_Name_Exception(SYNEIGHT__SOURCE_LOCATION,name);

	m_test_name = name; 
	m_test_level = level;
	m_run = false;
	m_test_result = new Test_Container_Result(level);
}

Test_Container::Test_Container(Self const & other)
	: m_run(other.m_run), 
	  m_test_name(other.m_test_name), 
	  m_test_level(other.m_test_level), 
	  m_test_result(other.m_test_result)
{
}

/// @brief Handles visitors and propagates them through the Testable vector.
void Test_Container::accept_visitor(Testable_Visitor & testable_visitor)
{

	::std::vector<Testable*>::const_iterator begin(m_test_units.begin());
	::std::vector<Testable*>::const_iterator const end(m_test_units.end());

	// 1.: Hand down visitor, we want him to work bottom-up
	/// @todo Check if this should be done by visitor
	for(;begin!=end;++begin)
	{
		(*begin)->accept_visitor(testable_visitor);
	}

	// 2.: After the visitor visited all branches, he can visit us here.
	testable_visitor.visit(*this);

}

void Test_Container::accept_visitor(Testable_Const_Visitor & testable_visitor) const
{
	testable_visitor.visit(*this);
}


/**--------------------------------------------------------------------------------
 *	@name Derived from Testable
 *	@{
 */

/// @brief Returns assigned Test_Result. 
Test_Container_Result & Test_Container::test_result()
{
	return *(m_test_result);
}
Test_Container_Result const & Test_Container::test_result() const
{
	return *(m_test_result);
}
/// @brief Returns name of test container as string. 
::std::string const & Test_Container::get_name() const
{
	return m_test_name;
}
/// @brief iteratively collects all non-positive results, sets m_run = true
void Test_Container::run_test()
{

	if (m_run == false)
	{

		::std::vector<Testable*>::iterator begin(m_test_units.begin());
		::std::vector<Testable*>::const_iterator const end(m_test_units.end());

		for( ; begin != end; ++begin)
		{
			
//			(*begin)->run_test(); // This should be called by the visitor.
			/// @todo Should we throw if the test hasn't already run?
			Test_Result const & current_result = (*begin)->test_result();
			// only add failed / errousnous results:
			if ( !current_result.is_empty() )
			{
				m_test_result->add_result(current_result);
			}
			
		}
	}

	m_run = true;

}

/// @}

/**--------------------------------------------------------------------------------
 * @name Specialized methods
 * @{
 */
void Test_Container::set_result(Test_Container_Result &summary)
{
	m_test_result = &summary;
};

/// @brief Add Testable to be run.  Checks for this.get_name() != test_unit.get_name().
void Test_Container::add_testable(Testable &test_unit)
{
	/// @todo CHECK WHETHER THIS IS SANE
	if (test_unit.get_name() == get_name()) {
		throw Invalid_Name_Exception(SYNEIGHT__SOURCE_LOCATION, get_name());
	}

	m_test_units.push_back(&test_unit);
}
/// @}

/**---------------------------------------------------------------------------
 * @name Private methods
 * @{
 */
bool Test_Container::check_name(::std::string &name) const
{
	return ::boost::spirit::parse( name.c_str(),
								 ( +::boost::spirit::alnum_p >> *('_' >> +::boost::spirit::alnum_p) )
								 ).full;
}
// @}

bool Test_Container::is_atomic() const
{
	return false;
}


SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
