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
 * @version $Id: block_stack.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/kernel/block_stack.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

Block_Stack * Block_Stack::m_instance=NULL;

Block_Stack::Block_Stack()
{
}

::std::string Block_Stack::stack_trace()
{
    /// @todo fill what string
    return "STACK TRACE";
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

// vim:ts=4:sw=4
