

#ifndef SYNEIGHT__TEST__MAZEGAME__OBJECT__WRONG_OBJECT_TYPE_EXCEPTION_HPP
#define SYNEIGHT__TEST__MAZEGAME__OBJECT__WRONG_OBJECT_TYPE_EXCEPTION_HPP

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/namespace.hpp>

#include <syneight/test/mazegame2/exception/standard_mazegame_exception.hpp>

#include <string>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

class Wrong_Object_Type_Exception 
    : public Standard_Mazegame_Exception
{
public:
    virtual ~Wrong_Object_Type_Exception() SYNEIGHT__EXCEPTION_NO_THROW;
    Wrong_Object_Type_Exception(::syneight::Source_Location const & source_location,
				    ::std::string const & what);
    
    virtual char const * plain_what() const;
    virtual char const * class_name() const;
private:
	::std::string m_what;
	mutable ::std::string m_buffer;
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif
// vim:ts=4:sw=4
