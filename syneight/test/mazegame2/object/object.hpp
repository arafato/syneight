// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/object.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__OBJECT__OBJECT_HPP
#define SYNEIGHT__TEST__MAZEGAME__OBJECT__OBJECT_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame2/namespace.hpp>

#include <syneight/test/mazegame2/object/wrong_object_type_exception.hpp>
#include <syneight/test/mazegame2/object/unknown_apply_command_exception.hpp>
#include <syneight/test/mazegame2/soul/soul.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class Object syneight/test/mazegame/object/object.hpp
 *
 * @brief Parent class for all Objects.
 *
 *
 * @nosubgrouping
 */
class Object {

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Object();
	virtual ~Object();
	/// @}

	/**
	 * @name Object type handling
	 * @{
	 */
public:
	typedef enum object_type_t {
		OT_OBJECT,
		OT_CONTAINER,
		OT_CONNECTOR
	};

	/** 
	 * @brief Getting the type of an object.
	 *
	 * There is no method for setting the type because there is no need for changing it after the creation.
	 */
public:
	object_type_t object_type() { 
		SYNEIGHT__AUD__METHOD_ENTER("object_type_t Object::object_type()");

		return m_object_type;

		SYNEIGHT__AUD__METHOD_EXIT;
	};

protected:
	object_type_t m_object_type;
	/// @}

	/**
	 * @name Soul handling
	 * @{
	 */
public:
	void soul(Soul* soul) {
		SYNEIGHT__AUD__METHOD_ENTER("void Object::soul(Soul* soul)");

		m_soul = soul;

		SYNEIGHT__AUD__METHOD_EXIT;
	};
	Soul* soul() { 
		SYNEIGHT__AUD__METHOD_ENTER("Soul* Object::soul()");

		return m_soul;

		SYNEIGHT__AUD__METHOD_EXIT;
	};
protected:
	Soul* m_soul;
	/// @}

	/**
	 * @name Object handling
	 * @{
	 */
public:
	virtual void put_in(Object* parent);
	Object* parent();
protected:
	Object* m_parent;
	/// @}

	/**
	 * @command and further object method handling
	 * @{
	 */
public:
	void apply(const char cmd_code[4], Object* subject); /// @TODO virtual???
	/// @}

};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
