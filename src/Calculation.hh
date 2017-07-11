
#ifndef CALCULATION_HH
#define CALCULATION_HH

#include "Directions.hh"
#include "Test.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Calculation : public UMLRTCapsule
{
public:
    Capsule_Calculation( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    Directions::Base directions;
public:
    enum BorderPortId
    {
        borderport_directions,
        borderport_test
    };
protected:
    Directions::Base directions2;
public:
    enum InternalPortId
    {
        internalport_directions2,
        internalport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
    Test::Base test;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_directions,
        port_directions2,
        port_log,
        port_test
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
private:
    int startR;
public:
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        CoordinateCalculater,
        Exited,
        Testing,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[5];
    State currentState;
    void update_state( State newState );
    void entryaction_____CoordinateCalculater( const UMLRTMessage * msg );
    void entryaction_____Exited( const UMLRTMessage * msg );
    void entryaction_____Testing( const UMLRTMessage * msg );
    void transitionaction_____Initial( const UMLRTMessage * msg );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void transitionaction_____transition2( const UMLRTMessage * msg );
    void transitionaction_____transition3( const UMLRTMessage * msg );
    void transitionaction_____transition4( const UMLRTMessage * msg );
    void transitionaction_____transition5( const UMLRTMessage * msg );
    void transitionaction_____transition6( const UMLRTMessage * msg );
    bool guard_____transition5( const UMLRTMessage * msg );
    bool guard_____transition6( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    void actionchain_____transition3( const UMLRTMessage * msg );
    void actionchain_____transition4( const UMLRTMessage * msg );
    void actionchain_____transition5( const UMLRTMessage * msg );
    void actionchain_____transition6( const UMLRTMessage * msg );
    State choice_____subvertex4( const UMLRTMessage * msg );
    State state_____CoordinateCalculater( const UMLRTMessage * msg );
    State state_____Exited( const UMLRTMessage * msg );
    State state_____Testing( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Calculation;

#endif

