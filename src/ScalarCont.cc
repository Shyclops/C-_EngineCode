
#include "ScalarCont.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

#include "external_resources/opencv/sources/modules/core/include/opencv2/core.hpp"
#include "external_resources/opencv/sources/modules/highgui/include/opencv2/highgui.hpp"

const UMLRTObject_field ScalarCont::fields[] = 
{
};
ScalarCont::ScalarCont()
{
}

ScalarCont::ScalarCont( const ScalarCont & other )
{
}

ScalarCont::~ScalarCont()
{
}

ScalarCont & ScalarCont::operator=( const ScalarCont & other )
{
    if( &other == this )
        return *this;
    return *this;
}



const UMLRTObject_class UMLRTType_ScalarCont = 
{
    UMLRTObjectInitialize<ScalarCont>,
    UMLRTObjectCopy<ScalarCont>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<ScalarCont>,
    UMLRTObject_fprintf,
    "ScalarCont",
    NULL,
    {
        sizeof( ScalarCont ),
        0,
        ScalarCont::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};

