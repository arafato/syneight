// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/soul/wall.t.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id:$ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/unittest.hpp>
#include <syneight/test/mazegame/logging/mazegame_category.hpp>

#include <syneight/test/mazegame/connector/soul/wall.hpp>

#include <iostream>

int main() { 
	::mazegame::Connector_Soul_Wall* test_soul;

	test_soul = new ::mazegame::Connector_Soul_Wall();

	::std::cout << "Connector_Soul_Wall created\n";

	delete test_soul;

	return 0;
}
// vim:ts=4:sw=4
