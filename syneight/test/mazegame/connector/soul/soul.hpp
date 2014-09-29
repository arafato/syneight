// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/soul/soul.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__CONNECTOR__SOUL__SOUL_HPP
#define SYNEIGHT__TEST__MAZEGAME__CONNECTOR__SOUL__SOUL_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class Connector_Soul syneight/test/mazegame/connector/soul/soul.hpp
 *
 * @brief Parent class for all Connector_Souls.
 *
 * This class is not meant to be directly used as content of a Connector. It is
 * only meant as a parent to all different Connector types like Wall or
 * Passage.
 *
 * @nosubgrouping
 */
class Connector_Soul {

	/**
	 * @name Members
	 * @{
	 */
public:
	/// @brief Enumeration of different connector types.
	typedef enum soul_type_t {m_null, m_wall, m_passage}; 
protected:
	/// @brief What type of soul am I?
	soul_type_t m_soul_type;	
	/// @}

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Connector_Soul();
	virtual ~Connector_Soul();
	/// @}

	/**
	 * @name Connector handling
	 * @{
	 */
	soul_type_t type();
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
