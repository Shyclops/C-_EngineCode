
#ifndef VECTORWRAPPER_HH
#define VECTORWRAPPER_HH

#include "Vector.hh"
#include "umlrtobjectclass.hh"

class VectorWrapper
{
public:
    Vector zombieVectorWrapper;
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_VectorWrapper;

#endif

