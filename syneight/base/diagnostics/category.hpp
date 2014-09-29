/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/category.hpp
 *
 * @author Christian Schallhart
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: category.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Category
 *
 * TODO: Long description.
 *
 * @note M1
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGSNOTICS__CATEGORY_HPP
#define SYNEIGHT__BASE__DIAGSNOTICS__CATEGORY_HPP

#include <syneight/base/diagnostics/level.hpp>

#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;
class Category_Manager;
SYNEIGHT__END__NAMESPACE__INTERNAL;


class Category_Handle;
class Log_Sink;

/**
 * @class Category
 *
 * @brief Category is the central class in the namespace
 * ::syneight::diagnostics wrt. the configuration of the diagnostics
 * framework. It is responsible for whether a message will be logged
 * -- depending on its level (@ref Level_t).
 *
 * Every Category instance has an assigned level. A message will be
 * logged if its level is <= than the level of the category it is send
 * to. Depending on its additivity-flag, log messages will be further
 * passed to its ancestors(if there are any).  
 *
 * All details on the location and the format of actual logs are
 * encapsulated within the registered @ref Log_Sink objects.
 *
 * A category object is used to read/alter logging configuration
 * properties, but is not used to do actual logging. Instead, a @ref
 * Category_Handle which is associated uniquely with a Category is
 * used for logging. The reason for doing so is performance. 
 *
 * The Category is uniquely identified by its name. On specifying its
 * name (or equivalently its @ref Category_Handle) a static method
 * returns the corresponding Category -- same state implies same
 * identity.
 *
 * @nosubgrouping
 */
