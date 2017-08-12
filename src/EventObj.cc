
#include "EventObj.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field EventObj::fields[] = 
{
};



const UMLRTObject_class UMLRTType_EventObj = 
{
    UMLRTObjectInitialize<EventObj>,
    UMLRTObjectCopy<EventObj>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<EventObj>,
    UMLRTObject_fprintf,
    "EventObj",
    NULL,
    {
        sizeof( EventObj ),
        0,
        EventObj::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};

