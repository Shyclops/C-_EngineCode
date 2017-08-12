
#include "Zombie.hh"

#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"
#include <cstddef>

const UMLRTObject_field Zombie::fields[] = 
{
    {
        "x",
        &UMLRTType_int,
        offsetof( Zombie, x ),
        1,
        0
    },
    {
        "y",
        &UMLRTType_int,
        offsetof( Zombie, y ),
        1,
        0
    },
    {
        "d",
        &UMLRTType_int,
        offsetof( Zombie, d ),
        1,
        0
    }
};
Zombie::Zombie()
{
}

Zombie::Zombie( const Zombie & other )
{
    x = other.x;
    y = other.y;
    d = other.d;
}

Zombie::~Zombie()
{
}




void Zombie::move( int newX, int newY )
{
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Zombie operation move */
    this->x = newX;
    this->y = newY;
    /* UMLRTGEN-USERREGION-END */
}

void Zombie::changeDirection( int newD )
{
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Zombie operation changeDirection */
    this->d = newD;
    /* UMLRTGEN-USERREGION-END */
}

int Zombie::currentDirection()
{
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Zombie operation currentDirection */
    return (d);
    /* UMLRTGEN-USERREGION-END */
}

int Zombie::getX()
{
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Zombie operation getX */
    return x;
    /* UMLRTGEN-USERREGION-END */
}

int Zombie::getY()
{
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Zombie operation getY */
    return y;
    /* UMLRTGEN-USERREGION-END */
}


Zombie & Zombie::operator=( const Zombie & other )
{
    if( &other == this )
        return *this;
    x = other.x;
    y = other.y;
    d = other.d;
    return *this;
}



const UMLRTObject_class UMLRTType_Zombie = 
{
    UMLRTObjectInitialize<Zombie>,
    UMLRTObjectCopy<Zombie>,
    UMLRTObject_decode,
    UMLRTObject_encode,
    UMLRTObjectDestroy<Zombie>,
    UMLRTObject_fprintf,
    "Zombie",
    NULL,
    {
        sizeof( Zombie ),
        3,
        Zombie::fields
    },
    UMLRTOBJECTCLASS_DEFAULT_VERSION,
    UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};

