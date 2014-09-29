// ----------------------------------------------------------------------------
// Syneight - A soft-realtime transaction monitor
// Copyright (C) 2003-2004 The Syneight Group
//
// TODO: License.
// ----------------------------------------------------------------------------

/** 
 * @file syneight/test/mazegame/soul/soul.cpp
 * 
 * @brief [LEVEL: alpha]
 * 
 * $Id: soul.hpp 502 2004-03-19 17:40:46Z esdentem $ 
 * 
 * @author Piotr Esden-Tempski
 */

#include <syneight/base/config/production.hpp>
#include <syneight/test/mazegame2/logging/mazegame_category.hpp>

#include <syneight/test/mazegame2/soul/soul.hpp>

SYNEIGHT__BEGIN__NAMESPACE__MAZEGAME;

// __ Creation and Destruction ________________________________________________
//
Soul::Soul() : m_soul_type(ST_SOUL)
{
	SYNEIGHT__AUD__TRACE("Creating Soul obj");
}

Soul::~Soul() 
{
	SYNEIGHT__AUD__TRACE("Destroying Soul obj");
}
//
// __ End Creation and Destruction ____________________________________________

SYNEIGHT__END__NAMESPACE__MAZEGAME;
// vim:ts=4:sw=4
