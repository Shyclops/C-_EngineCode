
#include "Zombie*.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field Zombie*::fields[] = 
{
};


const UMLRTObject_class UMLRTType_Zombie* = 
{
    UMLRTObjectInitialize<Zombie*>,
    UMLRTObjectCopy<Zombie*>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<Zombie*>,
    UMLRTObject_fprintf,
    "Zombie*",
    NULL,
    {
        sizeof( Zombie* ),
        0,
        Zombie*::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};

