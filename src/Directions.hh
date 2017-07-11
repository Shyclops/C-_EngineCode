
#ifndef DIRECTIONS_HH
#define DIRECTIONS_HH

#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace Directions
{
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal direction( int Direction ) const;
        UMLRTOutSignal directionCalc( int X, int Y ) const;
        UMLRTOutSignal exit() const;
    };
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal directions( int Direction ) const;
        UMLRTOutSignal directionsCalc( int X, int Y, int Direction ) const;
        UMLRTOutSignal exits() const;
    };
    enum SignalId
    {
        signal_directions = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_directionsCalc,
        signal_exits,
        signal_direction,
        signal_directionCalc,
        signal_exit
    };
};

#endif

