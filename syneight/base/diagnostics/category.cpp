/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/category.cpp
 *
 * @author Oliver Arafat
 * @author $Author: arafat $
 *
 * @version $Id: category.cpp 1056 2005-06-07 15:04:02Z arafat $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note M1
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/category.hpp>

#include <syneight/base/diagnostics/log_sink.hpp>
#include <syneight/base/diagnostics/internal/log_sink_handle.hpp>
#include <syneight/base/diagnostics/invalid_category_name.hpp>
#include <syneight/base/diagnostics/internal/category_handle.hpp>
#include <syneight/base/diagnostics/internal/level_priority.hpp>
#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>

#include <syneight/base/exception/invalid_argument.hpp>

#include <log4cpp/Category.hh>

#include <boost/spirit/core.hpp>

#include <map>
#include <algorithm>

SYNEIGHT__BEGIN__NAMESPACE__UNNAMED;

bool U_is_name_valid(::std::string const & name)
{
    using namespace boost::spirit;

    if(name==".")
      return true;

    return parse( name.c_str(), 
		  ((+('.' >> + alnum_p)))).full;
}

SYNEIGHT__END__NAMESPACE__UNNAMED;

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

/**
 * @class Category_Manager
 *
 * @brief The @ref Category_Manager stores all @ref Category objects ever
 * instantiated. 
 *
 * Category_Manager is used internally by @ref Category and holds all ever
 * instantiated Category objects in a map of type @ref Category_Map_t.
 * Each Category object is associated (both names are identical)with a 
 * @ref Category_Handle which are stored in @ref Facility_Implementation.
 *
 * It consists of two patterns. A Singelton and a Flyweight.
 * If a category does neither exist in Category_Manager nor does
 * a catgory_handle in Facility_Implementation exist, a new category
 * will be created on the fly. See @ref Category for more details.
 *  
 * @nosubgrouping
 */
class Category_Manager
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Singleton
     * @{
     */
private:
    typedef Category_Manager Self;
    friend class To_Avoid_Compiler_Errors;
    static Self * m_instance;

    Category_Manager(Self const & other);
    Self & operator=(Self const & other);
    Category_Manager();
    ~Category_Manager();
public:
    inline static Self & instance();
    // @}
    
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Flyweight pattern for Category objects
     * @{
     */
public:
    /**
     * @brief Returns a @ref Category object with @a name.
     *
     * If a Category with @a name is not found in the
     * Category_Manager's map, this method checks if a @ref
     * Category_Handle object with @a name exists in @ref
     * Facility_Implementation. If a valid Category_Handle object is
     * found a new Category will be created and added to the
     * Category_Manager. If is not found a new handle and thus a new
     * Category will be created on the fly. See Category for details.
     *
     * @throw never
     */  
   Category & category(::std::string const & name);
private:
    typedef ::std::map< ::std::string, Category* > Category_Map_t;
    Category_Map_t m_category_map;
    // @}
};

Category_Manager * Category_Manager::m_instance = 0;

Category_Manager & Category_Manager::instance()
{
    if (m_instance == NULL)
	m_instance = new Self;
    return *m_instance;
}

Category & Category_Manager::category(::std::string const & name)
{
    if(!U_is_name_valid(name))
	throw Invalid_Category_Name(SYNEIGHT__SOURCE_LOCATION,
				    ::std::string("'" + name + "' is not a valid name!"));

    // not needed anymore because of facility_implementation.cpp change
    //
    //// looking for root category
    //// we call it ".", log4cpp/log4cxx calls it ""
    //if(name == ".") {
    //  Category_Map_t::const_iterator const iter(m_category_map.find(""));
    //  // root category always exists 
    //  return *(iter->second);
    //}
    
    // name look up
    Category_Map_t::const_iterator const iter(m_category_map.find(name));
    if (iter == m_category_map.end()) {
	// name is valid --> no throw
	return *(m_category_map[name] = 
		 new Category(Facility_Implementation::instance().category(name)));
    }
    // Category was found
    return *(iter->second);
}

Category_Manager::~Category_Manager()
{
}

Category_Manager::Category_Manager()
{
}


SYNEIGHT__END__NAMESPACE__INTERNAL;

////////////////////////////////////////////////////////////////////////////////

Category & Category::instance(::std::string const & name)
{
    // check for valid name is done within the category call
    return Category_Manager::instance().category(name);
}

Category & Category::instance(Self const & root, 
			      ::std::string const & name)
{
    // check for valid name is done within the category call    
    return Category_Manager::instance().
	category(root.name() + "." + name);
}

Category & Category::instance(Category_Handle * const handle,
			      ::std::string const & name)
{
    if(handle==NULL)
	throw Invalid_Argument(SYNEIGHT__SOURCE_LOCATION,"failed: handle!=NULL");
    // check for valid name is done within the category call
    return Category_Manager::instance().
	category(internal::to_log4cpp(handle).getName() + "." + name);
}

Category & Category::instance(Category_Handle * const handle)
{
    if(handle==NULL)
	throw Invalid_Argument(SYNEIGHT__SOURCE_LOCATION,"failed: handle!=NULL");
    // should not throw -- since handle is valid and thus
    // its name ought to be valid.
    return Category_Manager::instance().
	category(internal::to_log4cpp(handle).getName());
}

void Category::register_log_sink(Log_Sink const & log_sink)
{
    Log_Sinks_t::const_iterator const iter(::std::find(m_log_sinks.begin(), m_log_sinks.end(), &log_sink));
    if(iter == m_log_sinks.end()) {
	internal::to_log4cpp(m_handle).setAppender(log_sink.handle()->appender());
	// no change -- if the above call fails and throws
	m_log_sinks.push_back(&log_sink);
    }
}

void Category::unregister_log_sink(Log_Sink const & log_sink)
{
    using namespace internal;
    Log_Sinks_t::iterator const iter(::std::find(m_log_sinks.begin(), m_log_sinks.end(), &log_sink));
    if(iter != m_log_sinks.end()) {
	// if one of the calls throws, we are in bad luck!
	m_log_sinks.erase(iter);
	to_log4cpp(m_handle).removeAppender(&log_sink.handle()->appender());
    }
}

void Category::unregister_all_log_sinks()
{
    m_log_sinks.clear();
    internal::to_log4cpp(m_handle).removeAllAppenders();
}

Category::Log_Sinks_t const & Category::log_sinks() const
{
    return m_log_sinks;
}

void Category::level(Level_t const level)
{
    using namespace internal;
    to_log4cpp(m_handle).setPriority(level_to_priority(level));
}

Level_t Category::level() const
{
    using namespace internal;
    return (priority_to_level(to_log4cpp(m_handle).getPriority()));
}

bool Category::is_level_enabled(Level_t const level) const
{
    using namespace internal;
    if (level >= priority_to_level(to_log4cpp(m_handle).getPriority()))
	return true;
    return false;
}

void Category::additivity(bool const additivity) 
{
    internal::to_log4cpp(m_handle).setAdditivity(additivity);
}

bool Category::additivity() const
{
    return(internal::to_log4cpp(m_handle).getAdditivity());
}

::std::string const & Category::name() const
{
    return(internal::to_log4cpp(m_handle).getName());
}

Category * Category::parent() const
{
    return &(Category_Manager::instance().
	     category((internal::to_log4cpp(m_handle).getParent())->getName()));
}

Category::~Category()
{
}

Category::Category(Category_Handle * const handle)
    : m_handle(handle)
{
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;





// vim:ts=4:sw=4
