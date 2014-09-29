/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/test_case.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: test_case.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Case.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TEST_CASE_HPP
#define SYNEIGHT__BASE__UNITTEST__TEST_CASE_HPP

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/unittest/level.hpp>
#include <syneight/base/unittest/testable.hpp>
#include <syneight/base/unittest/test_case_result.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Case_Result;

/**
 * @brief Atomic test case, derived from Testable. Method run_test() is to be overridden 
 * with custom test, test_result returning its result. 
 *
 * @nosubgrouping
 */
class Test_Case 
	: public Testable
{
	/**--------------------------------------------------------------------------------
	 * @name
	 */
private:
	typedef Test_Case Self;
	// @}

	/**--------------------------------------------------------------------------------
	 * @name Constructor and destructor
	 * @{
	 */
public:
	~Test_Case();
	virtual Self * clone() const;
	
	Test_Case(::std::string const &name, Level_t level, int timeout); 
	Test_Case(Self const & other);
	// @}
	

	void set_result(Test_Case_Result &result);
	/**--------------------------------------------------------------------------------
	 * @name Methods inherited from Testable
	 * @{
	 */

	/// @brief Returns Test_Case_Result which is generated while running test. 
	// only in the Test_Case since it is impossible to overwrite
	// an aggregate Test_Case_Result
	virtual Test_Case_Result & test_result();
	virtual Test_Case_Result const & test_result() const;

	/// @brief Returns name of this test as string. 
	::std::string const & get_name() const;
	/// @brief Initiate test. Has to be overridden by custom test procedure. 
	void run_test();
	///
	virtual bool is_atomic() const;
	// @}


public:
	virtual void accept_visitor(Testable_Visitor & testable_visitor);
	virtual void accept_visitor(Testable_Const_Visitor & testable_visitor) const;
	
	/**--------------------------------------------------------------------------------
	 * @name Methods spezialized for Test_Case
	 * 
	 */
public:	
	/// @brief Break running test (e.g. in case of timeout).
	void break_test();
	/// @brief Returns timeout (max. allowed durance) in milliseconds for this test. 
	void set_timeout(unsigned int timeout);
	int get_timeout() const;
	/// @brief Returns test level of this test (AUDIT | DEBUG | PROD). 
	Level_t get_test_level() const;
	// @}	

	/**--------------------------------------------------------------------------------
	 * @name Private methods
	 * @{
	 */
private: 
	bool check_name(::std::string const &name) const;
	
	/**--------------------------------------------------------------------------------
	 * @name Member variables
	 * @{
	 */
private: 
	/// @brief Wheter this test has been run already. 
	bool m_run;
	/// @brief Assigned Test_Case_Result to build during test. 
	//	No reference, as it is initialized in constructor. Per default, no Test_Case_Result 
	//	has to be set, but it may be overridden. 
	Test_Case_Result * m_test_result;
	/// @brief Assigned test level ( AUDIT | DEBUG | PROD )
	Level_t m_test_level;
	/// @brief Name of this test as string. 
	::std::string m_test_name;
	/// @brief Timeout in milliseconds for this test. 0 for none. 
	unsigned int m_test_timeout;
	// @}
	
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
