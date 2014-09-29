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
 * @version $Id: guard.cpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#include <syneight/base/memory_monitoring/guard.hpp>

#include <syneight/base/memory_monitoring/tick.hpp>

#include <syneight/base/diagnostics/type.hpp>
 
#include <syneight/base/diagnostics/kernel/diagnostics_guard.hpp>
#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>
#include <syneight/base/memory_monitoring/kernel/memory_monitoring_facility_implementation.hpp>


#include <syneight/base/util/string.hpp>

#include <string>
#include <stack>
#include <algorithm>

/// @todo document
#ifndef SYNEIGHT__PARAM__LEAK_REPORT_SIZE
#  define SYNEIGHT__PARAM__LEAK_REPORT_SIZE 128
#endif

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__MEMORY_MONITORING;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

class Frame
{
private:
    typedef Frame Self;
    typedef ::syneight::diagnostics::Level_t Level_t;
    typedef ::syneight::diagnostics::Category_Handle Category_Handle;

private:
    Frame(Self const & other);
    Self & operator=(Self const & other);
public:
    Frame(bool const logging,
	  bool const balance, 
	  Level_t const level,
	  char const * const base_file_name,
	  char const * const file_name,
	  int const line,
	  Category_Handle * const category_handle);
    ~Frame();
    
    void assert_balance(Level_t const level,
			char const * const base_file_name,
			char const * const file_name,
			int const line,
			Category_Handle * const category_handle) const;
    
    void balance(::std::size_t & size,Tick_t & number) const;
    
public: // we allow public access to constant fields
    bool const m_logging;
    bool const m_balance;
    Level_t const m_level;
    char const * const m_base_file_name;
    char const * const m_file_name;
    int const m_line;
    Category_Handle * const m_category_handle;
    Tick_t const m_start_tick;
    
private:
    ::std::size_t m_total_size;
    Tick_t m_total_number;
};

void Frame::balance(::std::size_t & size,Tick_t & number) const
{
    Facility_Implementation::get_instance().
	balance(m_start_tick,size,number);
}

Frame::Frame(bool const logging,
	     bool const balance, 
	     Level_t const level,
	     char const * const base_file_name,
	     char const * const file_name,
	     int const line,
	     Category_Handle * const category_handle)
    : m_logging(logging),
      m_balance(balance),
      m_level(level),
      m_base_file_name(base_file_name),
      m_file_name(file_name),
      m_line(line),
      m_category_handle(category_handle),
      // first entry AFTER the current one
      m_start_tick(Facility_Implementation::get_instance().
		   creation_tick()+1)
{
    // get current TOTAL balance
    Facility_Implementation::get_instance().
	balance(m_total_size,m_total_number);
    
    // swtich on analysis/logging
    Facility_Implementation::get_instance().
	analysis_on(m_logging);
    
    // log the analyis start
    diagnostics::Facility_Implementation::instance().
	log(diagnostics::Facility_Implementation::instance().category(m_category_handle,"mem"),
	    m_level, 
	    ::syneight::diagnostics::MEMORY_ANALYSIS_ENTER_TYPE,
	    ::std::string("Logging: ")
	    + (logging ? "ON  Balance: " : "OFF Balance: ")
	    + (balance ? "ON" : "OFF"),
	    0,
	    m_base_file_name,
	    m_file_name,
	    m_line);
}

void Frame::assert_balance(Level_t const level,
			   char const * const base_file_name,
			   char const * const file_name,
			   int const line,
			   Category_Handle * const base_category_handle) const
{
    using ::syneight::baseutil::to_string;
    
    Category_Handle * const category_handle
	(diagnostics::Facility_Implementation::instance().category(base_category_handle,"mem"));
    
    // OBTAIN RELEVANT DATA ///////////////////////////////////////////////////////////
    
    // balance relative to m_start_tick
    ::std::size_t size;
    Tick_t number;
    Facility_Implementation::get_instance().balance(m_start_tick,size,number);
    
    // total balance
    ::std::size_t total_size;
    Tick_t total_number;
    Facility_Implementation::get_instance().balance(total_size,total_number);
    
	
    // CHECK FOR LEAK ///////////////////////////////////////////////////////////////
    // note: we check for the number of blocks -- allocations of
    // size 0 are valid -- and must be freed again
    
    if(number>0){ // leak 
	::std::string what(to_string("Size=",size," Number=",number," ["));

	// obtain ticks list
	Tick_t ticks[SYNEIGHT__PARAM__LEAK_REPORT_SIZE];
	Tick_t * ticks_begin(ticks);
	Tick_t * const ticks_end
	    (Facility_Implementation::get_instance().
	     unallocated_blocks(m_start_tick,ticks,ticks+SYNEIGHT__PARAM__LEAK_REPORT_SIZE));
	::std::sort(ticks_begin,ticks_end);
	what+=to_string(*ticks_begin);
	for(++ticks_begin;ticks_begin!=ticks_end;++ticks_begin){
	    what+=',';
	    what+=to_string(*ticks_begin);
	}
	what+=']';
	
	diagnostics::Facility_Implementation::instance().
	    log(category_handle,
		level, 
		::syneight::diagnostics::MEMORY_LEAK_TYPE,
		what,
		0,
		base_file_name,
		file_name,
		line);
	
	// compensate for the leak to check for anti-leak
	total_size-=size;
	total_number-=number;
    }
    
    // CHECK FOR ANTI-LEAK /////////////////////////////////////////////////////////////////
    
    if(total_number<m_total_number) { // anti leak
	diagnostics::Facility_Implementation::instance().
	    log(category_handle,
		level, 
		::syneight::diagnostics::MEMORY_ANTI_LEAK_TYPE,
		to_string("Size=",m_total_size-total_size,
			  " Number=",m_total_number-total_number),
		0,
		base_file_name,
		file_name,
		line);
    }
    else if(total_number>m_total_number) { // something wired happend
	diagnostics::Facility_Implementation::instance().
	    log(category_handle,
		::syneight::diagnostics::EME_LEVEL, 
		::syneight::diagnostics::FAILED_ASSERT_TYPE,
		to_string("Failed Leak Compensation Size=",m_total_size-total_size,
			  " Number=",m_total_number-total_number),
		0,
		base_file_name,
		file_name,
		line);
    }
}

