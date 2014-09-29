/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/unittest/facility.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: facility.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::unittest::Test_Facility.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Test.
 */

#ifndef SYNEIGHT__BASE__UNITTEST__FACILITY_HPP
#define SYNEIGHT__BASE__UNITTEST__FACILITY_HPP

#include <syneight/base/unittest/namespace.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

class Facility
{
private:
	Facility();
	friend class To_Avoid_Compiler_Errors;
public:
	/**
	 * @brief returns the data string matching to @a id contained in
	 * the the @ref Test_Data set with the call set_test_data.
	 *
	 * Depending on the mode of interaction, this call might throw if
	 * @a id is not valid. In particular, this setting is configured
	 * in terms of the concrete @ref Test_Data object given to the
	 * Facility_Implementation. Usually, this object is constructed
	 * and maintained by the @ref Test_Environment.
	 *
	 * @pre @a id must be valid
	 *
	 * @throw Unknown_Test_Data_Id
	 */
	static ::std::string const & get_data(::std::string const & id);


	/**
	 * @brief returns true if the configured @ref Test_Data object
	 * maps @a id to @a data. This @ref Test_Data object is configured
	 * with the call set_test_data.
	 *
	 * Depending on the mode of interaction, the configured Test_Data
	 * object might handle mismachtes in different ways, i.e., it
	 * might allow the user to modify the maintained map. In a
	 * non-interactive mode, no changes might be allowed.
	 *
	 * @pre @a id must be valid 
	 *
	 * @throw Unknown_Test_Data_Id
	 */
	static bool cmp_data(::std::string const & id, ::std::string const & data);
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
