// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/connector/soul/passage.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: passage.hpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__CONNECTOR__SOUL__PASSAGE_HPP
#define SYNEIGHT__TEST__MAZEGAME__CONNECTOR__SOUL__PASSAGE_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/connector/soul/soul.hpp>
#include <syneight/test/mazegame/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class Connector_Soul_Passage syneight/test/mazegame/connector/soul/passage.hpp
 *
 * @brief Soul representing behaviour of a Passage.
 *
 * @nosubgrouping
 */
class Connector_Soul_Passage : Connector_Soul {

	/**
	 * @name Creation and Destruction
	 * @{
	 */
public:
	Connector_Soul_Passage();
	~Connector_Soul_Passage();
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