Frame::~Frame() 
{
    // log the analyis end
    diagnostics::Facility_Implementation::instance().
	log(diagnostics::Facility_Implementation::instance().category(m_category_handle,"mem"),
	    m_level, 
	    ::syneight::diagnostics::MEMORY_ANALYSIS_EXIT_TYPE,
	    ::std::string("Logging: ")
	    + (m_logging ? "ON  Balance: " : "OFF Balance: ")
	    + (m_balance ? "ON" : "OFF"),
	    0,
	    m_base_file_name,
	    m_file_name,
	    m_line);
    
    // check the balance
    if(m_balance) assert_balance(m_level,
				 m_base_file_name,
				 m_file_name,
				 m_line,
				 m_category_handle);
    
    // switch off the analyis
    Facility_Implementation::get_instance().
	analysis_off(m_logging);
}

////////////////////////////////////////////////////////////////////////////////

class Memory_Monitoring_Stack
{
private:
    typedef Memory_Monitoring_Stack Self;
    typedef ::syneight::diagnostics::Category_Handle Category_Handle;
    typedef ::syneight::diagnostics::Level_t Level_t;

    inline Memory_Monitoring_Stack()
    {
    }
    
public:
    static inline Self & instance()
    {
	if(mptr_instance==NULL)
	    mptr_instance=new Self;
	return *mptr_instance;
    }

private:
    static Self * mptr_instance;

public:
    Frame const * top(::std::string const & error_msg,
		      char const * const base_file_name,
		      char const * const file_name,
		      int const line,
		      Category_Handle * const category_handle);
    
    void pop();
    inline void push(bool const logging,
		     bool const balance, 
		     Level_t const level,
		     char const * const base_file_name,
		     char const * const file_name,
		     int const line,
		     Category_Handle * const category_handle);
    
private:
    typedef ::std::stack< Frame * > Stack_t;
    Stack_t m_stack;
};

Frame const *  Memory_Monitoring_Stack::top(::std::string const & error_msg,
					    char const * const base_file_name,
					    char const * const file_name,
					    int const line,
					    Category_Handle * const category_handle)
{
    if(m_stack.size()==0) {
	diagnostics::Facility_Implementation::instance().
	    panic_log(diagnostics::Facility_Implementation::instance().category(category_handle,"mem"),
		      ::syneight::diagnostics::EME_LEVEL, 
		      ::syneight::diagnostics::FAILED_ASSERT_TYPE,
		      error_msg,
		      0,
		      base_file_name,
		      file_name,
		      line);
	return NULL;
    }
    else 
	return m_stack.top();
}

void Memory_Monitoring_Stack::pop()
{
    if(m_stack.size()==0) 
	diagnostics::Facility_Implementation::instance().
	    panic_log(diagnostics::Facility_Implementation::instance().category("mem"),
		      ::syneight::diagnostics::EME_LEVEL, 
		      ::syneight::diagnostics::FAILED_ASSERT_TYPE,
		      "Memory_Monitoring_Stack::pop() found empty stack",
		      0,
		      "",
		      "",
		      0);
    else {
	delete m_stack.top();
	m_stack.pop();
    }
}

void Memory_Monitoring_Stack::push(bool const logging,
				   bool const balance, 
				   Level_t const level,
				   char const * const base_file_name,
				   char const * const file_name,
				   int const line,
				   Category_Handle * const category_handle)
{
    m_stack.push(new Frame(logging,
			   balance,
			   level,
			   base_file_name,
			   file_name,
			   line,
			   category_handle));
}


