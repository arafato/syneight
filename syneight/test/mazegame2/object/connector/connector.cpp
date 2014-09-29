// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/connector.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/logging/mazegame_category.hpp>

#include <syneight/test/mazegame2/object/connector/connector.hpp>

#include <syneight/test/mazegame2/object/container.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Creation and Destruction ________________________________________________
//
Connector::Connector()
{
	SYNEIGHT__AUD__TRACE("Creating Connector obj");
	m_object_type = OT_CONNECTOR;
	for (int i =0; i < 4; ++i ) {
		m_parent[i] = 0;
	}
	m_parent_count = 0;
}

Connector::~Connector() 
{
	SYNEIGHT__AUD__TRACE("Destroying Connector obj");
}
//
// __ End Creation and Destruction ____________________________________________

// __ Object handling _________________________________________________________
//
void Connector::put_in(Object* parent) {
	// throw an exception because we need more parameter ...
}

void Connector::put_in(Object* parent, direction_t direction) {

	// (dir ^ 1) means (dir xor 1) and that switches the directions to the
	// opposite, i.e. North becomes South, South becomes North and so on.
	SYNEIGHT__PRO__CHECK1( Wrong_Direction_Exception,
			( m_parent_count > 0 ) && 
			(( m_parent[direction] != 0 ) && 
			 ( m_parent[((int)direction ^ 1)] != 0 )),
			"Connector can not connect over corners");
	SYNEIGHT__PRO__CHECK1( Wrong_Direction_Exception,
			direction != D_NO_DIRECTION,
			"Connector can not be connected in no direction");
	SYNEIGHT__PRO__CHECK1(Wrong_Direction_Exception,
			m_parent_count < 2,
			"Connector can not be in more then two rooms");

	SYNEIGHT__PRO__CHECK1( Wrong_Object_Type_Exception, 
			parent->object_type() == Object::OT_CONTAINER, 
			"Can not connect anything but rooms");
	SYNEIGHT__PRO__CHECK1( Wrong_Object_Type_Exception, 
			static_cast<Container*>(parent)->container_type() 
			== Container::CT_ROOM, 
			"Can not connect anything but rooms");

	
	if ( m_parent[direction] != 0 ) {
		static_cast<Container*>(m_parent[direction])->remove(this);
	}
	m_parent[direction] = parent;
	static_cast<Container*>(parent)->add(this);
}
//
// __ End Connector handling _____________________________________________________
SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
