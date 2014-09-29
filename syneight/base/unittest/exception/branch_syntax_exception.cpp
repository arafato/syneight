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
 * @version $Id: branch_syntax_exception.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/exception/branch_syntax_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Branch_Syntax_Exception::Branch_Syntax_Exception(Source_Location const & source_location,
									   ::std::string const & branch_expression) 
	: Standard_Unittest_System_Exception(source_location), 
	  m_err_branch_expr(branch_expression)
{
}

Branch_Syntax_Exception::~Branch_Syntax_Exception() SYNEIGHT__EXCEPTION_NO_THROW
{

}

char const * Branch_Syntax_Exception::plain_what() const
{
  m_buffer = class_name()+ ::std::string(": [");
  m_buffer += m_err_branch_expr;
  m_buffer += "] test path does not exist. ";
  
  return m_buffer.c_str();
}

char const * Branch_Syntax_Exception::class_name() const
{
	return "Branch_Syntax_Exception";
}


SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
