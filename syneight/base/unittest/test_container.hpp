/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/test_container.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_container.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Container.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TEST_CONTAINER_HPP
#define SYNEIGHT__BASE__UNITTEST__TEST_CONTAINER_HPP

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/level.hpp>
#include <syneight/base/unittest/testable.hpp>
#include <syneight/base/unittest/test_container_result.hpp>

#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Container_Result;

/**
 * @brief A Test_Container bundles Testables (i.e. other Test_Containers, too) so they can be run and their results evaluated at once.
 *
 * @nosubgrouping
 */
class Test_Container : public Testable
{
private:
	typedef Test_Container Self;

	/**---------------------------------------------------------------------------
	 * @name Constructor and destructor
	 * @{
	 */
public:
	virtual ~Test_Container();	
	virtual Self * clone() const;

	/** sets run = false and valid name (no / allowed) */
	Test_Container(::std::string &name, Level_t level);	

	Test_Container(Self const & other);

	// @}

public:
	virtual void accept_visitor(Testable_Visitor & testable_visitor);
	virtual void accept_visitor(Testable_Const_Visitor & testable_visitor) const;

	
	/**---------------------------------------------------------------------------
	 * @name Methods derived from Testable
	 * @{
	 */
public:
	virtual Test_Container_Result & test_result();
	virtual Test_Container_Result const & test_result() const; 
	/// @brief Assign Test_Container_Result to be generated during test run. 
	::std::string const & get_name() const;
	
	/// @brief Assign Test_Container_Result to be generated during test run. 
	void set_result(Test_Container_Result & result);
	/// @brief Iteratively runs all added Testables, sets run = true.
	void run_test();
	///
	virtual bool is_atomic() const;
	// @}

	/**---------------------------------------------------------------------------
	 * @name Specialized methods for Test_Container
	 * @{
	 */
public:
	
	/// @brief Add a Testable to container. 
	// checks for this.get_name() != uut.get_name()
	void add_testable(Testable &test_unit); 
	// @}

	/**---------------------------------------------------------------------------
	 * @name Private methods
	 * @{
	 */
private: 
	bool check_name(::std::string &name) const;
	
	/**---------------------------------------------------------------------------
	 * @name Private member variabless
	 * @{
	 */
private: 
	
	/// @brief name of Test_Container
	::std::string m_test_name;
	/// @brief Assigned Test_Container_Result to build. 
	Test_Container_Result * m_test_result;
	/// @brief Test level to operate on
	Level_t m_test_level;
	/// @brief vector containing all Testables to be run
	::std::vector<Testable*> m_test_units;	
	/// @brief wheter this container already has been run
	bool m_run;
	/// @brief Contains branch expression. If set, only Testables matching the expression are executed. 
	::std::string m_branch_expression;
	// @}
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
