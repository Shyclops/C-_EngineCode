
#ifndef EVENTOBJ_HH
#define EVENTOBJ_HH

#include "umlrtobjectclass.hh"

#include "Event.hh"

class EventObj
{
public:
    Event event;

    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_EventObj;

#endif

