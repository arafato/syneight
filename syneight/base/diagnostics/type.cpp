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
 * @version $Id: type.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/type.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

Type_t const BLOCK_ENTER_TYPE="BLOCK_ENTER";
Type_t const BLOCK_EXIT_TYPE="BLOCK_EXIT";

Type_t const PROCEDURE_ENTER_TYPE="PROCEDURE_ENTER";
Type_t const PROCEDURE_EXIT_TYPE="PROCEDURE_EXIT";

Type_t const METHOD_ENTER_TYPE="METHOD_ENTER";
Type_t const METHOD_EXIT_TYPE="METHOD_EXIT";

Type_t const TRACE_TYPE="TRACE";
Type_t const BINARY_TRACE_TYPE="BINARY_TRACE";


Type_t const FAILED_ASSERT_TYPE="FAILED_ASSERT";
Type_t const FAILED_CHECK_TYPE="FAILED_CHECK";


Type_t const UNEXPECTED_EXCEPTION_TYPE="UNEXPECTED_EXCEPTION";
Type_t const WRONG_EXCEPTION_TYPE="WRONG_EXCEPTION";
Type_t const MISSING_EXCEPTION_TYPE="MISSING_EXCEPTION";

Type_t const STACK_TRACE_TYPE="STACK_TRACE";

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
