
#ifndef SCALARCONT_HH
#define SCALARCONT_HH

#include "umlrtobjectclass.hh"

#include "external_resources/opencv/sources/modules/core/include/opencv2/core.hpp"
#include "external_resources/opencv/sources/modules/highgui/include/opencv2/highgui.hpp"

class ScalarCont
{
public:
    ScalarCont();
    ScalarCont( const ScalarCont & other );
    ~ScalarCont();
    ScalarCont & operator=( const ScalarCont & other );
    static const UMLRTObject_field fields[];
};
extern const UMLRTObject_class UMLRTType_ScalarCont;

#endif

