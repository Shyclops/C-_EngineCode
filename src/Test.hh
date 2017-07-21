
#ifndef TEST_HH
#define TEST_HH

#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace Test
{
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal isReadyIn( int X, int Y ) const;
        UMLRTOutSignal isStartIn( int X, int Y ) const;
    };
    enum SignalId
    {
        signal_isReadyIn = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_isStartIn,
        signal_isReadyOut,
        signal_isStartOut
    };
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal isReadyOut( int X, int Y ) const;
        UMLRTOutSignal isStartOut( int X, int Y ) const;
    };
};

#endif

