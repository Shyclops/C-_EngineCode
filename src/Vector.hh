
#ifndef VECTOR_HH
#define VECTOR_HH

#include "Zombie.hh"
#include "umlrtobjectclass.hh"

#include <vector>
#include <iostream>
using namespace std;

class Vector
{
public:
    Vector();
    Vector( const Vector & other );
    ~Vector();
    std::vector<Zombie> zVector;
    void addZVector( Zombie newV );
    Zombie getZombie( int index );
    friend ostream & operator<<(ostream & os, const Vector & v)
    {
        os << "Vector { ";
        int len = v.zVector.size();
        int i = 0;
        for (std::vector<Zombie>::const_iterator it = v.zVector.begin(); it != v.zVector.end(); it++, i++)
        {
            os << *it;
            if (i < len - 1) os << ", ";
        }
        os << " }";
        return os;
    }

    Vector & operator=( const Vector & other );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_Vector;

#endif

