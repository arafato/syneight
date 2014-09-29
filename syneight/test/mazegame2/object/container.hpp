// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/object/container.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__OBJECT__CONTAINER_HPP
#define SYNEIGHT__TEST__MAZEGAME__OBJECT__CONTAINER_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame2/namespace.hpp>

#include <syneight/test/mazegame2/object/object.hpp>

#include <list>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;


/** 
 * @class Container syneight/test/mazegame/object/container.hpp
 *
 * @brief Parent class for all Containers.
 *
 *
 * @nosubgrouping
 */
class Container : public Object {

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Container();
	virtual ~Container();
	/// @}

	/**
	 * @name Object type handling
	 * @{
	 */
public:
	typedef enum container_type_t {
		CT_CONTAINER,
		CT_ROOM,
		CT_CHARACTER
	};

	/** 
	 * @brief Getting the type of an object.
	 *
	 * There is no method for setting the type because there is no need for changing it after the creation.
	 */
public:
	container_type_t container_type() {
		SYNEIGHT__AUD__METHOD_ENTER("container_type_t Container::container_type()");

		return m_container_type;

		SYNEIGHT__AUD__METHOD_EXIT;
	};

protected:
	container_type_t m_container_type;
	/// @}
	/**
	 * @name Object handling
	 * @{
	 */
public:
	/// @attention only to be used by object's put_in method (friend/protected stuff to do?)
	typedef ::std::list<Object*> object_list_t;

	void add(Object* object);
	void remove(Object* object);

protected:
	object_list_t m_object_list;
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
