// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/object.t.cpp
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

#include <syneight/test/mazegame2/object/object.hpp>

#include <syneight/base/config/namespace_category.impl.hpp>
SYNEIGHT__NAMESPACE_CATEGORY_INTERFACE;
SYNEIGHT__NAMESPACE_CATEGORY_IMPLEMENTATION("::");

void test_object_type() {
	::mazegame::Object test_object;

	SYNEIGHT__TEST__REL(test_object.object_type(),==, ::mazegame::Object::OT_OBJECT);
}

void test_object_put_in() {
	::mazegame::Object test_object;
	::mazegame::Object test_object2;

	SYNEIGHT__TES__THROW( test_object.put_in(&test_object2), ::mazegame::Wrong_Object_Type_Exception );
}

void test_object_apply_test() {
	::mazegame::Object test_object;
	::mazegame::Object test_object2;

	SYNEIGHT__TES__NOTHROW_ENTER;
       	test_object.apply("TEST", &test_object2);
	SYNEIGHT__TES__NOTHROW_EXIT_DROP;
}

void test_object_apply_quak() {
	::mazegame::Object test_object;
	::mazegame::Object test_object2;

	SYNEIGHT__TES__THROW( test_object2.apply("QUAK", &test_object2), ::mazegame::Unknown_Apply_Command_Exception );
}

int main() {

	test_object_type();
	test_object_put_in();

	test_object_apply_test();
	test_object_apply_quak();

}
// vim:ts=4:sw=4
