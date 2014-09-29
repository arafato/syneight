// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazegame/mazegame.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: mazegame.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/test/mazegame/mazegame/mazegame.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <iostream>
#include <stack>
#include <vector>

//#define SYNEIGHT__LOCAL__SWITCH__DEBUG 1

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;


// __ Creation and Destruction ________________________________________________
//
Maze_Game::Maze_Game()
{
	SYNEIGHT__AUD__TRACE("creating Maze_Game obj");

	m_room_factory 		= Room_Factory::instance();
	m_connector_factory 	= Connector_Factory::instance();

	m_map = NULL;
	m_size.x = 5;
	m_size.y = 5;
}

Maze_Game::~Maze_Game() {
	SYNEIGHT__AUD__TRACE("destroying Maze_Game obj");
}
//
// __ End Creation and Destruction ____________________________________________

// __ Room handling ___________________________________________________________
//
#if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
::std::string Maze_Game::generate_room_name(size_t position) {
	::std::stringstream room_name_stream;
	room_name_stream << "Room Nr.: x:" << position.x << " y:" << position.y;
	return room_name_stream.str();
}
#endif
//
// __ End Room handling _______________________________________________________

// __ Maze handling ___________________________________________________________
//
void Maze_Game::size(size_t size) {
	m_size.x = size.x;
	m_size.y = size.y;
}

void Maze_Game::generate_raw() {
	size_t position;


#	if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
	size_t position2; /// @todo only needed in audit
#	endif

	SYNEIGHT__AUD__TRACE("generating raw maze ...");

	m_map = new map_t(::boost::extents[m_size.x][m_size.y]);

	for (map_index_t y = 0; y < m_size.y; ++y) {
		for (map_index_t x = 0; x < m_size.x; ++x) {
			position.x = x;
			position.y = y;
#			if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
			{
				::std::string log_msg;
				log_msg = "creating room ";
				log_msg += generate_room_name(position);
				SYNEIGHT__AUD__TRACE(log_msg);
			}
#			endif
			(*m_map)[x][y] = m_room_factory->create_room();
//			(*m_map)[x][y]->name(generate_room_name(position));

			if (x > 0) {
#				if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
				position2.x = x-1;
				position2.y = y;
				{
					::std::string log_msg;
					log_msg  = "connecting ";
					log_msg += generate_room_name(position2) + " to ";
					log_msg += generate_room_name(position);
					SYNEIGHT__AUD__TRACE(log_msg);
				}
#				endif
				(*m_map)[x-1][y]->connect_to(Room::m_east, (*m_map)[x][y]);
			}

			if (y > 0) {
/// @todo needs another solution
//#				if SYNEIGHT__LOCAL__SWITCH__DEBUG == 1
//				position2.x = x;
//				position2.y = y-1;
//				::std::cout << "\n" << "LOG: connecting " <<
//					generate_room_name(position2) << " to " <<
//					generate_room_name(position) << ::std::endl;
//#				endif
				(*m_map)[x][y-1]->connect_to(Room::m_south, (*m_map)[x][y]);
			}
		}
	}

	SYNEIGHT__AUD__TRACE("finished generating raw maze");
}

void Maze_Game::generate_perfect_reset(maze_data_t& maze_data) {
	for (maze_data_index_t y = 0; y < m_size.y; ++y) {
		for (maze_data_index_t x = 0; x < m_size.x; ++x) {
			maze_data[x][y] = 0x000F;
		}
	}
}

