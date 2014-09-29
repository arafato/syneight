// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazegame/mazegame.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: mazegame.hpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__MAZEGAME__MAZEGAME_HPP
#define SYNEIGHT__TEST__MAZEGAME__MAZEGAME__MAZEGAME_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/namespace.hpp>

#include <syneight/test/mazegame/mazefactory/roomfactory.hpp>
#include <syneight/test/mazegame/mazefactory/connectorfactory.hpp>

#include <boost/multi_array.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;


/** 
 * @class Maze_Game syneight/test/mazegame/mazegame/mazegame.hpp
 *
 * @brief Mazegame main class creating the maze and managing all game data.
 *
 * This class is managing all game data. You can see it as the server. It will
 * run on the server of mazegame.
 *
 * @nosubgrouping
 */
class Maze_Game {

	/**
	 * @name Members
	 * @{
	 */
public:
	typedef struct {
		long int x;
		long int y;
	} size_t;
private:
	/// @todo estimate where should such things be defined? o_O
	typedef ::boost::multi_array<Room *, 2>	map_t;
	typedef map_t::index		map_index_t;

	Room_Factory*		m_room_factory;
	Connector_Factory*	m_connector_factory;

	Room*				m_root;

	map_t*				m_map;

	size_t				m_size;
	/// @}

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Maze_Game();
	~Maze_Game();
	/// @}

	/**
	 * @name Room handling
	 * @{
	 */
#	if SYNEIGHT__SWITCH__BUILD_LEVEL == 2
	::std::string generate_room_name(size_t size);
#	endif
	///@}

	/**
	 * @name Maze handling
	 * @{
	 */
public:
	/**
	 * @brief Set the size of the maze
	 */
	void size(size_t size);

private:
	/**
	 * @brief Build up a raw maze structure
	 */
	void generate_raw();

private:
	// methods for generate_perfect __________________
	typedef ::boost::multi_array<int, 2>	maze_data_t;
	typedef maze_data_t::index		maze_data_index_t;

	void generate_perfect_reset(maze_data_t& maze_data);
	Room::direction_t generate_perfect_get_next(maze_data_t& maze_data, size_t& current_room);
	// end methods for generate_perfect ______________

	/**
	 * @brief Generate a perfect maze
	 */
	void generate_perfect();

public:
	/**
	 * @brief Building up the maze structure
	 */
	void generate();

	/**
	 * @brief Printing out the whole maze structure.
	 */
	void print();

	/**
	 * @brief Run the management process(es)
	 */
	void run();
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif
// vim:ts=4:sw=4
