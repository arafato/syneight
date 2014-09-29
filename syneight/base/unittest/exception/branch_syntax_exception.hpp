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
 * @version $Id: branch_syntax_exception.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__UNITTEST__BRANCH_SYNTAX_EXCEPTION_HPP
#define SYNEIGHT__BASE__UNITTEST__BRANCH_SYNTAX_EXCEPTION_HPP

#define THROW__BRANCH_SYNTAX_ERROR(BRANCH) \
	throw Branch_Syntax_Exception(BRANCH, Source_Location("__FILE__", "SYNEIGHT__INTERNAL__PARAM__BASE_FILE", __LINE__))

#include <syneight/base/unittest/exception/standard_unittest_system_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

/**
 * @class Branch_Syntax_Exception
 * 
 * @brief Thrown in case of invalid branch syntax.  
 *
 * @nosubgrouping
 */
class Branch_Syntax_Exception
	: public Standard_Unittest_System_Exception
{
public: 
	virtual ~Branch_Syntax_Exception() SYNEIGHT__EXCEPTION_NO_THROW;
	Branch_Syntax_Exception(Source_Location const & source_location,
							::std::string const & branch_expression); 

	char const * plain_what() const;
	char const * class_name() const;
private:
	::std::string m_err_branch_expr;
	mutable ::std::string m_buffer;
};

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
