/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/invalid_category_name.hpp
 *
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: invalid_category_name.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Invalid_Category_Name
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__INVALID_CATEGORY_NAME_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__INVALID_CATEGORY_NAME_HPP

#include <syneight/base/diagnostics/exception.hpp>
#include <syneight/base/diagnostics/namespace.hpp>
#include <syneight/base/diagnostics/standard_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;


/**
 * @class Invalid_Category_Name
 *
 * @brief The exception to be used if the name of a @ref Category does not fullfill
 * a specific format. See Category for details.
 *
 * @nosubgrouping
 */
class Invalid_Category_Name
    : public Standard_Exception
{
    typedef Invalid_Category_Name Self;
    typedef Standard_Exception Super;
public:
    virtual ~Invalid_Category_Name() SYNEIGHT__EXCEPTION_NO_THROW;

    Invalid_Category_Name(Source_Location const source_location,
			  ::std::string const & name);
    
    Invalid_Category_Name(Self const & other);
    
    inline ::std::string const & name() const;

    virtual char const * class_name() const;

    virtual char const * plain_what() const;
  
  ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name State
     * @{
     */
private:
    ::std::string m_name;
    mutable ::std::string m_buffer;
    // @}
};

/////////////////////////////////////////////////////////////////////
inline ::std::string const & Invalid_Category_Name::name() const
{
    return m_name;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
