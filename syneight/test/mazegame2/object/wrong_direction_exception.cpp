#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame2/object/wrong_direction_exception.hpp>


SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

Wrong_Direction_Exception::Wrong_Direction_Exception(::syneight::Source_Location const & source_location,
							 ::std::string const & what) 
	: Standard_Mazegame_Exception(source_location)
{
	m_what = what;
}

Wrong_Direction_Exception::~Wrong_Direction_Exception() SYNEIGHT__EXCEPTION_NO_THROW 
{
}

char const * Wrong_Direction_Exception::plain_what() const
{
	m_buffer  = class_name()+ ::std::string(": '");
	m_buffer += m_what;
	m_buffer += "'";

	return m_buffer.c_str();
};

char const * Wrong_Direction_Exception::class_name() const
{
    return "Wrong_Direction_Exception";
}


SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
