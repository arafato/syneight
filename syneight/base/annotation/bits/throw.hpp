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
 * @version $Id: throw.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BITS__THROW_HPP
#define SYNEIGHT__ANNOTATION__BITS__THROW_HPP

#include <syneight/base/annotation/base/throw.hpp>

// deactived for non testing purposes ///////////////////////////////////////////

#if 0

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2

#  define SYNEIGHT__AUD__THROW(STATEMENT,TYPE)             SYNEIGHT__INTERNAL__THROW(AUD,(STATEMENT),TYPE)
#  define SYNEIGHT__AUD__THROW1(STATEMENT,TYPE,PRED)       SYNEIGHT__INTERNAL__THROW1(AUD,(STATEMENT),TYPE,(PRED))

#else 

#  define SYNEIGHT__AUD__THROW(STATEMENT,TYPE)             ((void)0)
#  define SYNEIGHT__AUD__THROW1(STATEMENT,TYPE,PRED)       ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > 0

#  define SYNEIGHT__DEB__THROW(STATEMENT,TYPE)             SYNEIGHT__INTERNAL__THROW(DEB,(STATEMENT),TYPE)
#  define SYNEIGHT__DEB__THROW1(STATEMENT,TYPE,PRED)       SYNEIGHT__INTERNAL__THROW1(DEB,(STATEMENT),TYPE,(PRED))

#else 

#  define SYNEIGHT__DEB__THROW(STATEMENT,TYPE)             ((void)0)
#  define SYNEIGHT__DEB__THROW1(STATEMENT,TYPE,PRED)       ((void)0)

#endif

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__BUILD_LEVEL > -1

#  define SYNEIGHT__PRO__THROW(STATEMENT,TYPE)             SYNEIGHT__INTERNAL__THROW(PRO,(STATEMENT),TYPE)
#  define SYNEIGHT__PRO__THROW1(STATEMENT,TYPE,PRED)       SYNEIGHT__INTERNAL__THROW1(PRO,(STATEMENT),TYPE,(PRED))

#else 

#  define SYNEIGHT__PRO__THROW(STATEMENT,TYPE)             ((void)0)
#  define SYNEIGHT__PRO__THROW1(STATEMENT,TYPE,PRED)       ((void)0)

#endif


#endif 

// end deactivation ////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

#if SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 1

#  define SYNEIGHT__TES__THROW(STATEMENT,TYPE)             SYNEIGHT__INTERNAL__THROW(TES,(STATEMENT),TYPE)
#  define SYNEIGHT__TES__THROW1(STATEMENT,TYPE,PRED)       SYNEIGHT__INTERNAL__THROW1(TES,(STATEMENT),TYPE,(PRED))

#elif SYNEIGHT__SWITCH__TEST_ANNOTATIONS == 0

#  define SYNEIGHT__TES__THROW(STATEMENT,TYPE)             ((void)0)
#  define SYNEIGHT__TES__THROW1(STATEMENT,TYPE,PRED)       ((void)0)

#endif

#endif
// vim:ts=4:sw=4
