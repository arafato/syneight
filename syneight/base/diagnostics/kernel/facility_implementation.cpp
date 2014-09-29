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
 * @version $Id: facility_implementation.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/diagnostics/event.hpp>
#include <syneight/base/diagnostics/internal/level_priority.hpp>
#include <syneight/base/diagnostics/log_sink.hpp>
#include <syneight/base/diagnostics/internal/log_sink_handle.hpp>
#include <syneight/base/diagnostics/invalid_log_sink_handle_name.hpp>
#include <syneight/base/diagnostics/observer_configuration_error.hpp>

#include <syneight/base/diagnostics/category.hpp>

#include <syneight/base/diagnostics/internal/category_handle.hpp>
#include <syneight/base/diagnostics/internal/syneight_basic_layout.hpp>
#include <syneight/base/diagnostics/internal/syneight_simple_layout.hpp>
#include <syneight/base/diagnostics/internal/syneight_pattern_layout.hpp>
#include <syneight/base/diagnostics/internal/syneight_layout_appender.hpp>
#include <syneight/base/diagnostics/internal/config_failure.hpp>

#include <syneight/base/diagnostics/kernel/observer.hpp>
#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>


//#include <syneight/base/diagnostics/static_init.hpp>

#include <log4cpp/Layout.hh>
#include <log4cpp/LayoutAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/NDC.hh>

#include <iomanip>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <algorithm>
#include <unistd.h>

SYNEIGHT__BEGIN__NAMESPACE__UNNAMED;

bool
U_find_replace(
	::std::string & str,
	::std::string const &needle,
	::std::string const &target )
{
	::std::string::size_type const pos(
	str.find( needle ) );
	if ( pos != ::std::string::npos ) {
		str.replace( pos, needle.size(), target );
		return true;
	}
	return false;
}


void
U_configure( ::std::string const &name )
{
	using ::syneight::diagnostics::Configure_Failure;

	// open file
	::std::ifstream config_file( name.c_str() );
	::std::ostringstream output_file;
	if ( !config_file ) {
		throw Configure_Failure(
				SYNEIGHT__SOURCE_LOCATION,
				::std::string( "Config file does not exist: '" + name + "'" ) );
	}

	// read file
	::std::string full_line, command;
	char line[256];
	::std::string::size_type length;
	while ( config_file.getline( line, 256 ) ) {
		full_line = line;

		/* if the line contains a # then it is a comment if we find it
		 * anywhere other then the beginning, then we assume there is a
		 * command on that line, and if we don't find it at all we
		 * assume there is a command on the line (we test for a valid
		 * command later) if neither is true, we continue with the next
		 * line.
		 */
		length = full_line.find( '#' );
		if ( length == ::std::string::npos ) {
			command = full_line;
		}
		else if ( length > 0 ) {
			command = full_line.substr( 0, length );
		}
		else {
			continue;
		}

		// check the command and handle it
		length = command.find( '=' );
		if ( length != ::std::string::npos ) {
			output_file << command.substr( 0, length + 1 );
			command = command.substr( length + 1, command.size() - length );

			// find and replace priority names
			if ( U_find_replace( command, "SYS", "FATAL" ) ) {
				output_file << command << ::std::endl;
				continue;
			}
			if ( U_find_replace( command, "TES", "ALERT" ) ) {
				output_file << command << ::std::endl;
				continue;
			}
			if ( U_find_replace( command, "EME", "CRIT" ) ) {
				output_file << command << ::std::endl;
				continue;
			}
			if ( U_find_replace( command, "ALE", "ERROR" ) ) {
				output_file << command << ::std::endl;
				continue;
			}
			if ( U_find_replace( command, "PRO", "WARN" ) ) {
				output_file << command << ::std::endl;
				continue;
			}
			if ( U_find_replace( command, "DEB", "NOTICE" ) ) {
				output_file << command << ::std::endl;
				continue;
			}
			if ( U_find_replace( command, "AUD", "INFO" ) ) {
				output_file << command << ::std::endl;
				continue;
			}
			output_file << command << ::std::endl;
		}
		else {
			continue;
		}
	}

	config_file.close();
	// save the parsed config_file content in a temporary file and pass it
	// to the configurator method of log4cpp
	char temp_file_name[] = "/tmp/syneight_property_config.XXXXXX";
	int fd;
	if ( ( fd = mkstemp( temp_file_name ) ) == -1 ) {
		::std::ostringstream tmp;
		tmp << temp_file_name;
		throw Configure_Failure(
				SYNEIGHT__SOURCE_LOCATION,
				::std::string( "Couldn't create temporary file " + tmp.str() ) );
	}
	else {
		close( fd );
	}

	::std::ofstream temp_file( temp_file_name );
	temp_file << output_file.str();
	temp_file.close();
	try {
		log4cpp::PropertyConfigurator::configure( temp_file_name );
	}
	catch( ::log4cpp::ConfigureFailure & f ) {
		remove( temp_file_name );
		throw( Configure_Failure
			   ( SYNEIGHT__SOURCE_LOCATION, ::std::string( f.what() ) ) );
	}
	remove( temp_file_name );
}


