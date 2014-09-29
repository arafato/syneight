// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/soul/null.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: null.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__CONNECTOR__SOUL__NULL_HPP
#define SYNEIGHT__TEST__MAZEGAME__CONNECTOR__SOUL__NULL_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/connector/soul/soul.hpp>
#include <syneight/test/mazegame/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/**
 * @class Connector_Soul_Null syneight/test/mazegame/connector/soul/null.hpp
 *
 * @brief Soul representing null behaviour.
 *
 * @nosubgrouping
 */
class Connector_Soul_Null : Connector_Soul {

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Connector_Soul_Null();
	~Connector_Soul_Null();
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
