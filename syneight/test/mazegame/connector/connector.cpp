// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/connector.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: connector.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/connector/connector.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;


// __ Creation and Destruction ________________________________________________
//
Connector::Connector() {
	SYNEIGHT__AUD__TRACE("creating Connector obj");
	m_soul = 0;
	m_partner_room_count = 0;
}

Connector::~Connector() {
	if (m_soul != 0) {
		delete m_soul;
	}
	SYNEIGHT__AUD__TRACE("destroying Connector obj");
}
//
// __ End Creation and Destruction ____________________________________________

// __ Soul handling ___________________________________________________________
//
void Connector::set_soul(Connector_Soul* m_soul_to_set) {
	SYNEIGHT__AUD__TRACE("setting Connector_Soul obj");
	if (m_soul != 0) {
		SYNEIGHT__AUD__TRACE("trying to delete Connector_Soul obj");
		delete m_soul;
	}
	m_soul = m_soul_to_set;
}

Connector_Soul::soul_type_t Connector::type() {
	return m_soul->type();
}
//
// __ End Soul handling _______________________________________________________

// __ Connecion handling ______________________________________________________
//
void Connector::connect(Room* partner_room) {
	if (m_partner_room_count < 2) {
		m_partner_rooms[m_partner_room_count] = partner_room;
		m_partner_room_count++;
	}
}

void Connector::disconnect(Room* partner_room) {
	int i;

	for (i=0; i<m_partner_room_count; i++) {
		if (m_partner_rooms[i] == partner_room) {
			if (i < m_partner_room_count - 1) {
				m_partner_rooms[i] = m_partner_rooms[m_partner_room_count-1];
			}
			m_partner_room_count--;
		}
	}
	if (m_partner_room_count == 0) {
		delete this;
	}
}
//
// __ End Connecion handling __________________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
