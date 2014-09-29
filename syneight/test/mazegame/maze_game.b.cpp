// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazegame.b.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: maze_game.b.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 *
 * @todo everything must be in a namespace. The correct namespaces are
 * not yet determined. Especially: There is no root category at global
 * scope.
 */

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/mazegame/mazegame.hpp>


#include <iostream>

// Defining category() for the root namespace
// it is needed only in this file that is why I do not define it in a stand
// alone .hpp and .cpp files
#include <syneight/base/config/namespace_category.impl.hpp>

SYNEIGHT__NAMESPACE_CATEGORY_INTERFACE;
SYNEIGHT__NAMESPACE_CATEGORY_IMPLEMENTATION(".");

#include <syneight/base/diagnostics/management_facility.hpp>

using namespace mazegame;
using namespace syneight::diagnostics;

/** @brief The main method of mazegame
 *
 * That is the method running the demo actions on maze structures ... it will
 * be replaced with a function in the real mazegame class that will come later.
 */
int main (int argc, char** argv) {
	Maze_Game::size_t maze_size;
	::std::cout << "Mazegame (C) 2004 Piotr Esden-Tempski <esdentem@in.tum.de>\n\n";

	::std::cout << "Running at build level: " << level_to_string(SYNEIGHT__BUILD_LEVEL) << "\n\n";
	
	// configuring logging
	try {
		Management_Facility::load_config("config/logging.conf");
	} catch (::syneight::Exception & e )
	{
		::std::cout << "caught exception: " << e.what() << "\n";
		return 1;
	}
	
	Maze_Game* maze_game = new Maze_Game;


	SYNEIGHT__PRO__TRACE("Weeeee logging is working!");
	
	maze_size.x = 26;
	if (argc > 1) {
		if (atoi(argv[1]) > 1260) {
			::std::cout << "Maze can not be bigger then 1260 rows\n";
			// Otherwise it is producing a segfault
			/// @todo check why mazegame is segfaulting when the
			/// count of rooms is getting bigger then 1260x26 =~ 2^15
			delete maze_game;
			return 1;
		}
		maze_size.y = atoi(argv[1]);
	} else {
		maze_size.y = 6;
	}
	maze_game->size(maze_size);
	maze_game->generate();
	maze_game->print();

	delete maze_game;

/*
	::std::cout << "\nLOG: getting factorys\n";
	room_factory_instance = Room_Factory::instance();
	connector_factory_instance = Connector_Factory::instance();

	::std::cout << "\nLOG: creating root_room\n";
	root_room = room_factory_instance->create_room();
	::std::cout << "\nLOG: creating Room1\n";
	room1 = room_factory_instance->create_room();

	::std::cout << "\nLOG: connecting Room1 to the east of root_room\n";
	root_room->connect_to(Room::m_east, room1);

	::std::cout << "\nLOG: setting connector between rooms to Passage\n";
	root_room->get_connector(Room::m_east)->set_soul(connector_factory_instance->create_soul(Connector_Factory::m_passage));

	::std::cout << "\nLOG: deleting all we created\n";
	::std::cout << "\nLOG: deleting root_room\n";
	delete room1; /// @todo This should happen automatically.
	::std::cout << "\nLOG: deleting Room1\n";
	delete root_room;
*/
	return 0;
}
// vim:ts=4:sw=4
