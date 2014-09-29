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
 * @version $Id: namespace_category.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__CONFIG__NAMESPACE_CATEGORY_HPP
#define SYNEIGHT__CONFIG__NAMESPACE_CATEGORY_HPP

#include <syneight/base/diagnostics/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
class Category_Handle;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


#define SYNEIGHT__NAMESPACE_CATEGORY_INTERFACE \
class Internal_Do_Not_Use_Category_Holder \
{ \
public: \
    static ::syneight::diagnostics::Category_Handle * handle; \
public: \
    static void category_handle_nothrow();  \
    static void category_handle_throwing(); \
 \
    friend ::syneight::diagnostics::Category_Handle * category_handle(); \
    friend ::syneight::diagnostics::Category_Handle * category_handle_throwing(); \
};\
inline ::syneight::diagnostics::Category_Handle * category_handle() \
{ \
    if(Internal_Do_Not_Use_Category_Holder::handle==NULL) { \
	Internal_Do_Not_Use_Category_Holder::category_handle_nothrow(); \
    } \
    return Internal_Do_Not_Use_Category_Holder::handle; \
} \
\
inline ::syneight::diagnostics::Category_Handle * category_handle_safe() \
{ \
    if(Internal_Do_Not_Use_Category_Holder::handle==NULL) { \
	Internal_Do_Not_Use_Category_Holder::category_handle_throwing(); \
    } \
    return Internal_Do_Not_Use_Category_Holder::handle; \
} \


#endif
// vim:ts=4:sw=4
