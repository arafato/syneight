// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/standard_mazegame_exception.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id$ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/exception/standard_mazegame_exception.hpp>
#include <syneight/base/exception/standard_exception_aspect.impl.hpp>


template class ::syneight::Standard_Exception_Aspect< ::mazegame::Mazegame_Exception>;
// vim:ts=4:sw=4