class Category
{
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Creation
     * @{
     */
private:
    typedef Category Self;
    typedef internal::Category_Manager Category_Manager;
public:
    friend class Category_Manager;

    /**
     * @brief Returns the Category for @a name (@a name is interpreted
     * as absolute path). If the Category for @a name does not exist,
     * it is created on the fly. In the latter case it will have no
     * specific configuration, i.e., it will behave like its parent
     * until configured differently. More specifically, a message sent
     * to the new category will be sent to the same @ref Log_Sink
     * objects as if it would be sent to its partent.
     *
     * If the category is newly created, then its additivity flag is set
     * to true and no Log_Sinks are added.
     *
     * Note that @a name has to follow a specific format. In
     * particular, @a name is formated as ('.'|((.<NAME>)+)), where
     * <NAME> can be any non-empty alpha-numerical string with
     * underscores. Thus, ".X", ".X.Y" are valid names. "", "X", "X.",
     * ".X."  ".Y-X" are invalid.  The global root category has an
     * empty name, thus it can be retrieved with ".".
     *
     * If called with ".X.Y", then the method returns the category
     * of name "Y", which is child of category "X", which is child of
     * the root category.
     *
     * @pre @a name is valid
     *
     * @throw Invalid_Category_Name
     *
     */ 
    static Category & instance(::std::string const & name);
    
    /**
     * @brief Constructs child category of @a root with @a name, i.e.,
     * @a name is interpreted relatively to @a root.
     *
     * Equivalent to Category(<name of @a root> + "." + @a
     * name).
     * 
     * @pre @a name is valid and non-empty (same as in the above
     * method, but without leading dot ('.'), i.e., (<NAME>
     * (.<NAME>)*)).
     *
     * @throw Invalid_Category_Name
     *
     */
    static Category & instance(Self const & root,
			       ::std::string const & name);


    /**
     * @brief Constructs a category of @a handle
     *
     * @pre @a handle != NULL
     *
     * @pre [UNCHECKED] @a handle is valid, i.e, it must be the
     * result of a call to handle()
     *
     * @pre @a name is valid
     *
     * @throw Invalid_Argument
     */
    static Category & instance(Category_Handle * const handle);
    
    /**
     * @brief Constructs child category of @a handle.
     *
     * @pre @a handle != NULL 
     *
     * @pre [UNCHECKED] @a handle is valid, i.e., it must be the
     * result of a call to handle().
     *
     * @pre @a name is valid
     *
     * @throw Invalid_Argument
     * @throw Invalid_Category_Name
     */
    static Category & instance(Category_Handle * const handle,
			       ::std::string const & name);
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Disallowed Construction/Destruction
     * @{
     */
private:
    Category(Self const & other);
    Self & operator=(Self const & other);
    Category();
    ~Category();
    explicit Category(Category_Handle * const handle);
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Category Handles
     * @{
     */
public:
    /**
     * @brief Returns a category handle of this category instance.
     * This handle is used to call actual logging methods -- see @ref
     * Facility.
     *
     * @throw never
     */
    inline Category_Handle const * handle() const;

    /**
     * @brief Returns a category handle of this category instance.
     * This handle is used to call actual logging methods -- see @ref
     * Facility.
     *
     * @throw never
     */
    inline Category_Handle * handle();
    // @}


    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Log_Sink Registration
     * @{
     */
public:
    /**
     * @brief Used to maintain sets of  @ref Log_Sink objects.
     */
    typedef ::std::vector < Log_Sink const *> Log_Sinks_t;

    /**
     * @brief Registers a @a log_sink. After registering a @ref Log_Sink
     * to a category instance, all @ref Event objects matching this
     * category will be sent to the @ref Log_Sink.
     *
     * Which @ref Event do match? Those events which have a level
     * which >= level() match.
     *
     * @note Double registration of the same @a log_sink is a NOOP.
     *
     * @throw never
     */
    void register_log_sink(Log_Sink const & log_sink); 

    /**
     * @brief Unregisters a @a log_sink from the Category. Afterwards,
     * no @ref Event will be sent from the Category to the @a
     * log_sink. See register_log_sink.
     *
     * @note If @a log_sink is not registered, this operation is a
     * NOOP.
     *
     * @throw never
     */
    void unregister_log_sink(Log_Sink const & log_sink);


    /**
     * @brief Unregisters all @ref Log_Sink objects currently assigned
     * to this category.
     *
     * @throw never
     */
    void unregister_all_log_sinks();


    /**
     * @brief Returns all @ref Log_Sink objects currently assigned to
     * this category instance.
     *
     * @throw never
     */
    Log_Sinks_t const & log_sinks() const;
    // @}

    
    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name Category Properties
     * @{
     */
public:
    /**
     * @brief Sets Level of this category instance to @a level. The
     * actual level of a Category determines which @ref Event objects
     * are sent to the registered @ref Log_Sink objects.
     *
     * If @a level <= the level of an @ref Event object, then the
     * event is logged.
     *
     * @throw never
     */
    void level(Level_t const level);

    /**
     * @brief Returns the Level of this category instance. 
     * 
     * @throw never
     */
    Level_t level() const ;

    /**
     * @brief Returns true if level of category instance is equal
     * or higher than @a level, otherwise it returns false.
     *
     * @throw never
     */
    bool is_level_enabled(Level_t const level) const;
    
    /**
     * @brief Sets the additivity-flag for this category instance. If
     * set to true, @ref Event objects will be forwarded to the
     * ancestors of this instance.
     *
     * The output of a log statement of category C will go to all the
     * appenders in C and its ancestors. This is the meaning of the
     * term "appender additivity".
     *
     * However, if an ancestor of category C, say P, has the additivity flag
     * set to false, then C's output will be directed to all the appenders
     * in C and it's ancestors upto and including P but not the appenders
     * in any of the ancestors of P (C might equal P).
     *
     * @throw never
     */
    void additivity(bool const additivity);

    /**
     * @brief Returns true if additivity_flag is set for this category
     * instance, otherwise it returns false.
     *
     * @throw never
     */
    bool additivity() const;

    /**
     * @brief Returns the name of the category instance.
     *
     * @throw never
     */
    ::std::string const & name() const;

    /**
     * @brief Returns the parent of this category.
     * Returns NULL if this category is the root category.
     *
     * @throw never
     */
    Category * parent() const;
    // @}

    ////////////////////////////////////////////////////////////////////////////////
    /**
     * @name State
     * @{
     */
private:
    Category_Handle * m_handle;
    Log_Sinks_t m_log_sinks;
    // @}
};

////////////////////////////////////////////////////////////////////////////////

inline Category_Handle * Category::handle() 
{
    return m_handle;
}

inline Category_Handle const * Category::handle() const
{
    return m_handle;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
