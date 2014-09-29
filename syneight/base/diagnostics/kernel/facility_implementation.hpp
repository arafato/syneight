/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/kernel/facility_implementation.hpp
 *
 * @author Christian Schallhart
 * @author Oliver Arafat
 * @author $Author: (local) $
 *
 * @version $Id: facility_implementation.hpp 1053M 2007-12-02 16:29:45Z (local) $
 *
 * @brief @ref syneight::diagnostics::kernel::Facility_Implementation
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__KERNEL__FACILITY_IMPLEMENTATION_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__KERNEL__FACILITY_IMPLEMENTATION_HPP

#include <syneight/base/diagnostics/level.hpp>
#include <syneight/base/diagnostics/type.hpp>

#include <map>
#include <string>
#include <vector>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
class Source_Location;

SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;
class Category_Handle;
class Log_Sink_Handle;
class Observer;
class Log_Sink;

/**
 * @class Facility_Implementation
 *
 * @brief The @ref Facility_Implementation is used the kernel
 * implementation of the @ref Facility and the @ref
 * Facility_Implementation. 
 *
 * @todo add some ref on the kernel concept.
 *
 * @nosubgrouping
 */
class Facility_Implementation
{
	////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Types
	 * @{
	 */
  private:
	typedef Facility_Implementation Self;
	typedef::std::vector < Observer * >Observers_t;
	typedef::std::map < ::std::string, Category_Handle * >Category_Handle_Map_t;
	typedef::std::map < ::std::string, Log_Sink_Handle * >Log_Sink_Handle_Map_t;
  public:
	/// @brief This type is also defined (redundantly) in @ref Log_Sink
	typedef::std::vector < ::std::string > Log_Sink_Names_t;
	// @}

	////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Singelton 
	 * @{
	 */
  private:
	friend class To_Avoid_Compiler_Errors;
	static Self *m_instance;

	Facility_Implementation();
	~Facility_Implementation();
	Facility_Implementation( Self const &other );
	Self & operator=( Self const &other );
  public:
	inline static Self & instance();
	// @}


	////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Facility Interface
	 *
	 * @brief Behaves like the @ref Facility -- but does not use the
	 * @ref Diagnostics_Guard
	 *
	 * @{
	 */
  public:
	void log(
		Category_Handle * const category,
		Level_t const level,
		Type_t const type,
		::std::string const &what,
		int const nr_what,
		char const *const base_file_name,
		char const *const file_name,
		int const line );

	void log(
		Category_Handle * const category,
		Level_t const level,
		Type_t const type,
		::std::string const &what,
		int const nr_what,
		Source_Location const &source_location );

	void panic_log(
		Category_Handle * const category,
		Level_t const level,
		Type_t const type,
		::std::string const &what,
		int const nr_what,
		char const *const base_file_name,
		char const *const file_name,
		int const line );

	void panic_log(
		Category_Handle * const category,
		Level_t const level,
		Type_t const type,
		::std::string const &what,
		int const nr_what,
		Source_Location const &source_location );
	// @}


	////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Management_Facility Interface
	 *
	 * @brief Behaves like the @ref Facility -- but does not use the
	 * @ref Diagnostics_Guard
	 *
	 * @{
	 */
  public:
	void load_config( ::std::string const &name );
	void init();
	Log_Sink_Names_t const &log_sink_names();
	Category_Handle *category( ::std::string const &name );
	Category_Handle *category(Category_Handle * const root,
				  ::std::string const &name );
	void register_observer( Observer & observer );
	void unregister_observer( Observer & observer );
	// @}


	////////////////////////////////////////////////////////////////////////////
	/**
	 * @name Interface for Log_Sink (DO NOT USE OTHERWISE)
	 * @{
	 */
  public:
	/**
	 * @brief Returns a @ref Log_Sink_Handle object with @name if it is
	 * found in the Log_Sink_Handle map. 
	 *
	 * @throw Invalid_Log_Sink_Handle_Name
	 */
	Log_Sink_Handle * log_sink( ::std::string const &name );
	// @}


	////////////////////////////////////////////////////////////////////////////
	/**
	 * @name State
	 * @{
	 */
  private:
	Log_Sink_Names_t m_log_sink_names;
	Observers_t m_observers;
	Category_Handle_Map_t m_category_handle_map;
	Log_Sink_Handle_Map_t m_log_sink_handle_map;
	bool m_is_observing;
	// @}
};


Facility_Implementation & Facility_Implementation::instance()
{
	if ( m_instance == NULL )
		m_instance = new Self;
	return *m_instance;
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif

// vim:ts=4:sw=4