Room::direction_t Maze_Game::generate_perfect_get_next(maze_data_t& maze_data, size_t& current_room) {
	::std::vector<Room::direction_t> candidate_rooms;
	maze_data_index_t x = current_room.x;
	maze_data_index_t y = current_room.y;

	SYNEIGHT__AUD__TRACE("finding next room for perfect maze");
	if (m_size.x > 1) {
		if (x < m_size.x-1) {
			if ((maze_data[x+1][y] & 0x000F) == 0x000F) {
				SYNEIGHT__AUD__TRACE("Found candidate room in the east");
				candidate_rooms.insert(candidate_rooms.end(), Room::m_east);
				SYNEIGHT__AUD__TRACE("Candidate in the east inserted in candidate_rooms");
			}
		}
		if (y > 0) {
			if ((maze_data[x-1][y] & 0x000F) == 0x000F) {
				SYNEIGHT__AUD__TRACE("Found candidate room in the west");
				candidate_rooms.insert(candidate_rooms.end(), Room::m_west);
				SYNEIGHT__AUD__TRACE("Candidate in the west inserted in candidate_rooms");
			}
		}
	}
	if (m_size.y > 1) {
		if (y < m_size.y-1) {
			if ((maze_data[x][y+1] & 0x000F) == 0x000F) {
				SYNEIGHT__AUD__TRACE("Found candidate room in the south");
				candidate_rooms.insert(candidate_rooms.end(), Room::m_south);
				SYNEIGHT__AUD__TRACE("Candidate in the south inserted in candidate_rooms");
			}
		}
		if (y > 0) {
			if ((maze_data[x][y-1] & 0x000F) == 0x000F) {
				SYNEIGHT__AUD__TRACE("Found candidate room in the north");
				candidate_rooms.insert(candidate_rooms.end(), Room::m_north);
				SYNEIGHT__AUD__TRACE("Candidate in the north inserted in candidate_rooms");
			}
		}
	}

	if (candidate_rooms.size() > 0) {
/// @todo needs another solution
//#		if SYNEIGHT__LOCAL__SWITCH__DEBUG == 1
//		::std::cout << "LOG: Found " << candidate_rooms.size() << " candidate rooms" << ::std::endl;
//#		endif
		return candidate_rooms[rand() % candidate_rooms.size()];
	} else {
		return Room::m_no_direction;
	}
}

void Maze_Game::generate_perfect() {
	// maze_data is an array of integers (we relay on the fact that int is 16 bit wide)
	// each int value has the following structure:
	// Backtrack Solution  Border   Walls
	//  __|__     __|__    __|__    __|__
	// |     |   |     |  |     |  |     |
	// 0 0 0 0   0 0 0 0  0 0 0 0  0 0 0 0
	// N S E W   N S E W  N S E W  N S E W
	//
	// 0 means not set
	// 1 means set
	// Currently only Walls entry is being used

	maze_data_t maze_data(::boost::extents[m_size.x][m_size.y]);
	int visited_rooms = 1;
	const int total_rooms = m_size.x*m_size.y;
	size_t* current_room;
	size_t current_room_bak;
	map_index_t map_index_x;
	map_index_t map_index_y;
	Room::direction_t next_room;

	current_room = new size_t;
	current_room->x = 0;
	current_room->y = 0;

	::std::stack<size_t*> room_coord_stack;

	// set all entries to 0x000F (that means that this room has all walls rised)
	generate_perfect_reset(maze_data);

	// set random seed to a quasi random number
	srand( (unsigned)time( NULL ) );

	while (visited_rooms < total_rooms) {
		next_room = generate_perfect_get_next(maze_data, *current_room);

		map_index_x = current_room->x; /// @todo needed only in audit
		map_index_y = current_room->y; /// @todo needed only in audit
/// @todo needs another solution
//		::std::cout << "\nCurrent " <<(*m_map)[map_index_x][map_index_y]->name() << 
//			" total rooms:" << total_rooms << 
//			" visited rooms: " << visited_rooms << ::std::endl;
		if (next_room == Room::m_north) {
			SYNEIGHT__AUD__TRACE("next room is north");
		} else if (next_room == Room::m_south) {
			SYNEIGHT__AUD__TRACE("next room is south");
		} else if (next_room == Room::m_east) {
			SYNEIGHT__AUD__TRACE("next room is east");
		} else if (next_room == Room::m_west) {
			SYNEIGHT__AUD__TRACE("next room is west");
		} else if (next_room == Room::m_no_direction) {
			SYNEIGHT__AUD__TRACE("next room is in no direction");
		}
		
		// Knocking down the wall in the m_map
		if (next_room != Room::m_no_direction) {
		map_index_x = current_room->x;
		map_index_y = current_room->y;
		(*m_map)[map_index_x][map_index_y]->
			get_connector(next_room)->
			set_soul(m_connector_factory->create_soul(Connector_Soul::m_passage));
		}

		// Knocking down the wall in our internal map
		// Pushing the current location up the stack
		// Moving to the new room
		// Incrementing visited rooms counter
		if (next_room == Room::m_north) {
			maze_data[current_room->x][current_room->y]   = 0x0007; //0000 0000 0000 0111
			maze_data[current_room->x][current_room->y-1] = 0x000B; //0000 0000 0000 1011
			room_coord_stack.push(current_room);
			current_room_bak.x = current_room->x;
			current_room_bak.y = current_room->y;
			current_room = new size_t;
			current_room->x = current_room_bak.x;
			current_room->y = current_room_bak.y;
			--(current_room->y);
			++visited_rooms;
		} else if (next_room == Room::m_south) {
			maze_data[current_room->x][current_room->y]   = 0x000B; //0000 0000 0000 1011
			maze_data[current_room->x][current_room->y+1] = 0x0007; //0000 0000 0000 1011
			room_coord_stack.push(current_room);
			current_room_bak.x = current_room->x;
			current_room_bak.y = current_room->y;
			current_room = new size_t;
			current_room->x = current_room_bak.x;
			current_room->y = current_room_bak.y;
			++(current_room->y);
			++visited_rooms;
		} else if (next_room == Room::m_east) {
			maze_data[current_room->x][current_room->y]   = 0x000D; //0000 0000 0000 1101
			maze_data[current_room->x+1][current_room->y] = 0x000E; //0000 0000 0000 1110
			room_coord_stack.push(current_room);
			current_room_bak.x = current_room->x;
			current_room_bak.y = current_room->y;
			current_room = new size_t;
			current_room->x = current_room_bak.x;
			current_room->y = current_room_bak.y;
			++(current_room->x);
			++visited_rooms;
		} else if (next_room == Room::m_west) {
			maze_data[current_room->x][current_room->y]   = 0x000E; //0000 0000 0000 0111
			maze_data[current_room->x-1][current_room->y] = 0x000D; //0000 0000 0000 1011
			room_coord_stack.push(current_room);
			current_room_bak.x = current_room->x;
			current_room_bak.y = current_room->y;
			current_room = new size_t;
			current_room->x = current_room_bak.x;
			current_room->y = current_room_bak.y;
			--(current_room->x);
			++visited_rooms;
		} else if (next_room == Room::m_no_direction) {
			free(current_room);
			current_room = room_coord_stack.top();
			room_coord_stack.pop();
		}
	}

	// Freeing the memory we have still allocated
	while (room_coord_stack.size() > 1) {
		free(current_room);
		current_room = room_coord_stack.top();
		room_coord_stack.pop();
	}
	free(current_room);
}

