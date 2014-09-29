// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/standard_mazegame_exception.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id$ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__STANDARD_MAZEGAME_EXCEPTION_HPP
#define SYNEIGHT__TEST__MAZEGAME__STANDARD_MAZEGAME_EXCEPTION_HPP

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/namespace.hpp>
#include <syneight/test/mazegame2/exception/mazegame_exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/**
 * @class Standard_Mazegame_Exception
 *
 * @brief Standard implementation @ref Mazegame_Exception.
 */
typedef ::syneight::Standard_Exception_Aspect<Mazegame_Exception> Standard_Mazegame_Exception;

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif
// vim:ts=4:sw=4
