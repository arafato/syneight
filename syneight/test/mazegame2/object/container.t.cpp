// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/container.t.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id$ 
 * 
 * @author Piotr Esden-Tempski
 *
 * @todo everything must be in a namespace. The correct namespaces are
 * not yet determined. Especially: There is no root category at global
 * scope.
 */

#include <syneight/base/config/unittest.hpp>
#include <syneight/test/mazegame2/logging/mazegame_category.hpp>

#include <syneight/test/mazegame2/object/container.hpp>
#include <syneight/test/mazegame2/object/object.hpp>

#include <syneight/base/config/namespace_category.impl.hpp>
SYNEIGHT__NAMESPACE_CATEGORY_INTERFACE;
SYNEIGHT__NAMESPACE_CATEGORY_IMPLEMENTATION("::");


void test_container_type() {
	::mazegame::Container test_container;

	SYNEIGHT__TEST__REL(test_container.object_type(),==, ::mazegame::Object::OT_CONTAINER);
}

void test_container_add() {
	::mazegame::Container test_container;
	::mazegame::Object test_object;

	test_object.put_in(&test_container);
}

int main() { 

	test_container_type();

	test_container_add();

}
// vim:ts=4:sw=4
