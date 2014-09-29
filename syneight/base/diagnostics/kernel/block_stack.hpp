/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/kernel/block_stack.hpp
 *
 * @author Christian Schallhart
 * @author $Author: esdentem $
 *
 * @version $Id: block_stack.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref syneight::diagnostics::kernel::Block_Stack
 *
 * TODO: Long description.
 *
 * @note DOCUMENTED
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__KERNEL__BLOCK_STACK_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__KERNEL__BLOCK_STACK_HPP

#include <syneight/base/diagnostics/kernel/facility_implementation.hpp>

#include <stack>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

class Block_Frame
{
private:
    typedef Block_Frame Self;
    Block_Frame(Self const & other);
    Self & operator=(Self const & other);
public:
    inline Block_Frame(bool const log,
		       Type_t const type_enter, 
		       Type_t const type_exit,
		       Level_t const level,
		       ::std::string const & str_what,
		       int const nr_what,
		       char const * const base_file_name,
		       char const * const file_name,
		       int const line,
		       Category_Handle * const category_handle);
    inline ~Block_Frame();
private:
    bool const m_log;
    Type_t const m_type_enter;
    Type_t const m_type_exit;
    Level_t const m_level;
    ::std::string const m_str_what;
    int const m_nr_what;
    char const * const m_base_file_name;
    char const * const m_file_name;
    int const m_line;
    Category_Handle * const m_category_handle;
};

Block_Frame::Block_Frame(bool const log,
			 Type_t const type_enter, 
			 Type_t const type_exit,
			 Level_t const level,
			 ::std::string const & str_what,
			 int const nr_what,
			 char const * const base_file_name,
			 char const * const file_name,
			 int const line,
			 Category_Handle * const category_handle) :
    m_log(log),
	m_type_enter(type_enter),
    m_type_exit(type_exit),
    m_level(level),
    m_str_what(str_what),
    m_nr_what(nr_what),
    m_base_file_name(base_file_name),
    m_file_name(file_name),
    m_line(line),
    m_category_handle(category_handle)
{
    if(m_log)
	Facility_Implementation::instance().log
	    (m_category_handle,
	     m_level, 
	     m_type_enter,
	     m_str_what,
	     m_nr_what,
	     m_base_file_name,
	     m_file_name,
	     m_line);
}

Block_Frame::~Block_Frame()
{
    if(m_log)
	Facility_Implementation::instance().log
	    (m_category_handle,
	     m_level, 
	     m_type_exit,
	     m_str_what,
	     m_nr_what,
	     m_base_file_name,
	     m_file_name,
	     m_line);
}

////////////////////////////////////////////////////////////////////////////////

/// @todo the simple stack must be replaced with something more effective

class Block_Stack
{
private:
    typedef Block_Stack Self;
    Block_Stack();
public:
    static inline Self & instance()
    {
	/// @todo be thread specific
	if(m_instance==NULL)
	    m_instance=new Self;
	return *m_instance;
    }
private:
    static Self * m_instance;

public:
    typedef ::std::stack< Block_Frame * > Stack_t;
    Stack_t m_stack;

public:
    ::std::string stack_trace();

    inline void pop();
    inline void push(bool const log,
		     Type_t const type_enter, 
		     Type_t const type_exit,
		     Level_t const level,
		     ::std::string const & str_what,
		     int const nr_what,
		     char const * const base_file_name,
		     char const * const file_name,
		     int const line,
		     Category_Handle * const category_handle);
    
    inline Block_Frame const & top() const;

    inline int size() const;
};

int Block_Stack::size() const
{
    return m_stack.size();
}

void Block_Stack::pop()
{
    delete m_stack.top();
    m_stack.pop();
}
 
Block_Frame const & Block_Stack::top() const
{
    return *m_stack.top();
}

void Block_Stack::push(bool const log,
		       Type_t const type_enter, 
		       Type_t const type_exit,
		       Level_t const level,
		       ::std::string const & str_what,
		       int const nr_what,
		       char const * const base_file_name,
		       char const * const file_name,
		       int const line,
		       Category_Handle * const category_handle)
{
    m_stack.push(new Block_Frame(log,
				 type_enter,
				 type_exit,
				 level,
				 str_what,
				 nr_what,
				 base_file_name,
				 file_name,
				 line,
				 category_handle));
}

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
