
#include "Status.hh"

#include "VectorWrapper.hh"
#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
#include <cstddef>
struct UMLRTCommsPort;

struct params_isReadyIn
{
    int X;
    int Y;
};

static UMLRTObject_field fields_isReadyIn[] = 
{
    {
        "X",
        &UMLRTType_int,
        offsetof( params_isReadyIn, X ),
        1,
        0
    },
    {
        "Y",
        &UMLRTType_int,
        offsetof( params_isReadyIn, Y ),
        1,
        0
    }
};

static UMLRTObject payload_isReadyIn = 
{
    sizeof( params_isReadyIn ),
    2,
    fields_isReadyIn
};

static UMLRTObject_field fields_isStartIn[] = 
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

static UMLRTObject payload_isStartIn = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_isStartIn
};

struct params_isReadyOut
{
    int X;
    int Y;
};

static UMLRTObject_field fields_isReadyOut[] = 
{
    {
        "X",
        &UMLRTType_int,
        offsetof( params_isReadyOut, X ),
        1,
        0
    },
    {
        "Y",
        &UMLRTType_int,
        offsetof( params_isReadyOut, Y ),
        1,
        0
    }
};

static UMLRTObject payload_isReadyOut = 
{
    sizeof( params_isReadyOut ),
    2,
    fields_isReadyOut
};

struct params_isStartOut
{
    int X;
    int Y;
};

static UMLRTObject_field fields_isStartOut[] = 
{
    {
        "X",
        &UMLRTType_int,
        offsetof( params_isStartOut, X ),
        1,
        0
    },
    {
        "Y",
        &UMLRTType_int,
        offsetof( params_isStartOut, Y ),
        1,
        0
    }
};

static UMLRTObject payload_isStartOut = 
{
    sizeof( params_isStartOut ),
    2,
    fields_isStartOut
};

struct params_zombieOut
{
    VectorWrapper data;
    int max;
};

static UMLRTObject_field fields_zombieOut[] = 
{
    {
        "data",
        &UMLRTType_VectorWrapper,
        offsetof( params_zombieOut, data ),
        1,
        0
    },
    {
        "max",
        &UMLRTType_int,
        offsetof( params_zombieOut, max ),
        1,
        0
    }
};

static UMLRTObject payload_zombieOut = 
{
    sizeof( params_zombieOut ),
    2,
    fields_zombieOut
};

Status::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Status::Conj::isReadyIn( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isReadyIn", signal_isReadyIn, srcPort, &payload_isReadyIn, &X, &Y );
    return signal;
}

UMLRTOutSignal Status::Conj::isStartIn() const
{
    UMLRTOutSignal signal;
    signal.initialize( "isStartIn", signal_isStartIn, srcPort, &payload_isStartIn );
    return signal;
}

Status::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Status::Base::isReadyOut( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isReadyOut", signal_isReadyOut, srcPort, &payload_isReadyOut, &X, &Y );
    return signal;
}

UMLRTOutSignal Status::Base::isStartOut( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isStartOut", signal_isStartOut, srcPort, &payload_isStartOut, &X, &Y );
    return signal;
}

UMLRTOutSignal Status::Base::zombieOut( const VectorWrapper & data, int max ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "zombieOut", signal_zombieOut, srcPort, &payload_zombieOut, &data, &max );
    return signal;
}


