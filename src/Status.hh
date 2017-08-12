
#ifndef STATUS_HH
#define STATUS_HH

#include "VectorWrapper.hh"
#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace Status
{
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal isReadyIn( int X, int Y ) const;
        UMLRTOutSignal isStartIn() const;
    };
    enum SignalId
    {
        signal_isReadyIn = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_isStartIn,
        signal_isReadyOut,
        signal_isStartOut,
        signal_zombieOut
    };
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal isReadyOut( int X, int Y ) const;
        UMLRTOutSignal isStartOut( int X, int Y ) const;
        UMLRTOutSignal zombieOut( const VectorWrapper & data, int max ) const;
    };
};

#endif