Memory_Monitoring_Stack * Memory_Monitoring_Stack::mptr_instance=NULL;


SYNEIGHT__END__NAMESPACE__INTERNAL;


Guard::Guard(bool const logging,
	     bool const balance, 
	     Level_t const level,
	     char const * const base_file_name,
	     char const * const file_name,
	     int const line,
	     Category_Handle * const category_handle) 
{
    using ::syneight::memory_monitoring::internal::Memory_Monitoring_Stack;
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Memory_Monitoring_Stack::instance().
	push(logging,
	     balance,
	     level,
	     base_file_name,
	     file_name,
	     line,
	     category_handle);
    SYNEIGHT__DIAGNOSTICS_END;
}


Guard::~Guard() 
{
    using ::syneight::memory_monitoring::internal::Memory_Monitoring_Stack;
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Memory_Monitoring_Stack::instance().pop();
    SYNEIGHT__DIAGNOSTICS_END;
}

void Guard::assert_balance(Level_t const level,
			   char const * const base_file_name,
			   char const * const file_name,
			   int const line,
			   Category_Handle * const category_handle)
{
    using ::syneight::memory_monitoring::internal::Memory_Monitoring_Stack;
    using ::syneight::memory_monitoring::internal::Frame;
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Frame const * const frame
	(Memory_Monitoring_Stack::instance().top("Memory_Monitoring_Stack::assert_balance found empty stack",
						     base_file_name,file_name,line,category_handle));
    if(frame!=NULL)
	frame->assert_balance(level,base_file_name,file_name,line,category_handle);
    SYNEIGHT__DIAGNOSTICS_END;
}

void Guard::log_balance(Level_t const level,
			char const * const base_file_name,
			char const * const file_name,
			int const line,
			Category_Handle * const category_handle)
{
    using ::syneight::memory_monitoring::internal::Memory_Monitoring_Stack;
    using ::syneight::memory_monitoring::internal::Frame;
    using ::syneight::baseutil::to_string;
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Frame const * const frame
	(Memory_Monitoring_Stack::instance().top("Memory_Monitoring_Stack::log_balance found empty stack",
						     base_file_name,file_name,line,category_handle));
    if(frame!=NULL) {
	::std::size_t size;
	Tick_t number;
	frame->balance(size,number);
	
	diagnostics::Facility_Implementation::instance().
	    log(diagnostics::Facility_Implementation::instance().category(category_handle,"mem"),
		level, 
		::syneight::diagnostics::MEMORY_BALANCE_TYPE,
		to_string("Size=",size," Number=",number,
			  " [wrt. ",frame->m_base_file_name,
			  " / ",frame->m_file_name,
			  " / ",frame->m_line,
			  " ]"),
		0,
		base_file_name,
		file_name,
		line);
    }
    SYNEIGHT__DIAGNOSTICS_END;
}

void Guard::log_total_balance(Level_t const level,
			      char const * const base_file_name,
			      char const * const file_name,
			      int const line,
			      Category_Handle * const category_handle)
{
    using ::syneight::memory_monitoring::internal::Memory_Monitoring_Stack;
    using ::syneight::baseutil::to_string;
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    ::std::size_t size;
    Tick_t number;
    Facility_Implementation::get_instance().balance(size,number);
	
    diagnostics::Facility_Implementation::instance().
	log(diagnostics::Facility_Implementation::instance().category(category_handle,"mem"),
	    level, 
	    ::syneight::diagnostics::MEMORY_BALANCE_TYPE,
	    to_string("Size=",size," Number=",number," [total]"),
	    0,
	    base_file_name,
	    file_name,
	    line);
    SYNEIGHT__DIAGNOSTICS_END;
}


void Guard::balance(::std::size_t & size,Tick_t & number)
{
    using ::syneight::memory_monitoring::internal::Memory_Monitoring_Stack;
    using ::syneight::memory_monitoring::internal::Frame;
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Frame const * const frame
	(Memory_Monitoring_Stack::instance().
	 top("Memory_Monitoring_Stack::balance found empty stack",
	     "","",0,
	     diagnostics::Facility_Implementation::instance().category("mem")));
    if(frame!=NULL)
	frame->balance(size,number);
    SYNEIGHT__DIAGNOSTICS_END;
}


void Guard::total_balance(::std::size_t & size,Tick_t & number)
{
    using ::syneight::memory_monitoring::internal::Memory_Monitoring_Stack;
    SYNEIGHT__DIAGNOSTICS_BEGIN;
    Facility_Implementation::get_instance().balance(size,number);
    SYNEIGHT__DIAGNOSTICS_END;
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;
// vim:ts=4:sw=4
