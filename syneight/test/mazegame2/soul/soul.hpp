// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/soul/soul.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__SOUL__SOUL_HPP
#define SYNEIGHT__TEST__MAZEGAME__SOUL__SOUL_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame2/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class Soul syneight/test/mazegame/soul/soul.hpp
 *
 * @brief Parent class for all Souls.
 *
 *
 * @nosubgrouping
 */
class Soul {

	/**
	 * @name Members
	 * @{
	 */
	/// @}

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Soul();
	virtual ~Soul();
	/// @}

	/**
	 * @name Soul type handling
	 * @{
	 */
public:
	typedef enum soul_type_t {
		ST_SOUL,
		ST_NULL,
		ST_CHARACTER,
		ST_CONNECTOR
	};

	/** 
	 * @brief Getting the type of a soul.
	 *
	 * There is no method for setting the type because there is no need for changing it after the creation.
	 */
	soul_type_t inline soul_type() { return m_soul_type; };

protected:
	soul_type_t m_soul_type;
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
