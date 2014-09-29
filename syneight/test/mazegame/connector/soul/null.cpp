// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/soul/null.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: null.cpp 730 2004-04-20 17:35:21Z schallha $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/connector/soul/null.hpp>

#include <iostream>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

Connector_Soul_Null::Connector_Soul_Null() {
    SYNEIGHT__AUD__TRACE("creating Connector_Soul_Null obj");
    
    m_soul_type = m_null;
}

Connector_Soul_Null::~Connector_Soul_Null() {
    SYNEIGHT__AUD__TRACE("destroying Connector_Soul_Null obj");
}

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
