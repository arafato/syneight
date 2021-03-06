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
 * @version $Id: testsupport.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__CONFIG__TESTSUPPORT_HPP
#define SYNEIGHT__CONFIG__TESTSUPPORT_HPP

#ifndef SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE
#  define SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE 1

#  include <syneight/config/internal/common.hpp>
#  include <syneight/base/annotation/testsupport.hpp>

#elif SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE == 0
#  error testsupport.hpp must be included before production.hpp!
#elif SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE == -1
#  error testsupport.hpp must not be included into an executable
#endif



#endif
// vim:ts=4:sw=4
