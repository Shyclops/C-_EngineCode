
#include "Directions.hh"

#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
#include <cstddef>
struct UMLRTCommsPort;

static UMLRTObject_field fields_directions[] = 
{
    {
        "Direction",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_directions = 
{
    sizeof( int ),
    1,
    fields_directions
};

struct params_directionsCalc
{
    int X;
    int Y;
    int Direction;
};

static UMLRTObject_field fields_directionsCalc[] = 
{
    {
        "X",
        &UMLRTType_int,
        offsetof( params_directionsCalc, X ),
        1,
        0
    },
    {
        "Y",
        &UMLRTType_int,
        offsetof( params_directionsCalc, Y ),
        1,
        0
    },
    {
        "Direction",
        &UMLRTType_int,
        offsetof( params_directionsCalc, Direction ),
        1,
        0
    }
};

static UMLRTObject payload_directionsCalc = 
{
    sizeof( params_directionsCalc ),
    3,
    fields_directionsCalc
};

static UMLRTObject_field fields_exits[] = 
{
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    {
        0,
        0,
        0,
        0,
        0
    }
    #endif
};

static UMLRTObject payload_exits = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_exits
};

static UMLRTObject_field fields_direction[] = 
{
    {
        "Direction",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_direction = 
{
    sizeof( int ),
    1,
    fields_direction
};

struct params_directionCalc
{
    int X;
    int Y;
};

static UMLRTObject_field fields_directionCalc[] = 
{
    {
        "X",
        &UMLRTType_int,
        offsetof( params_directionCalc, X ),
        1,
        0
    },
    {
        "Y",
        &UMLRTType_int,
        offsetof( params_directionCalc, Y ),
        1,
        0
    }
};

static UMLRTObject payload_directionCalc = 
{
    sizeof( params_directionCalc ),
    2,
    fields_directionCalc
};

static UMLRTObject_field fields_exit[] = 
{
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    {
        0,
        0,
        0,
        0,
        0
    }
    #endif
};

static UMLRTObject payload_exit = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_exit
};

Directions::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Directions::Base::direction( int Direction ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "direction", signal_direction, srcPort, &payload_direction, &Direction );
    return signal;
}

UMLRTOutSignal Directions::Base::directionCalc( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "directionCalc", signal_directionCalc, srcPort, &payload_directionCalc, &X, &Y );
    return signal;
}

UMLRTOutSignal Directions::Base::exit() const
{
    UMLRTOutSignal signal;
    signal.initialize( "exit", signal_exit, srcPort, &payload_exit );
    return signal;
}

Directions::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Directions::Conj::directions( int Direction ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "directions", signal_directions, srcPort, &payload_directions, &Direction );
    return signal;
}

UMLRTOutSignal Directions::Conj::directionsCalc( int X, int Y, int Direction ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "directionsCalc", signal_directionsCalc, srcPort, &payload_directionsCalc, &X, &Y, &Direction );
    return signal;
}

UMLRTOutSignal Directions::Conj::exits() const
{
    UMLRTOutSignal signal;
    signal.initialize( "exits", signal_exits, srcPort, &payload_exits );
    return signal;
}


