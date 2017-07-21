
#ifndef TESTCONT_HH
#define TESTCONT_HH

#include "Directions.hh"
#include "Observation.hh"
#include "Test.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_TestCont : public UMLRTCapsule
{
public:
    Capsule_TestCont( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    Directions::Base directions;
public:
    enum BorderPortId
    {
        borderport_directions,
        borderport_directions2
    };
protected:
    Directions::Conj directions2;
    Directions::Base directions3;
public:
    enum InternalPortId
    {
        internalport_directions3,
        internalport_observation,
        internalport_test,
        internalport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
    Observation::Base observation;
    Test::Base test;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_directions,
        port_directions2,
        port_directions3,
        port_log,
        port_observation,
        port_test
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
private:
    int x;
    int y;
public:
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        Finished,
        Playing,
        Waiting,
        checkingDirection,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[6];
    State currentState;
    void update_state( State newState );
    void entryaction_____Finished( const UMLRTMessage * msg );
    void entryaction_____Playing( const UMLRTMessage * msg );
    void entryaction_____Waiting( const UMLRTMessage * msg );
    void transitionaction_____Initial( const UMLRTMessage * msg );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void transitionaction_____transition2( const UMLRTMessage * msg );
    void transitionaction_____transition3( const UMLRTMessage * msg );
    void transitionaction_____transition4( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    void actionchain_____transition3( const UMLRTMessage * msg );
    void actionchain_____transition4( const UMLRTMessage * msg );
    State state_____Finished( const UMLRTMessage * msg );
    State state_____Playing( const UMLRTMessage * msg );
    State state_____Waiting( const UMLRTMessage * msg );
    State state_____checkingDirection( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass TestCont;

#endif

