
#ifndef ZOMBIEBEHAVIOR_HH
#define ZOMBIEBEHAVIOR_HH

#include "Directions.hh"
#include "Status.hh"
#include "Vector.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
#include "umlrttimerprotocol.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_ZombieBehavior : public UMLRTCapsule
{
public:
    Capsule_ZombieBehavior( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    Directions::Conj directions;
public:
    enum BorderPortId
    {
        borderport_directions,
        borderport_test
    };
protected:
    UMLRTLogProtocol_baserole log;
    Status::Conj test;
    UMLRTTimerProtocol_baserole timing;
public:
    enum InternalPortId
    {
        internalport_timing,
        internalport_log
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_directions,
        port_log,
        port_test,
        port_timing
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
private:
    Vector zombieVector;
    int delay;
    int maxZombie;
    int index;
    int x;
    int y;
    bool notFirstZombie;
public:
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        Recieved,
        Start,
        Waiting,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[5];
    State currentState;
    void update_state( State newState );
    void entryaction_____Recieved( const UMLRTMessage * msg );
    void entryaction_____Start( const UMLRTMessage * msg );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void transitionaction_____transition2( const UMLRTMessage * msg );
    void transitionaction_____transition3( const UMLRTMessage * msg );
    void transitionaction_____transition4( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    void actionchain_____transition3( const UMLRTMessage * msg );
    void actionchain_____transition4( const UMLRTMessage * msg );
    State state_____Recieved( const UMLRTMessage * msg );
    State state_____Start( const UMLRTMessage * msg );
    State state_____Waiting( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass ZombieBehavior;

#endif

