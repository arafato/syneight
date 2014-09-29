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
 * @version $Id: assert.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__ASSERT_HPP
#define SYNEIGHT__ANNOTATION__BITS__ASSERT_HPP

#include <syneight/base/annotation/base/condition.hpp>

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__ASSERT(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(ASSERT,AUD,NAME,COND)
#  define SYNEIGHT__AUD__ASSERT1(NAME,COND,W1)          SYNEIGHT__INTERNAL__CONDITION1(ASSERT,AUD,NAME,COND,(W1)) 
#  define SYNEIGHT__AUD__ASSERT2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(ASSERT,AUD,NAME,COND,(W1),(W2)) 
#  define SYNEIGHT__AUD__ASSERT3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(ASSERT,AUD,NAME,COND,(W1),(W2),(W3)) 
#  define SYNEIGHT__AUD__ASSERT4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(ASSERT,AUD,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__AUD__ASSERT(NAME,COND)              ((void)0)
#  define SYNEIGHT__AUD__ASSERT1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__AUD__ASSERT2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__AUD__ASSERT3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__AUD__ASSERT4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__ASSERT(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(ASSERT,DEB,NAME,COND)		   
#  define SYNEIGHT__DEB__ASSERT1(NAME,COND,W1) 	       SYNEIGHT__INTERNAL__CONDITION1(ASSERT,DEB,NAME,COND,(W1)) 	   
#  define SYNEIGHT__DEB__ASSERT2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(ASSERT,DEB,NAME,COND,(W1),(W2)) 	   
#  define SYNEIGHT__DEB__ASSERT3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(ASSERT,DEB,NAME,COND,(W1),(W2),(W3))    
#  define SYNEIGHT__DEB__ASSERT4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(ASSERT,DEB,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__DEB__ASSERT(NAME,COND)              ((void)0)
#  define SYNEIGHT__DEB__ASSERT1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__DEB__ASSERT2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__DEB__ASSERT3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__DEB__ASSERT4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__ASSERT(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(ASSERT,PRO,NAME,COND)		   
#  define SYNEIGHT__PRO__ASSERT1(NAME,COND,W1) 	       SYNEIGHT__INTERNAL__CONDITION1(ASSERT,PRO,NAME,COND,(W1)) 	   
#  define SYNEIGHT__PRO__ASSERT2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(ASSERT,PRO,NAME,COND,(W1),(W2)) 	   
#  define SYNEIGHT__PRO__ASSERT3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(ASSERT,PRO,NAME,COND,(W1),(W2),(W3))    
#  define SYNEIGHT__PRO__ASSERT4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(ASSERT,PRO,NAME,COND,(W1),(W2),(W3),(W4)) 

#else 

#  define SYNEIGHT__PRO__ASSERT(NAME,COND)              ((void)0)
#  define SYNEIGHT__PRO__ASSERT1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__PRO__ASSERT2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__PRO__ASSERT3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__PRO__ASSERT4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__ASSERT(NAME,COND)              SYNEIGHT__INTERNAL__CONDITION(ASSERT,TES,NAME,COND)		         
#  define SYNEIGHT__TES__ASSERT1(NAME,COND,W1)          SYNEIGHT__INTERNAL__CONDITION1(ASSERT,TES,NAME,COND,(W1)) 	      
#  define SYNEIGHT__TES__ASSERT2(NAME,COND,W1,W2)       SYNEIGHT__INTERNAL__CONDITION2(ASSERT,TES,NAME,COND,(W1),(W2)) 	   
#  define SYNEIGHT__TES__ASSERT3(NAME,COND,W1,W2,W3)    SYNEIGHT__INTERNAL__CONDITION3(ASSERT,TES,NAME,COND,(W1),(W2),(W3))    
#  define SYNEIGHT__TES__ASSERT4(NAME,COND,W1,W2,W3,W4) SYNEIGHT__INTERNAL__CONDITION4(ASSERT,TES,NAME,COND,(W1),(W2),(W3),(W4)) 

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__ASSERT(NAME,COND)              ((void)0)
#  define SYNEIGHT__TES__ASSERT1(NAME,COND,W1)          ((void)0)
#  define SYNEIGHT__TES__ASSERT2(NAME,COND,W1,W2)       ((void)0)
#  define SYNEIGHT__TES__ASSERT3(NAME,COND,W1,W2,W3)    ((void)0)
#  define SYNEIGHT__TES__ASSERT4(NAME,COND,W1,W2,W3,W4) ((void)0)

#endif

#endif
// vim:ts=4:sw=4
