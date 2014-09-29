// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/soul/wall.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: wall.cpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/connector/soul/wall.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

Connector_Soul_Wall::Connector_Soul_Wall() {
    SYNEIGHT__AUD__TRACE("creating Connector_Soul_Wall obj");
    
    m_soul_type = m_wall;
}

Connector_Soul_Wall::~Connector_Soul_Wall() {
    SYNEIGHT__AUD__TRACE("destroying Connector_Soul_Wall obj");
}

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
