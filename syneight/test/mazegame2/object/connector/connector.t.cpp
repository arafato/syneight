// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/connector.t.cpp
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

#include <syneight/test/mazegame2/object/connector/connector.hpp>

#include <syneight/base/config/namespace_category.impl.hpp>
SYNEIGHT__NAMESPACE_CATEGORY_INTERFACE;
SYNEIGHT__NAMESPACE_CATEGORY_IMPLEMENTATION("::");

void test_connector_type() 
{
    ::mazegame::Connector test_connector;
    
    SYNEIGHT__TEST__REL(test_connector.object_type(),==, ::mazegame::Object::OT_CONNECTOR);
}

int main() 
{ 
    test_connector_type();
}
// vim:ts=4:sw=4
