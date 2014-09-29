// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazefactory/roomfactory.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: roomfactory.hpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__MAZEFACTORY__ROOMFACTORY_HPP
#define SYNEIGHT__TEST__MAZEGAME__MAZEFACTORY__ROOMFACTORY_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/room.hpp>
#include <syneight/test/mazegame/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class RoomFactory syneight/test/mazegame/mazefactory/roomfactory.hpp
 *
 * @brief Factory for creating Rooms.
 *
 * @nosubgrouping
 */
class Room_Factory {

	/**
	 * @name Factory
	 * @{
	 */	
private:
	/// Reference to the only ever existing instance of Room_Factory.
	static Room_Factory* p_instance;
public:
	/** 
	 * @brief Room_Factory constructor replacement.
	 *
	 * Method that is a replacement for the Room_Factory constructor. It is
	 * taking care that there is always only one instance of the RoomFatory
	 * class existing. There is never another instance needed.
	 */
	static Room_Factory* instance();

protected:
	/// @brief Room_Factory constructor meant only for the use from inside
	/// of Room_Factory class.
	Room_Factory();

public:
	/// @brief Room_Factory destructor what else. ;)
	~Room_Factory();


	/// @}
	
	/**
	 * @name Room handling
	 *
	 * @{
	 */
public:
	/// @brief Room creation method.
	Room* create_room() const;
	/// @}

};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
