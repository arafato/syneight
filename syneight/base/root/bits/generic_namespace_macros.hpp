/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/root/bits/generic_namespace_macros.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: generic_namespace_macros.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief Provides @ref SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE and
 * @ref SYNEIGHT__BASE__GENERIC_END_NAMESPACE
 *
 * These two macros are used to declare new namespace marocs which
 * enforce correct usage as far as possible. More precisely, they
 * enforce that
 * @arg a semi-colon is placed after them, 
 * @arg their usages form proper nesting.
 *
 * The latter means that
 *
 * SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE(NS1); SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE(NS2); 
 *
 * must be followed by 
 *
 * SYNEIGHT__BASE__GENERIC_END_NAMESPACE(NS2); SYNEIGHT__BASE__GENERIC_END_NAMESPACE(NS1); 
 *
 * Missing one of the ending macros, adding another one, or changing
 * their order is mistake that will lead to a compile time error.
 *
 * Currently, these macros do not report an error if somebody would use 
 *
 * SYNEIGHT__BASE__GENERIC_END_NAMESPACE(NS1); SYNEIGHT__BASE__GENERIC_END_NAMESPACE(NS1); 
 * 
 * in the example above.
 *
 * @todo close the last error possibility
 *
 * @note DOCUMENTED -- NO TEST
 */

#ifndef SYNEIGHT__BASE__ROOT__BITS__GENERIC_NAMESPACE_MACROS_HPP
#define SYNEIGHT__BASE__ROOT__BITS__GENERIC_NAMESPACE_MACROS_HPP


/**
 * @brief Opens a namesapce of with name @a NAME. Requires that the
 * macros instantiation is terminated by a semi-colon and that a
 * corresponding instantiation of @ref
 * SYNEIGHT__BASE__GENERIC_END_NAMESPACE(@a NAME) is used.
 */ 
#define SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE(NAME) \
namespace NAME { namespace NS__USELESS__NS__ ## NAME {typedef int NS__USELESS__ ## NAME;} \
void NS__USELESS_FUN1__ ## NAME (int)

/**
 * @brief See @ref SYNEIGHT__BASE__GENERIC_BEGIN_NAMESPACE
 */  
#define SYNEIGHT__BASE__GENERIC_END_NAMESPACE(NAME) \
void NS__USELESS_FUN2__ ## NAME (NS__USELESS__NS__ ## NAME :: NS__USELESS__ ## NAME); } \
void NS__USELESS_FUN_NEVER_USE_THIS (int)

#endif

