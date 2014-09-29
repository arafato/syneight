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
 * @version $Id: level.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/level.hpp>


SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;


char const * level_to_string(Level_t const level)
{
    switch(level) {
	case AUD_LEVEL:
	    return "AUD";
	case DEB_LEVEL:
	    return "DEB";
	case PRO_LEVEL:
	    return "PRO";
	case ALE_LEVEL:
	    return "ALE";
	case EME_LEVEL:
	    return "EME";
	case TES_LEVEL:
	    return "TES";
	case SYS_LEVEL:
	    return "SYS";
	default:
	    return "UNK";
    }
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
