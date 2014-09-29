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
 * @version $Id: check.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__CHECK_HPP
#define SYNEIGHT__ANNOTATION__BITS__CHECK_HPP

#include <syneight/base/annotation/base/condition.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__CHECK(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(CHECK,AUD,NAME,COND)
#  define SYNEIGHT__AUD__CHECK1(NAME,COND,W1)          SYNEIGHT__INTERNAL__CONDITION1(CHECK,AUD,NAME,COND,(W1)) 
#  define SYNEIGHT__AUD__CHECK2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(CHECK,AUD,NAME,COND,(W1),(W2)) 
#  define SYNEIGHT__AUD__CHECK3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(CHECK,AUD,NAME,COND,(W1),(W2),(W3)) 
#  define SYNEIGHT__AUD__CHECK4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(CHECK,AUD,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__AUD__CHECK(NAME,COND)              ((void)0)
#  define SYNEIGHT__AUD__CHECK1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__AUD__CHECK2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__AUD__CHECK3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__AUD__CHECK4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__CHECK(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(CHECK,DEB,NAME,COND)		   
#  define SYNEIGHT__DEB__CHECK1(NAME,COND,W1) 	      SYNEIGHT__INTERNAL__CONDITION1(CHECK,DEB,NAME,COND,(W1)) 	   
#  define SYNEIGHT__DEB__CHECK2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(CHECK,DEB,NAME,COND,(W1),(W2)) 	   
#  define SYNEIGHT__DEB__CHECK3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(CHECK,DEB,NAME,COND,(W1),(W2),(W3))    
#  define SYNEIGHT__DEB__CHECK4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(CHECK,DEB,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__DEB__CHECK(NAME,COND)              ((void)0)
#  define SYNEIGHT__DEB__CHECK1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__DEB__CHECK2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__DEB__CHECK3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__DEB__CHECK4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  if SYNEIGHT__SWITCH__LOG_PRO_CHECKS == 1

#    define SYNEIGHT__PRO__CHECK(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(CHECK,PRO,NAME,COND)		   
#    define SYNEIGHT__PRO__CHECK1(NAME,COND,W1) 	        SYNEIGHT__INTERNAL__CONDITION1(CHECK,PRO,NAME,COND,(W1)) 	   
#    define SYNEIGHT__PRO__CHECK2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(CHECK,PRO,NAME,COND,(W1),(W2)) 	   
#    define SYNEIGHT__PRO__CHECK3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(CHECK,PRO,NAME,COND,(W1),(W2),(W3))    
#    define SYNEIGHT__PRO__CHECK4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(CHECK,PRO,NAME,COND,(W1),(W2),(W3),(W4)) 

#  else 

#    define SYNEIGHT__PRO__CHECK(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION_THROW(CHECK,PRO,NAME,COND)		   
#    define SYNEIGHT__PRO__CHECK1(NAME,COND,W1) 	        SYNEIGHT__INTERNAL__CONDITION_THROW1(CHECK,PRO,NAME,COND,(W1)) 	   
#    define SYNEIGHT__PRO__CHECK2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION_THROW2(CHECK,PRO,NAME,COND,(W1),(W2)) 	   
#    define SYNEIGHT__PRO__CHECK3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION_THROW3(CHECK,PRO,NAME,COND,(W1),(W2),(W3))    
#    define SYNEIGHT__PRO__CHECK4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION_THROW4(CHECK,PRO,NAME,COND,(W1),(W2),(W3),(W4))

#  endif

#else 

#  define SYNEIGHT__PRO__CHECK(NAME,COND)              ((void)0)
#  define SYNEIGHT__PRO__CHECK1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__PRO__CHECK2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__PRO__CHECK3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__PRO__CHECK4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__CHECK(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(CHECK,TES,NAME,COND)		         
#  define SYNEIGHT__TES__CHECK1(NAME,COND,W1)          SYNEIGHT__INTERNAL__CONDITION1(CHECK,TES,NAME,COND,(W1)) 	      
#  define SYNEIGHT__TES__CHECK2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(CHECK,TES,NAME,COND,(W1),(W2)) 	   
#  define SYNEIGHT__TES__CHECK3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(CHECK,TES,NAME,COND,(W1),(W2),(W3))    
#  define SYNEIGHT__TES__CHECK4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(CHECK,TES,NAME,COND,(W1),(W2),(W3),(W4)) 

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__CHECK(NAME,COND)              ((void)0)
#  define SYNEIGHT__TES__CHECK1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__TES__CHECK2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__TES__CHECK3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__TES__CHECK4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

#endif
// vim:ts=4:sw=4
