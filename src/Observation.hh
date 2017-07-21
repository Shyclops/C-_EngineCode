
#ifndef OBSERVATION_HH
#define OBSERVATION_HH

#include "Event.hh"
#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace Observation
{
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal event( const Event & data ) const;
    };
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
    };
    enum SignalId
    {
        signal_event = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID
    };
};

#endif

