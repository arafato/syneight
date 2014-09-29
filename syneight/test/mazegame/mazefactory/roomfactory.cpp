// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazefactory/roomfactory.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: roomfactory.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/mazefactory/roomfactory.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Factory _________________________________________________________________
//
Room_Factory* Room_Factory::p_instance = 0;

Room_Factory* Room_Factory::instance() {
	if (p_instance == 0) {
		p_instance = new Room_Factory;
	} else {
		SYNEIGHT__AUD__TRACE("reusing Room_Factory obj");
	}
	return p_instance;
}

Room_Factory::Room_Factory () {
	SYNEIGHT__AUD__TRACE("constructing Room_Factory obj");
}

Room_Factory::~Room_Factory () {
	SYNEIGHT__AUD__TRACE("destroying Room_Factory obj");
}
//
// __ End Factory _____________________________________________________________

// __ Room handling ___________________________________________________________
//
Room* Room_Factory::create_room() const {
	return new Room;
}
//
// __ End Room handling _______________________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
