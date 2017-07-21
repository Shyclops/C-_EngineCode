
#include "Test.hh"

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

struct params_isStartIn
{
    int X;
    int Y;
};

static UMLRTObject_field fields_isStartIn[] = 
{
    {
        "X",
        &UMLRTType_int,
        offsetof( params_isStartIn, X ),
        1,
        0
    },
    {
        "Y",
        &UMLRTType_int,
        offsetof( params_isStartIn, Y ),
        1,
        0
    }
};

static UMLRTObject payload_isStartIn = 
{
    sizeof( params_isStartIn ),
    2,
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

Test::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Test::Conj::isReadyIn( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isReadyIn", signal_isReadyIn, srcPort, &payload_isReadyIn, &X, &Y );
    return signal;
}

UMLRTOutSignal Test::Conj::isStartIn( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isStartIn", signal_isStartIn, srcPort, &payload_isStartIn, &X, &Y );
    return signal;
}

Test::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Test::Base::isReadyOut( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isReadyOut", signal_isReadyOut, srcPort, &payload_isReadyOut, &X, &Y );
    return signal;
}

UMLRTOutSignal Test::Base::isStartOut( int X, int Y ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isStartOut", signal_isStartOut, srcPort, &payload_isStartOut, &X, &Y );
    return signal;
}


