
#include "VectorWrapper.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field VectorWrapper::fields[] = 
{
    {
        "zombieVectorWrapper",
        &UMLRTType_Vector,
        offsetof( VectorWrapper, zombieVectorWrapper ),
        1,
        0
    }
};



const UMLRTObject_class UMLRTType_VectorWrapper = 
{
    UMLRTObjectInitialize<VectorWrapper>,
    UMLRTObjectCopy<VectorWrapper>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<VectorWrapper>,
    UMLRTObject_fprintf,
    "VectorWrapper",
    NULL,
    {
        sizeof( VectorWrapper ),
        1,
        VectorWrapper::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};

