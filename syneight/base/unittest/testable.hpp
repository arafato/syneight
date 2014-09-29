/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/testable.hpp
 *
 * @author Christian Schallhart
 * @author Tobias Fuchs
 * @author $Author: esdentem $
 *
 * @version $Id: testable.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Testable.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__TESTABLE_HPP
#define SYNEIGHT__BASE__UNITTEST__TESTABLE_HPP

#include <syneight/base/unittest/namespace.hpp>
#include <syneight/base/exception/exception.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Test_Result;
class Testable_Visitor;
class Testable_Const_Visitor;


/**
 * @brief Pure virtual interface. Base class for Test_Case and Test_Container
 *
 * @nosubgrouping
 */
class Testable 
{
	/**--------------------------------------------------------------------------------
	 * @name Types
	 */
private:
	typedef Testable Self;
	// @}

	/**--------------------------------------------------------------------------------
	 * @name Constructor and destructor
	 * @{
	 */
public: 
	//explicit Testable(std::string &name) throw Invalid_Name_Exception;
	virtual ~Testable();
	virtual Self * clone() const =0;
	// @}
	
	/**--------------------------------------------------------------------------------
	 * @name Setters and getters
	 * @{
	 */
public:
	virtual ::std::string const & get_name() const =0;
	virtual bool is_atomic() const =0;
	virtual Test_Result const & test_result() const =0;
	// @}

public:
	virtual void accept_visitor(Testable_Visitor & testable_visitor)=0;
	virtual void accept_visitor(Testable_Const_Visitor & testable_visitor) const =0;
	
	/**--------------------------------------------------------------------------------
	 * @name Virtual interface for running tests
	 * @{
	 */
public: 
	virtual void run_test()=0;
	// @}
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
