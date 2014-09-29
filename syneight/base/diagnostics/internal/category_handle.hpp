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
 * @version $Id: category_handle.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__DIAGSNOTICS__INTERNAL__CATEGORY_HANDLE_HPP
#define SYNEIGHT__DIAGSNOTICS__INTERNAL__CATEGORY_HANDLE_HPP

#include <syneight/base/diagnostics/namespace.hpp>

#include <log4cpp/Category.hh>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

class Category_Handle
{
private:
    Category_Handle();
    ~Category_Handle();
    Category_Handle & operator=(Category_Handle const &);
    friend class To_Avoid_Compiler_Errors;
};


SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

inline ::log4cpp::Category & to_log4cpp(Category_Handle * const category)
{
    return *static_cast< ::log4cpp::Category*>(static_cast<void*>(category));
}

inline ::log4cpp::Category const & to_log4cpp(Category_Handle const * const category)
{
    return *static_cast< ::log4cpp::Category const *>(static_cast<void const *>(category));
}

inline Category_Handle * to_diagnostics(::log4cpp::Category & category)
{
    return static_cast<Category_Handle*>(static_cast<void*>(&category));
}

inline Category_Handle const * to_diagnostics(::log4cpp::Category const & category)
{
    return static_cast<Category_Handle const*>(static_cast<void const *>(&category));
}


Category_Handle * get_category(::std::string const & ref_name); 

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
