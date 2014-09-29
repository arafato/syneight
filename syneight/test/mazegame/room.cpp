// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/room.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: room.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/room.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Creation and Destruction ________________________________________________
//
Room::Room() : room_name("no name")
{
	int i;
	Connector_Factory* connector_factory_instance;
	SYNEIGHT__AUD__TRACE("creating Room obj");
	connector_factory_instance = Connector_Factory::instance();

	for (i=0; i<4; i++) {
	SYNEIGHT__AUD__TRACE("creating Room Connector obj");
		connector_instances[i] = connector_factory_instance->create_wall();
		connector_instances[i]->connect(this);
	}
}

Room::~Room() {
	int i;

	SYNEIGHT__AUD__TRACE("disconnecting connectors");
	for (i=0; i<4; i++) {
		connector_instances[i]->disconnect(this);

	}
	SYNEIGHT__AUD__TRACE("destroying Room obj");
}
//
// __ End Creation and Destruction ____________________________________________

// __ Room handling ___________________________________________________________
//
void Room::name(::std::string room_name) {
	this->room_name = room_name;
}

::std::string Room::name() {
	return room_name;
}
//
// __ End Room handling _______________________________________________________

// __ Connector handling ______________________________________________________
//
Connector* Room::get_connector(direction_t dir) {
	return connector_instances[dir];
}

void Room::connect_to(direction_t dir, Room* PartnerRoom) {
	connector_instances[dir]->disconnect(this);

	// (dir ^ 1) means (dir xor 1) and that switches the directions to the
	// opposite, i.e. North becomes South, South becomes North and so on.
	connector_instances[dir] = PartnerRoom->get_connector( (direction_t)((int)dir ^ 1) );
	connector_instances[dir]->connect(this);
}
//
// __ End Connector handling __________________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
