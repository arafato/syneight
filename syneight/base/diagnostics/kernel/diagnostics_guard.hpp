/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/kernel/diagnostics_guard.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: diagnostics_guard.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Macros @ref SYNEIGHT__DIAGNOSTICS_BEGIN and
 * @ref SYNEIGHT__DIAGNOSTICS_END.
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Implement and add test.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__KERNEL__DIAGNOSTICS_GUARD_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__KERNEL__DIAGNOSTICS_GUARD_HPP

#include <syneight/base/diagnostics/namespace.hpp>

/**
 * @brief This block is used to guard all kernel code. Kernel Code
 * logs, tests, and monitors the real application -- it is code which
 * is not allowed to have ''any'' side-effect on the application. It
 * is used for diagnostic purposes.
 *
 * In particular, each block is thread-mutexed and it is ensured that
 * there is no recursive memory logging.
 */
#define SYNEIGHT__DIAGNOSTICS_BEGIN do { ::syneight::diagnostics::internal::Diagnostics_Guard internal_diagnostics_guard; { ((void)0) 
#define SYNEIGHT__DIAGNOSTICS_END   } } while(false)

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

/**
 * @class Diagnostics_Guard
 *
 * @brief Implements @ref SYNEIGHT__DIAGNOSTICS_BEGIN
 *
 * @nosubgrouping
 */
class Diagnostics_Guard
{
public:
    inline Diagnostics_Guard();
    inline ~Diagnostics_Guard();
};

Diagnostics_Guard::Diagnostics_Guard()
{
}
    
Diagnostics_Guard::~Diagnostics_Guard()
{
}

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;



#endif
// vim:ts=4:sw=4
