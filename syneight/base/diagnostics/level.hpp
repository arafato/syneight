/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file syneight/base/diagnostics/level.hpp
 *
 * @author Christian Schallhart
 * @author Oliver Arafat
 * @author $Author: esdentem $
 *
 * @version $Id: level.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief @ref ::syneight::diagnostics::Level_t,
 * ::syneight::diagnostics::level_to_string
 *
 * TODO: Long description.
 *
 * @note CLEAN
 *
 * @todo Add test.
 */

#ifndef SYNEIGHT__BASE__DIAGNOSTICS__LEVEL_HPP
#define SYNEIGHT__BASE__DIAGNOSTICS__LEVEL_HPP

#include <syneight/base/diagnostics/namespace.hpp>

SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__DIAGNOSTICS;

/**
 * @brief Serves primarily as the level of a diagnostic @ref
 * Event. BUT BE AWARE that these levels are used in other contexts.
 *
 * In particular, there are the following ''levels'' within syneight: 
 *
 * @arg annoation_level: The level of a particular annoation. E.g., an @ref
 * SYNEIGHT__AUD__ASSERT has annoation level AUD_LEVEL while an @ref
 * SYNEIGHT__PRO__ASSERT has PRO_LEVEL. 
 *
 * @arg build_level: The level of annotations which are built into the
 * binary (aka the debug level). It can be AUD_LEVEL (all
 * annotations), DEB_LEVEL (all annotations<=DEB_LEVEL), PRO_LEVEL
 * (all annotations<=PRO_LEVEL) or SYS_LEVEL (all annotations
 * <=TES_LEVEL). The latter appears to be confusing, however, the test
 * annotations are switched separately. You can refer to the build
 * level with @ref SYNEIGHT__BUILD_LEVEL and switch it with @ref
 * SYNEIGHT__SWITCH__BUILD_LEVEL.
 *
 * @arg test_level: A given unit test must have a specified test_level. A
 * test with test_level PRO_LEVEL has to succeed at all build_levels
 * >=PRO_LEVEL, a test with test_level DEB_LEVEL (AUD_LEVEL) at all
 * build_levels >=DEB_LEVEL (>=AUD_LEVEL). A test is allowed to behave
 * arbitrarily at build_level SYS_LEVEL. Note, that all possible
 * test_levels have to tested.
 *
 * Note that the developer is confronted with the following decisions
 * wrt. ''levels'': @arg which annoation_level to choose for a given
 * annoation? @arg which test_level to choose for a given test?
 */ 
typedef enum {
    /**
     * @brief AUDIT: An audit annoation is meant for testing the component
     * which contains the annoation. E.g., for invariances of classes.
     */ 
    AUD_LEVEL=6,
    /**
     * @brief DEBUG: A debug annoation is meant for testing components
     * which use the component which contains the annoation. E.g., for
     * pre-conditions of methods.
     */ 
    DEB_LEVEL=5,
    /**
     * @brief PRODUCTION: A production annoation will remain in the
     * production binary.
     */ 
    PRO_LEVEL=4,
    /**
     * @brief ALERT: An alert annoation will remain in the production
     * binary and is meant to signify an alert condition.
     */ 
    ALE_LEVEL=3,
    /**
     * @brief EMERGENCY: An emergency annoation will remain in the
     * production binary and is used in emergency situations (more
     * alert than ALE_LEVEL).
     */ 
    EME_LEVEL=2,
    /**
     * @brief TEST: A test annoation is used for testing only. It is
     * not contained in any production code.
     */ 
    TES_LEVEL=1,
    /**
     * @brief SYSTEM: There are no system annoations. Only
     * ::syneight::diagnostics and modules which operate within the
     * ::syneight::diagnostics kernel are allowed to send system
     * annoations.
     */ 
    SYS_LEVEL=0
} Level_t;

/**
 * @brief returns string which contains the first three letters of
 * each enum type. BE AWARE, it returns "UNK" if the @a level is
 * unknown.
 *
 * @throw never
 */ 
char const * level_to_string(Level_t const level);

SYNEIGHT__END__NAMESPACE__DIAGNOSTICS;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;

#endif
// vim:ts=4:sw=4
