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
 * @version $Id: unittest.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__CONFIG__UNITTEST_HPP
#define SYNEIGHT__CONFIG__UNITTEST_HPP


#ifndef SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE
#  define SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE 2

#  include <syneight/base/config/internal/common.hpp>
#  include <syneight/base/config/internal/main.hpp>
#  include <syneight/base/annotation/unittest.hpp>

#elif SYNEIGHT__INTERNAL__SWITCH__COMPILATION_UNIT_TYPE != 2
#  error unittest.hpp must be included first!
#endif

#endif
// vim:ts=4:sw=4