SYNEIGHT__END__NAMESPACE__UNNAMED;

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

Facility_Implementation *
	Facility_Implementation::m_instance = 0;

Facility_Implementation::Facility_Implementation()
{
	/// @todo We need to implement static_init() function.
	//init();
}


Facility_Implementation::~Facility_Implementation()
{
}


Facility_Implementation::Log_Sink_Names_t const &
Facility_Implementation::log_sink_names()
{
	return m_log_sink_names;
}


void
Facility_Implementation::init()
{
	// to initalize the singleton
	instance();
	/// @todo
}


void
Facility_Implementation::load_config( ::std::string const &name )
{
	////////////////////////////////////////////////////////////////////////////
	//
	// Reconfigure log4cpp 
	//
	////////////////////////////////////////////////////////////////////////////

	// might throw Configure_Failure
	U_configure( name );

	////////////////////////////////////////////////////////////////////////////
	//
	// Reconfigure diagnostics itself
	//
	////////////////////////////////////////////////////////////////////////////

	typedef::std::vector < ::log4cpp::Category * >Cat_Vector_t;

	// Kill associations between Categories and Log Sinks //////////////////////
	Category_Handle_Map_t::const_iterator begin( m_category_handle_map.
												 begin() );
	Category_Handle_Map_t::const_iterator const end(
	m_category_handle_map.end() );
	for ( ; begin != end; ++begin )
		( Category::instance( begin->second ) ).unregister_all_log_sinks();

	// Set will contain all Appenders of a specific category.
	::log4cpp::AppenderSet appender_set;

	Cat_Vector_t *const temp_cats(
	::log4cpp::Category::getCurrentCategories() );
	Cat_Vector_t::const_iterator cat_begin( temp_cats->begin() );
	Cat_Vector_t::const_iterator const cat_end(
	temp_cats->end() );

	// In this loop we build the current set of Log_Sinks based on 
	// the log4cpp Appenders and Layouts
	for ( ; cat_begin != cat_end; ++cat_begin ) {
		appender_set = ( *cat_begin )->getAllAppenders();

		::log4cpp::AppenderSet::const_iterator begin( appender_set.
													  begin() );
		::log4cpp::AppenderSet::const_iterator const end(
			appender_set.end() );

		// Load new Log_Sink definitions
		// Old definitions won't be deleted but overwritten
		for ( ; begin != end; ++begin ) {
			::log4cpp::Appender * const appender(
				*begin );

			/// @todo KILL -- remeber, we won't need the layout directly
			/// To be done when switching to log4cxx.
			// Casting the appender into an Syneight_Layout_Appender to get its Layout.
			// In log4cpp this method is protected!
			::log4cpp::Layout * tmp =
				static_cast <
				internal::Syneight_Layout_Appender * >( appender )
				->get_layout();


			// Casting original layouts to syneight layouts (are derived from
			// the orginal layouts!), 
			// which use type Level_t for Priority

			// if (typeid(*tmp) == typeid(*(new ::log4cpp::SimpleLayout()))) {
			if ( dynamic_cast < ::log4cpp::SimpleLayout * >( tmp ) != NULL )
				appender->
					setLayout( new internal::Syneight_Simple_Layout() );
			else if ( dynamic_cast < ::log4cpp::BasicLayout * >( tmp ) !=
					  NULL )
				appender->setLayout( new internal::Syneight_Basic_Layout() );
			else if ( dynamic_cast < ::log4cpp::PatternLayout * >( tmp ) !=
					  NULL ) {
				internal::Syneight_Pattern_Layout * const layout(
	new internal::Syneight_Pattern_Layout() );
				layout->
					setConversionPattern( static_cast < ::log4cpp::
										  PatternLayout *
										  >( tmp )->
										  getConversionPattern() );
				appender->setLayout( layout );
			}
			// Storing Log_Sink_Handle in Log_Sink_Handle_Map
			// Either it's a new one or it will be overwritten
			/// @todo the null is filler for a layout
			m_log_sink_handle_map[appender->getName()] =
				new Log_Sink_Handle( appender, appender->getName() );

			// Registering Log_Sink to Category and store category handle in category_handle_map 
			if ( ( *cat_begin )->getName() == "" )
				// special case root category: it comes with
				// the empty name, which is invalid -- the 
				// proper name is "."
				Category::instance( "." ).
					register_log_sink( Log_Sink::
									   instance( appender->getName() ) );
			else
				Category::instance( ( *cat_begin )->getName() ).
					register_log_sink( Log_Sink::
									   instance( appender->getName() ) );

			m_log_sink_names.push_back( appender->getName() );
		}
	}
}

Log_Sink_Handle *
Facility_Implementation::log_sink(
	::std::string const &name )
{
	Log_Sink_Handle_Map_t::const_iterator const iter(
	m_log_sink_handle_map.find( name ) );

	if ( iter == m_log_sink_handle_map.end() )
		throw Invalid_Log_Sink_Handle_Name(
				SYNEIGHT__SOURCE_LOCATION,
				::std::string( "'" + name +
				   "' is not a registered Log_Sink_Handle object!" ) );
	return iter->second;
}


