// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/object.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 * @author Daniel Reutter
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/logging/mazegame_category.hpp>

#include <syneight/test/mazegame2/object/object.hpp>

#include <syneight/test/mazegame2/object/container.hpp>


SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Creation and Destruction ________________________________________________
//
Object::Object() : m_object_type(OT_OBJECT)
{
	SYNEIGHT__AUD__METHOD_ENTER("Object::Object()");
	SYNEIGHT__AUD__TRACE("Creating Object object");

	m_parent = 0;

	SYNEIGHT__AUD__METHOD_EXIT;
}

Object::~Object() 
{
	SYNEIGHT__AUD__METHOD_ENTER("Object::~Object()");
	SYNEIGHT__AUD__TRACE("Destroying Object object");
	SYNEIGHT__AUD__METHOD_EXIT;
}
//
// __ End Creation and Destruction ____________________________________________

// __ Object handling _________________________________________________________
//
void Object::put_in(Object* parent) {
	SYNEIGHT__AUD__METHOD_ENTER("void Object::put_in(Object* parent)");

	if ( parent->object_type() == Object::OT_CONTAINER ) {

		// Check if we are already in a container
		// if yes then remove us from there
		if (m_parent != 0) {
			static_cast<Container*>(parent)->remove(this);
		}

		// remember that we are now in parent
		m_parent = parent;

		// add us to the container parent
		static_cast<Container*>(parent)->add(this);
	} else {
		// throw exception that it is not possible
		switch ( parent->object_type() ) {
			case Object::OT_OBJECT:
				SYNEIGHT__PRO__CHECK1(Wrong_Object_Type_Exception,
						false, "Can not put an Object"
						" in an Object");
				break;
			case Object::OT_CONNECTOR:
				SYNEIGHT__PRO__CHECK1(Wrong_Object_Type_Exception,
						false, "Can not put a Connector"
						" in an Object");
				break;
			default:
				SYNEIGHT__AUD__CHECK1(Wrong_Object_Type_Exception,
						false, "Can not put an unknown"
						" Object in an Object");
		}
	}

	SYNEIGHT__AUD__METHOD_EXIT;
}

Object* Object::parent() {
	SYNEIGHT__AUD__METHOD_ENTER("Object* Object::parent()");

	return m_parent;

	SYNEIGHT__AUD__METHOD_EXIT;
}
//
// __ End Object handling _____________________________________________________

// __ Command handling  _______________________________________________________
//

void Object::apply(const char cmd_code[4], Object* subject){
	SYNEIGHT__AUD__METHOD_GUARD("void Object::apply(const char cmd_code[4], Object* subject)");

	if (cmd_code == "TEST") {
		SYNEIGHT__AUD__TRACE("TEST cmd applied succesfully.");
	}
	else if (cmd_code == "NOOP") {
		SYNEIGHT__AUD__TRACE("Successfully did nothing.");
	}
	else {
		SYNEIGHT__AUD__CHECK1(Unknown_Apply_Command_Exception, false, ::std::string("Unknown command \"") + cmd_code + "\"");
	}
}

//
// __ End Command handling  ___________________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
