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
 * @version $Id: assert_log.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__ASSERT_LOG_HPP
#define SYNEIGHT__ANNOTATION__BITS__ASSERT_LOG_HPP

#include <syneight/base/annotation/base/condition.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__ASSERT_LOG(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION_LOG(ASSERT,AUD,NAME,COND)
#  define SYNEIGHT__AUD__ASSERT_LOG1(NAME,COND,W1)          SYNEIGHT__INTERNAL__CONDITION_LOG1(ASSERT,AUD,NAME,COND,(W1)) 
#  define SYNEIGHT__AUD__ASSERT_LOG2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION_LOG2(ASSERT,AUD,NAME,COND,(W1),(W2)) 
#  define SYNEIGHT__AUD__ASSERT_LOG3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION_LOG3(ASSERT,AUD,NAME,COND,(W1),(W2),(W3)) 
#  define SYNEIGHT__AUD__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION_LOG4(ASSERT,AUD,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__AUD__ASSERT_LOG(NAME,COND)              ((void)0)
#  define SYNEIGHT__AUD__ASSERT_LOG1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__AUD__ASSERT_LOG2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__AUD__ASSERT_LOG3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__AUD__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__ASSERT_LOG(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION_LOG(ASSERT,DEB,NAME,COND)		   
#  define SYNEIGHT__DEB__ASSERT_LOG1(NAME,COND,W1) 	   SYNEIGHT__INTERNAL__CONDITION_LOG1(ASSERT,DEB,NAME,COND,(W1)) 	   
#  define SYNEIGHT__DEB__ASSERT_LOG2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION_LOG2(ASSERT,DEB,NAME,COND,(W1),(W2))
#  define SYNEIGHT__DEB__ASSERT_LOG3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION_LOG3(ASSERT,DEB,NAME,COND,(W1),(W2),(W3))
#  define SYNEIGHT__DEB__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION_LOG4(ASSERT,DEB,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__DEB__ASSERT_LOG(NAME,COND)              ((void)0)
#  define SYNEIGHT__DEB__ASSERT_LOG1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__DEB__ASSERT_LOG2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__DEB__ASSERT_LOG3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__DEB__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__ASSERT_LOG(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION_LOG(ASSERT,PRO,NAME,COND)		   
#  define SYNEIGHT__PRO__ASSERT_LOG1(NAME,COND,W1) 	   SYNEIGHT__INTERNAL__CONDITION_LOG1(ASSERT,PRO,NAME,COND,(W1)) 	   
#  define SYNEIGHT__PRO__ASSERT_LOG2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION_LOG2(ASSERT,PRO,NAME,COND,(W1),(W2))
#  define SYNEIGHT__PRO__ASSERT_LOG3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION_LOG3(ASSERT,PRO,NAME,COND,(W1),(W2),(W3))
#  define SYNEIGHT__PRO__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION_LOG4(ASSERT,PRO,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__PRO__ASSERT_LOG(NAME,COND)              ((void)0)
#  define SYNEIGHT__PRO__ASSERT_LOG1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__PRO__ASSERT_LOG2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__PRO__ASSERT_LOG3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__PRO__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__ASSERT_LOG(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION_LOG(ASSERT,TES,NAME,COND)		         
#  define SYNEIGHT__TES__ASSERT_LOG1(NAME,COND,W1)          SYNEIGHT__INTERNAL__CONDITION_LOG1(ASSERT,TES,NAME,COND,(W1)) 	      
#  define SYNEIGHT__TES__ASSERT_LOG2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION_LOG2(ASSERT,TES,NAME,COND,(W1),(W2))
#  define SYNEIGHT__TES__ASSERT_LOG3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION_LOG3(ASSERT,TES,NAME,COND,(W1),(W2),(W3))
#  define SYNEIGHT__TES__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION_LOG4(ASSERT,TES,NAME,COND,(W1),(W2),(W3),(W4)) 

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__ASSERT_LOG(NAME,COND)              ((void)0)
#  define SYNEIGHT__TES__ASSERT_LOG1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__TES__ASSERT_LOG2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__TES__ASSERT_LOG3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__TES__ASSERT_LOG4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

#endif
// vim:ts=4:sw=4
