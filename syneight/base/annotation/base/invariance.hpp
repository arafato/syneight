/*-----------------------------------------------------------------------------
 * Syneight - A soft-realtime transaction monitor.
 * Copyright (C) 2003-2004 The Syneight Group.
 *
 * TODO: License.
 *---------------------------------------------------------------------------*/

/**
 * @file TODO
 *
 * @author TODO
 * @author $Author: esdentem $
 *
 * @version $Id: invariance.hpp 1053 2005-06-07 12:14:38Z esdentem $
 *
 * @brief TODO
 *
 * TODO: Long description.
 *
 * @note TODO
 *
 * @todo TODO
 */

#ifndef SYNEIGHT__ANNOTATION__BASE__INVARIANCE_HPP
#define SYNEIGHT__ANNOTATION__BASE__INVARIANCE_HPP

#include <syneight/base/annotation/namespace.hpp>

////////////////////////////////////////////////////////////////////////////////
//
// Adaption Macros
//
////////////////////////////////////////////////////////////////////////////////


#define SYNEIGHT__INTERNAL__INVARIANCE_GUARD(LEVEL) \
           ::syneight::annotation::internal::Class_Invariance_Guard<Self> \
           syneight_reserved_name_internal_class_invariance_guard(this)

#define SYNEIGHT__INTERNAL__INVARIANCE_ASSERT(LEVEL)  this->class_invariance()



SYNEIGHT__BEGIN__NAMESPACE__SYNEIGHT;
SYNEIGHT__BEGIN__NAMESPACE__ANNOTATION;
SYNEIGHT__BEGIN__NAMESPACE__INTERNAL;

/**
 * @brief Helper for Class-Invariance Checking. On construction and
 * description, the invariance is checked. The check is performed by
 * calling an argumentless void method. 
 */
template<typename CLASS>
class Class_Invariance_Guard
{
public:
   inline Class_Invariance_Guard(CLASS const * const object)
       : m_object(*object)
    {
	(m_object.class_invariance)();
    }
    
    inline ~Class_Invariance_Guard()
    {
	(m_object.class_invariance)();
    }
    
    
private:
    CLASS const & m_object;
};

SYNEIGHT__END__NAMESPACE__INTERNAL;
SYNEIGHT__END__NAMESPACE__ANNOTATION;
SYNEIGHT__END__NAMESPACE__SYNEIGHT;


////////////////////////////////////////////////////////////////////////////////
//
// Derived Macros
//
////////////////////////////////////////////////////////////////////////////////


#define SYNEIGHT__INTERNAL__INVARIANCE_ENTER(LEVEL) \
  do { SYNEIGHT__INTERNAL__INVARIANCE_GUARD(LEVEL); { ((void)0)

#define SYNEIGHT__INTERNAL__INVARIANCE_EXIT }} while(false) 



#endif
// vim:ts=4:sw=4
