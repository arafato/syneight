// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/connector.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: connector.hpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__CONNECTOR__CONNECTOR_HPP
#define SYNEIGHT__TEST__MAZEGAME__CONNECTOR__CONNECTOR_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

class Room;

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#include <syneight/test/mazegame/connector/soul/soul.hpp>
#include <syneight/test/mazegame/room.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/**
 * @class Connector syneight/test/mazegame/connector/connector.hpp 
 *
 * @brief Class that is a container for Connector_Soul classes.
 *
 * This class is meant as a connection between rooms. It has to contain a soul
 * that represents apriopriate behaviour like Wall or Passage.
 *
 * @nosubgrouping
 */
class Connector {

	/**
	 * @name Members
	 * @{
	 */
private:
	/// @brief Reference to the soul of the connector.
	Connector_Soul* m_soul;
	/// @brief References to the rooms on the sides of the connector.
	Room* m_partner_rooms[2];
	/// @brief Number of currently connected rooms to the connector.
	int m_partner_room_count;
	/// @}

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Connector();

	/// @attention Destructor destroys the contained soul
	/// automatically.
	~Connector();
	/// @}

	/**
	 * @name Soul handling
	 * @{
	 */
public:
	/// @brief Set the soul of a connector.
	void set_soul(Connector_Soul* soul_to_set);
	/// @brief Get the type of the soul in this connector
	Connector_Soul::soul_type_t type();
	/// @}

	/**
	 * @name Connecion handling
	 * @{
	 */
public:
	/// @brief Connect a room to the connector.
	void connect(Room* partner_room);
	/** 
	 * @brief Disconnect a room from the connector.
	 *
	 * @attention When you disconnect the last room from the connector it
	 * selfdestroys automatically.
	 */
	void disconnect(Room* partner_room);
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
