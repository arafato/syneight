// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazefactory/connectorfactory.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: connectorfactory.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/mazefactory/connectorfactory.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Factory _________________________________________________________________
//
Connector_Factory* Connector_Factory::p_instance = 0;

Connector_Factory* Connector_Factory::instance() {
	if (p_instance == 0) {
		p_instance = new Connector_Factory;
	} else {
	    SYNEIGHT__AUD__TRACE("reusing Connector_Factory obj");
	}
	return p_instance;
}

Connector_Factory::Connector_Factory () {
	SYNEIGHT__AUD__TRACE("constructing Connector_Factory obj");
}

Connector_Factory::~Connector_Factory () {
	SYNEIGHT__AUD__TRACE("destroying Connector_Factory obj");
}
//
// __ End Factory _____________________________________________________________

// __ Methods _________________________________________________________________
//
Connector_Soul* Connector_Factory::create_soul(::mazegame::Connector_Soul::soul_type_t soul_type) {
	switch (soul_type) {
		case ::mazegame::Connector_Soul::m_wall:
			SYNEIGHT__AUD__TRACE("creating a wall soul");
			return (Connector_Soul*) new Connector_Soul_Wall;
		case ::mazegame::Connector_Soul::m_passage: 
			SYNEIGHT__AUD__TRACE("creating a passage soul");
			return (Connector_Soul*) new Connector_Soul_Passage;
		default:
			return (Connector_Soul*) new Connector_Soul_Null;
	}
}

Connector* Connector_Factory::create_wall() {
	Connector* connector_instance;

	connector_instance = new Connector;
	connector_instance->set_soul(create_soul(::mazegame::Connector_Soul::m_wall));
	return connector_instance;
}
//
// __ End Methods _____________________________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;

// vim:ts=4:sw=4