void Maze_Game::generate() {
	SYNEIGHT__AUD__TRACE("generating maze...");

	// First generate a raw maze containing rooms with walls in all
	// directions
	generate_raw();

	// Generate a perfect maze (we do not have other algorithms yet) (idea
	// we could also load a maze from a file ;) )
	generate_perfect();

	SYNEIGHT__AUD__TRACE("finished generating maze");
}

void Maze_Game::print() {
	for (map_index_t y = 0; y < m_size.y; ++y) {
		for (map_index_t x = 0; x < m_size.x; ++x) {
			if ((*m_map)[x][y]->get_connector(Room::m_north)->type() == Connector_Soul::m_wall) {
				::std::cout << ",-.";
			} else {
				::std::cout << ",#.";
			}
		}
		::std::cout << "\n";
		for (map_index_t x = 0; x < m_size.x; ++x) {
			if ((*m_map)[x][y]->get_connector(Room::m_west)->type() == Connector_Soul::m_wall) {
				::std::cout << "|#";
			} else {
				::std::cout << "##";
			}
			if ((*m_map)[x][y]->get_connector(Room::m_east)->type() == Connector_Soul::m_wall) {
				::std::cout << "|";
			} else {
				::std::cout << "#";
			}
		}
		::std::cout << "\n";
		for (map_index_t x = 0; x < m_size.x; ++x) {
			if ((*m_map)[x][y]->get_connector(Room::m_south)->type() == Connector_Soul::m_wall) {
				::std::cout << "`-'";
			} else {
				::std::cout << "`#'";
			}
		}
		::std::cout << "\n";
	}
	::std::cout << "\n";
} 

void Maze_Game::run() {
	// The maze management process main routine ...
}

//
// __ End Maze handling _______________________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
