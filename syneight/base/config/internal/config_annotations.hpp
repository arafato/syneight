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
 * @version $Id: config_annotations.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__CONFIG__INTERNAL__CONFIG_ANNOTATIONS_HPP
#define SYNEIGHT__CONFIG__INTERNAL__CONFIG_ANNOTATIONS_HPP

// Exception Base Type /////////////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_TYPE
#  define SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_TYPE ::syneight::Exception
#  include <syneight/base/exception/exception.hpp>
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT
#  define SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT(e) e.plain_what()
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION
#  define SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION(e) ((e).source_location())
#  include <syneight/base/util/string.hpp>
#endif

// Test Exception Type /////////////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_TYPE
#  define SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_TYPE ::syneight::unittest::Unittest_Exception
#  include <syneight/base/unittest/exception/unittest_exception.hpp>
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_WHAT
#  define SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_WHAT(e) \
     SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_WHAT(e)
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_SOURCE_LOCATION
#  define SYNEIGHT__INTERNAL__PARAM__TEST_EXCEPTION_SOURCE_LOCATION(e) \
     SYNEIGHT__INTERNAL__PARAM__BASE_EXCEPTION_SOURCE_LOCATION(e)
#endif

// Specific Test Exception Types ////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__TEST_ERROR_EXCEPTION_TYPE
#  define SYNEIGHT__INTERNAL__PARAM__TEST_ERROR_EXCEPTION_TYPE ::syneight::unittest::Unittest_Error
#  include <syneight/base/unittest/exception/unittest_error.hpp>
#endif

// Test Exception Handling //////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__SWITCH__HANDLE_TEST_EXCEPTION_EXPLICITLY
#  define SYNEIGHT__INTERNAL__SWITCH__HANDLE_TEST_EXCEPTION_EXPLICITLY 0
#endif

// Standard Logging Category ///////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY
#  define SYNEIGHT__INTERNAL__PARAM__STANDARD_CATEGORY category_handle()
#  include <syneight/base/config/internal/root_category.hpp>
#endif

// Memory Analysis /////////////////////////////////////////////////////////////

#ifndef SYNEIGHT__SWITCH__MEMORY_ANALYSIS
#  define SYNEIGHT__SWITCH__MEMORY_ANALYSIS 0
#endif

// Exception Construction //////////////////////////////////////////////////////

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION0
#  define SYNEIGHT__INTERNAL__PARAM__EXCEPTION0(LEVEL,TYPE,NAME,COND) \
      NAME excep(SYNEIGHT__SOURCE_LOCATION, ("failed: " #COND))
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION1
#  define SYNEIGHT__INTERNAL__PARAM__EXCEPTION1(LEVEL,TYPE,NAME,COND,W1) \
      NAME excep(SYNEIGHT__SOURCE_LOCATION, W1)
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION2
#  define SYNEIGHT__INTERNAL__PARAM__EXCEPTION2(LEVEL,TYPE,NAME,COND,W1,W2) \
      NAME excep(SYNEIGHT__SOURCE_LOCATION, W1,W2)
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION3
#  define SYNEIGHT__INTERNAL__PARAM__EXCEPTION3(LEVEL,TYPE,NAME,COND,W1,W2,W3) \
      NAME excep(SYNEIGHT__SOURCE_LOCATION, W1,W2,W3)
#endif

#ifndef SYNEIGHT__INTERNAL__PARAM__EXCEPTION4
#  define SYNEIGHT__INTERNAL__PARAM__EXCEPTION4(LEVEL,TYPE,NAME,COND,W1,W2,W3,W4) \
      NAME excep(SYNEIGHT__SOURCE_LOCATION, W1,W2,W3,W4)
#endif


#endif
// vim:ts=4:sw=4
