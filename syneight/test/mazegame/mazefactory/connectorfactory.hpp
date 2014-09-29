// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazefactory/connectorfactory.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: connectorfactory.hpp 1053 2005-06-07 12:14:38Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__MAZEFACTORY__CONNECTORFACTORY_HPP
#define SYNEIGHT__TEST__MAZEGAME__MAZEFACTORY__CONNECTORFACTORY_HPP

#include <syneight/base/config/production.hpp>

#include <syneight/test/mazegame/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// This forward declaration is needed because of the circular includes
// connector.hpp->room.hpp->mazefactory_connectorfactory.hpp->connector.hpp.
class Connector;

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#include <syneight/test/mazegame/connector/connector.hpp>
#include <syneight/test/mazegame/connector/soul/soul.hpp>
#include <syneight/test/mazegame/connector/soul/wall.hpp>
#include <syneight/test/mazegame/connector/soul/passage.hpp>
#include <syneight/test/mazegame/connector/soul/null.hpp>
#include <syneight/test/mazegame/room.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/** 
 * @class Connector_Factory syneight/test/mazegame/mazefactory/connectorfactory.hpp
 *
 * @brief Factory for creating connectors.
 *
 * @nosubgrouping
 */
class Connector_Factory {

	/**
	 * @name Members
	 * @{     
	 */
public:
	/// @}

	/**
	 * @name Factory
	 * @{
	 */
public:
	/**
	 * @brief Replacement Method for the constructor.
	 *
	 * That method is to be used to get a reference to the
	 * Connector_Factory. It is the replacement for the constructor. It is
	 * there to prevent the existence of more then one instance of
	 * Connector_Factory class in the memory what would be unnessesary.
	 */
	static Connector_Factory* instance();
	/// @brief Simply the destructor of MazeFactory.
	~Connector_Factory();
	
private:
	/**
	 * @brief Constructor only ment to be used from inside of Connector_Factory class.
	 *
	 * The constructor is protected because it is not ment to be used from
	 * outside of the class instead use Instance() method for getting a
	 * reference to that class. See the factory pattern.
	 */
	Connector_Factory();
	/// @brief The reference to the one ever existing instance of Connector_Factory class.
	static Connector_Factory* p_instance;
	/// @}

	/**
	 * @name Methods
	 * @{
	 */
public:

	/**
	 * @brief Connector_Soul creation method.
	 *
	 * This method is creating a Connector_Soul indicated by the SoulType. It is
	 * returning a reference to a soul object.
	 */
	Connector_Soul* create_soul(::mazegame::Connector_Soul::soul_type_t soul_type);
	/**
	 * @brief Wall creation method.
	 *
	 * This method creates a Connector object containing a SoulWall. It is
	 * using the createSoul method to create the soul.
	 */
	Connector* create_wall();
	/// @}
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif

// vim:ts=4:sw=4
