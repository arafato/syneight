/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/type.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: type.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Type_t and the standard types.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__TYPE_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__TYPE_HPP

#include <syneight/base/diagnostics/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

typedef char const * Type_t;

extern Type_t const BLOCK_ENTER_TYPE;
extern Type_t const BLOCK_EXIT_TYPE;

extern Type_t const PROCEDURE_ENTER_TYPE;
extern Type_t const PROCEDURE_EXIT_TYPE;

extern Type_t const METHOD_ENTER_TYPE;
extern Type_t const METHOD_EXIT_TYPE;

extern Type_t const TRACE_TYPE;
extern Type_t const BINARY_TRACE_TYPE;

extern Type_t const FAILED_ASSERT_TYPE;
extern Type_t const FAILED_CHECK_TYPE;

extern Type_t const UNEXPECTED_EXCEPTION_TYPE;
extern Type_t const WRONG_EXCEPTION_TYPE;
extern Type_t const MISSING_EXCEPTION_TYPE;

extern Type_t const MEMORY_LEAK_TYPE;
extern Type_t const MEMORY_ANTI_LEAK_TYPE;
extern Type_t const MEMORY_UNEXPECTED_DEALLOCATION;
extern Type_t const MEMORY_ANALYSIS_ENTER_TYPE;
extern Type_t const MEMORY_ANALYSIS_EXIT_TYPE;
extern Type_t const MEMORY_BALANCE_TYPE;


extern Type_t const STACK_TRACE_TYPE;


inline char const * type_to_string(Type_t const type)
{
    return type;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
