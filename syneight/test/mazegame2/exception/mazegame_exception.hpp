// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/mazegame_exception.hpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id$ 
 * 
 * @author Piotr Esden-Tempski
 */

#ifndef SYNEIGHT__TEST__MAZEGAME__MAZEGAME_EXCEPTION_HPP
#define SYNEIGHT__TEST__MAZEGAME__MAZEGAME_EXCEPTION_HPP

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/namespace.hpp>
#include <syneight/base/exception/exception.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

/**
 * @class Mazegame_Exception
 *
 * @brief The interface to all exceptions of the mazegame
 * environment.
 *
 * @nosubgrouping
 */

class Mazegame_Exception
    : public ::syneight::Exception 
{
public:
    virtual ~Mazegame_Exception() SYNEIGHT__EXCEPTION_NO_THROW;
};

SYNEIGHT__END__NAMESPACE__MAZEGAME;

#endif
// vim:ts=4:sw=4
