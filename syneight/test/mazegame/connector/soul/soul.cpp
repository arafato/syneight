// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/soul/soul.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/connector/soul/soul.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Creation and Destruction ________________________________________________
//
Connector_Soul::Connector_Soul() {
	SYNEIGHT__AUD__TRACE("creating Connector_Soul obj");
}

Connector_Soul::~Connector_Soul() {
	SYNEIGHT__AUD__TRACE("destroying Connector_Soul obj");
}
//
// __ End Creation and Destruction ____________________________________________

// __ Connector handling ______________________________________________________
//
Connector_Soul::soul_type_t Connector_Soul::type() {
	return m_soul_type;
}
//
// __ End Connector handling __________________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
