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
 * @version $Id: namespace_category.impl.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__CONFIG__NAMESPACE_CATEGORY_IMPL_HPP
#define SYNEIGHT__CONFIG__NAMESPACE_CATEGORY_IMPL_HPP

#include <syneight/base/config/namespace_category.hpp>
#include <syneight/base/diagnostics/management_facility.hpp>
#include <syneight/base/diagnostics/category.hpp>
#include <syneight/base/diagnostics/invalid_category_name.hpp>

#include <cstdlib>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
class Category_Handle;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

/// @todo make this thread safe.
/// add a try catch to the emergency handle

#define SYNEIGHT__NAMESPACE_CATEGORY_IMPLEMENTATION(NAME) \
::syneight::diagnostics::Category_Handle * Internal_Do_Not_Use_Category_Holder::handle=NULL; \
\
void Internal_Do_Not_Use_Category_Holder::category_handle_nothrow() \
{ \
   try { \
     category_handle_throwing(); \
   } \
   catch(::syneight::diagnostics::Invalid_Category_Name & e) { \
                                      \
   } \
   catch(...) { \
      \
   } \
   \
   if(handle==NULL) { \
     handle= ::syneight::diagnostics::Category::instance(".ERROR").handle(); \
   } \
} \
\
void Internal_Do_Not_Use_Category_Holder::category_handle_throwing() \
{ \
  handle= ::syneight::diagnostics::Category::instance(NAME).handle(); \
} 


#endif
// vim:ts=4:sw=4