Category_Handle *
Facility_Implementation::category( ::std::string const &name )
{
	Category_Handle_Map_t::const_iterator const iter(
	m_category_handle_map.find( name ) );

	if ( iter != m_category_handle_map.end() )
		return iter->second;

	return m_category_handle_map[name] = internal::get_category( name );
}

Category_Handle *
Facility_Implementation::category(
	Category_Handle * const root,
	::std::string const &name )
{
	Category_Handle_Map_t::const_iterator const iter =
		m_category_handle_map.find( internal::to_log4cpp( root ).getName()
									+ "." + name );

	if ( iter != m_category_handle_map.end() )
		return iter->second;

	return m_category_handle_map[name] = internal::get_category( name );
}

void
Facility_Implementation::register_observer( Observer & observer )
{
	Observers_t::const_iterator const iter(
	::std::find( m_observers.begin(),
				 m_observers.end(),
				 &observer ) );
	if ( iter != m_observers.end() )
		throw Observer_Configuration_Error(
				SYNEIGHT__SOURCE_LOCATION,
				::std::string( "Double registration of an observer!" ) );
	m_observers.push_back( &observer );
	m_is_observing = true;
}

void
Facility_Implementation::unregister_observer( Observer & observer )
{
	Observers_t::iterator const iter(
	::std::find( m_observers.begin(),
				 m_observers.end(),
				 &observer ) );
	if ( iter == m_observers.end() )
		throw Observer_Configuration_Error(
				SYNEIGHT__SOURCE_LOCATION,
				::std::string( "Unregistration of an observer failed!" ) );

	m_observers.erase( iter );
	m_is_observing = m_observers.size() != 0;
}


void
Facility_Implementation::log(
	Category_Handle * const category,
	Level_t const level,
	Type_t const type,
	::std::string const &what,
	int const nr_what,
	char const *const base_file_name,
	char const *const file_name,
	int const line )
{

	/// @todo long term -- clean up the WORKING mess (tid,pid,timestamp,hostname)

	Source_Location const source_location(
	file_name,
	base_file_name,
	line );

	// send event to @ref Observer (if any)
	if ( m_is_observing ) {
		Event const event(
	category,
	level,
	type,
	what,
	nr_what,
	source_location );

		Observers_t::const_iterator begin( m_observers.begin() );
		Observers_t::const_iterator const end(
	m_observers.end() );
		for ( ; begin != end; ++begin )
			( *begin )->log( event );
	}

	// Create LoggingEvent
	::std::ostringstream message;
	message	//<< ::std::setiosflags(::std::ios_base::left) << ::std::setw(15)
		<< type_to_string( type ) << " : " << what << ' '
		<< nr_what << ' ' << source_location;
	::log4cpp::LoggingEvent event( internal::to_log4cpp( category ).getName(),
								   message.str(), ::log4cpp::NDC::get(),
								   internal::level_to_priority( level ) );


	// Send event to log4cpp
	internal::to_log4cpp( category ).callAppenders( event );
}


void
Facility_Implementation::log(
	Category_Handle * const category,
	Level_t const level,
	Type_t const type,
	::std::string const &what,
	int const nr_what,
	Source_Location const &source_location )
{
	/// @todo long term -- keep in sync with other log

	// send event to @ref Observer (if any)
	if ( m_is_observing ) {
		Event const event(
	category,
	level,
	type,
	what,
	nr_what,
	source_location );

		Observers_t::const_iterator begin( m_observers.begin() );
		Observers_t::const_iterator const end(
	m_observers.end() );
		for ( ; begin != end; ++begin )
			( *begin )->log( event );
	}

	// Create LoggingEvent
	::std::ostringstream message;
	message	//<< ::std::setiosflags(::std::ios_base::left) << ::std::setw(15)
		<< type_to_string( type ) << " : " << what << ' '
		<< nr_what << ' ' << source_location;
	::log4cpp::LoggingEvent event( internal::to_log4cpp( category ).getName(),
								   message.str(), ::log4cpp::NDC::get(),
								   internal::level_to_priority( level ) );


	// Send event to log4cpp
	internal::to_log4cpp( category ).callAppenders( event );
}


void
Facility_Implementation::panic_log(
	Category_Handle * const category,
	Level_t const level,
	Type_t const type,
	::std::string const &what,
	int const nr_what,
	char const *const base_file_name,
	char const *const file_name,
	int const line )
{
	panic_log( category, level, type, what, nr_what,
			   Source_Location( file_name, base_file_name, line ) );
}


void
Facility_Implementation::panic_log(
	Category_Handle * const category,
	Level_t const level,
	Type_t const type,
	::std::string const &what,
	int const nr_what,
	Source_Location const &source_location )
{
	::std::cerr << internal::to_log4cpp( category ).getName() << ' '
		<< level_to_string( level ) << ' '
		<< type_to_string( type ) << ": "
		<< what << ' ' << nr_what << ' ' << source_location << ::std::endl;
}


SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
