/*-----------------------------------------------------------------------------:
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
 * @version $Id: branch_path_exception.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/unittest/exception/branch_path_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__UNITTEST;

Branch_Path_Exception::Branch_Path_Exception(Source_Location const & source_location,
									   ::std::string const & branch_expression) 
	: Standard_Unittest_System_Exception(source_location), 
	  m_err_branch_expr(branch_expression)
{
}

Branch_Path_Exception::~Branch_Path_Exception() SYNEIGHT__EXCEPTION_NO_THROW
{

}

char const * Branch_Path_Exception::plain_what() const
{
  m_buffer = "Branch_Path_Exception: [";
  m_buffer += m_err_branch_expr;
  m_buffer += "] test path does not exist. ";
  
  return m_buffer.c_str();
}

SYNEIGHT__END__NAMESPACE__UNITTEST;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
