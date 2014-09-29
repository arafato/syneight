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
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/logging/mazegame_category.hpp>

#include <syneight/test/mazegame2/object/container.hpp>


SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Creation and Destruction ________________________________________________
//
Container::Container()
{
	SYNEIGHT__AUD__METHOD_ENTER("Container::Container()");
	SYNEIGHT__AUD__TRACE("Creating Container object");

	m_object_type = OT_CONTAINER;

	SYNEIGHT__AUD__METHOD_EXIT;
}

Container::~Container() {
	SYNEIGHT__AUD__METHOD_ENTER("Container::~Container()");
	SYNEIGHT__AUD__TRACE("Destroying Container object");
	SYNEIGHT__AUD__METHOD_EXIT;
}
//
// __ End Creation and Destruction ____________________________________________

// __ Object handling _________________________________________________________
//
void Container::add(Object* object) {
	SYNEIGHT__AUD__METHOD_ENTER("void Container::add(Object* object)");

	m_object_list.push_front(object);

	SYNEIGHT__AUD__METHOD_EXIT;
}

void Container::remove(Object* object) {
	SYNEIGHT__AUD__METHOD_ENTER("void Container::remove(Object* object)");
	// find and remove object
	SYNEIGHT__AUD__METHOD_EXIT;
}
//
// __ End Object handling _____________________________________________________
SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
