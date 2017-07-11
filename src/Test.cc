
#include "Test.hh"

#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
#include <cstddef>
struct UMLRTCommsPort;

struct params_isReadyIn
{
    int X;
    int Y;
    int Height;
    int Width;
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
    },
    {
        "Height",
        &UMLRTType_int,
        offsetof( params_isReadyIn, Height ),
        1,
        0
    },
    {
        "Width",
        &UMLRTType_int,
        offsetof( params_isReadyIn, Width ),
        1,
        0
    }
};

static UMLRTObject payload_isReadyIn = 
{
    sizeof( params_isReadyIn ),
    4,
    fields_isReadyIn
};

static UMLRTObject_field fields_isStartIn[] = 
{
    {
        "R",
        &UMLRTType_uchar,
        0,
        1,
        0
    }
};

static UMLRTObject payload_isStartIn = 
{
    sizeof( unsigned char ),
    1,
    fields_isStartIn
};

struct params_isReadyOut
{
    int X;
    int Y;
    int Height;
    int Width;
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
    },
    {
        "Height",
        &UMLRTType_int,
        offsetof( params_isReadyOut, Height ),
        1,
        0
    },
    {
        "Width",
        &UMLRTType_int,
        offsetof( params_isReadyOut, Width ),
        1,
        0
    }
};

static UMLRTObject payload_isReadyOut = 
{
    sizeof( params_isReadyOut ),
    4,
    fields_isReadyOut
};

static UMLRTObject_field fields_isStartOut[] = 
{
    {
        "Flag",
        &UMLRTType_bool,
        0,
        1,
        0
    }
};

static UMLRTObject payload_isStartOut = 
{
    sizeof( bool ),
    1,
    fields_isStartOut
};

Test::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Test::Conj::isReadyIn( int X, int Y, int Height, int Width ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isReadyIn", signal_isReadyIn, srcPort, &payload_isReadyIn, &X, &Y, &Height, &Width );
    return signal;
}

UMLRTOutSignal Test::Conj::isStartIn( unsigned char R ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isStartIn", signal_isStartIn, srcPort, &payload_isStartIn, &R );
    return signal;
}

Test::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Test::Base::isReadyOut( int X, int Y, int Height, int Width ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isReadyOut", signal_isReadyOut, srcPort, &payload_isReadyOut, &X, &Y, &Height, &Width );
    return signal;
}

UMLRTOutSignal Test::Base::isStartOut( bool Flag ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "isStartOut", signal_isStartOut, srcPort, &payload_isStartOut, &Flag );
    return signal;
}


