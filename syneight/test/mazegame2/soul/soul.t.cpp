// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/soul/soul.t.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id$ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/unittest.hpp>
#include <syneight/test/mazegame2/logging/mazegame_category.hpp>

#include <syneight/test/mazegame2/soul/soul.hpp>

#include <syneight/base/config/namespace_category.impl.hpp>
SYNEIGHT__NAMESPACE_CATEGORY_INTERFACE;
SYNEIGHT__NAMESPACE_CATEGORY_IMPLEMENTATION("::");

int main() { 
	int return_val = 0;
	::mazegame::Soul test_soul;

	SYNEIGHT__AUD__TRACE("Soul created");

	switch ( test_soul.soul_type() ) {
		case ::mazegame::Soul::ST_SOUL:
			SYNEIGHT__AUD__TRACE("Soul type is ok");
			break;
		default:
			SYNEIGHT__AUD__TRACE("Soul type is WRONG");
			return_val = 1;
	}

	return return_val;
}
// vim:ts=4:sw=4
