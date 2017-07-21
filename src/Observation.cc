
#include "Observation.hh"

#include "Event.hh"
#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
struct UMLRTCommsPort;

static UMLRTObject_field fields_event[] = 
{
    {
        "data",
        &UMLRTType_Event,
        0,
        1,
        0
    }
};

static UMLRTObject payload_event = 
{
    sizeof( Event ),
    1,
    fields_event
};

Observation::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal Observation::Base::event( const Event & data ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "event", signal_event, srcPort, &payload_event, &data );
    return signal;
}

Observation::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}


