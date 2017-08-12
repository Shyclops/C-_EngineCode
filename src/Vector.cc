
#include "Vector.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field Vector::fields[] = 
{
};
Vector::Vector()
{
}

Vector::Vector( const Vector & other )
{
    zVector = other.zVector;
}

Vector::~Vector()
{
}


void Vector::addZVector( Zombie newV )
{
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Vector operation addZVector */
    zVector.push_back(newV);
    /* UMLRTGEN-USERREGION-END */
}

Zombie Vector::getZombie( int index )
{
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Vector operation getZombie */
    return zVector[index];
    /* UMLRTGEN-USERREGION-END */
}


Vector & Vector::operator=( const Vector & other )
{
    if( &other == this )
        return *this;
    zVector = other.zVector;
    return *this;
}



const UMLRTObject_class UMLRTType_Vector = 
{
    UMLRTObjectInitialize<Vector>,
    UMLRTObjectCopy<Vector>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<Vector>,
    UMLRTObject_fprintf,
    "Vector",
    NULL,
    {
        sizeof( Vector ),
        0,
        Vector::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};

