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

#include <syneight/base/memory_monitoring/type.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;

diagnostics::Type_t const MEMORY_LEAK_TYPE="MEMORY_LEAK";
diagnostics::Type_t const MEMORY_ANTI_LEAK_TYPE="MEMORY_ANTI_LEAK";
diagnostics::Type_t const MEMORY_UNEXPECTED_DEALLOCATION="MEMORY_UNEXPECTED";
diagnostics::Type_t const MEMORY_ANALYSIS_ENTER_TYPE="MEMORY_ANALYSIS_ENTER";
diagnostics::Type_t const MEMORY_ANALYSIS_EXIT_TYPE="MEMORY_ANALYSIS_EXIT";
diagnostics::Type_t const MEMORY_BALANCE_TYPE="MEMORY_BALANCE";


SYNEIGHT__END__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
