// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/room.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: room.hpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__ROOM_HPP
#define SYNEIGHT__TEST__MAZEGAME__ROOM_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/mazefactory/connectorfactory.hpp>
#include <syneight/test/mazegame/connector/connector.hpp>
#include <syneight/test/mazegame/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class Room syneight/test/mazegame/room.hpp
 * 
 * @brief Class representing rooms.
 * 
 * @nosubgrouping   
 */
class Room {

	/**
	 * @name Members
	 * @{     
	 */

public:
	/// @brief Listing of all possible directions to which connectors can be connected.
	typedef enum direction_t {m_north, m_south, m_east, m_west, m_no_direction};

private:
	/// @brief References to connectors connected to a room.
	Connector* connector_instances[4];

	/// @brief Name of the room
	::std::string room_name;
	/// @}

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	/// @brief Creates a room with walls connected to all directions of a room.
	Room();
	/// @brief Disconnects all surrounding connectors automatically.
	~Room();
	/// @}

	/**
	 * @name Room handling
	 * @{
	 */
public:
	void name(::std::string room_name);
	::std::string name();
	/// @}
	/**
	 * @name Connector handling
	 * @{
	 */
public:
	/** 
	 * @brief Connects two rooms together.
	 *
	 * @attention The connector between that rooms is not being replaced
	 * with any other. The connector of the room passed is being used to
	 * connect the two rooms. The connector of the current room is being
	 * destroyed.
	 *
	 */
	void connect_to(direction_t dir, Room* partner_room);
	/** 
	 * @brief Getts a reference to a connector connected to
	 * one of the directions of a room.
	 *
	 * You can pass a direction to this method to get a reference to a
	 * connector connected to the particular direction of the room.
	 * 
	 */
	Connector* get_connector(direction_t dir);
	/// @}

};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
