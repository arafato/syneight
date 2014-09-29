// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/connector/connector.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__OBJECT__CONNECTOR_HPP
#define SYNEIGHT__TEST__MAZEGAME__OBJECT__CONNECTOR_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame2/namespace.hpp>

#include <syneight/test/mazegame2/object/object.hpp>
#include <syneight/test/mazegame2/object/wrong_object_type_exception.hpp>
#include <syneight/test/mazegame2/object/wrong_direction_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class Object syneight/test/mazegame/object/connector/connector.hpp
 *
 * @brief Parent class for all Objects.
 *
 *
 * @nosubgrouping
 */
class Connector : public Object {

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Connector();
	~Connector();
	/// @}

	/**
	 * @name Object handling
	 * @{
	 */
public:
	typedef enum direction_t {
		D_NORTH,
		D_SOUTH,
		D_EAST,
		D_WEST,
		D_NO_DIRECTION
	};

    void put_in(Object* parent);
    void put_in(Object* parent, direction_t direction);

private:
	Object* m_parent[4];
	char m_parent_count;
	/// @}

};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
