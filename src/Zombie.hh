
#ifndef ZOMBIE_HH
#define ZOMBIE_HH

#include "umlrtobjectclass.hh"

#include <iostream>

using namespace std;

class Zombie
{
public:
    Zombie();
    Zombie( const Zombie & other );
    ~Zombie();
    int x;
    int y;
    int d;
    void move( int newX, int newY );
    void changeDirection( int newD );
    int currentDirection();
    int getX();
    int getY();
    friend ostream & operator<<( ostream & os, const Zombie & z)
    {
        os << "Zombie(\"" << z.x << z.y << z.d << "\")";
        return os;
    }

    Zombie & operator=( const Zombie & other );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_Zombie;

#endif

