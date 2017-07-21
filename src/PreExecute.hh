
#ifndef PREEXECUTE_HH
#define PREEXECUTE_HH

#include "Directions.hh"
#include "Observation.hh"
#include "Test.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_PreExecute : public UMLRTCapsule
{
public:
    Capsule_PreExecute( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    Directions::Conj directions;
public:
    enum InternalPortId
    {
        internalport_directions,
        internalport_observation,
        internalport_test,
        internalport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
    Observation::Base observation;
    Test::Conj test;
    Test::Conj test2;
public:
    enum BorderPortId
    {
        borderport_test2
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_directions,
        port_log,
        port_observation,
        port_test,
        port_test2
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        Exited,
        Found,
        Waiting,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[5];
    State currentState;
    void update_state( State newState );
    void entryaction_____Exited( const UMLRTMessage * msg );
    void entryaction_____Found( const UMLRTMessage * msg );
    void entryaction_____Waiting( const UMLRTMessage * msg );
    void exitaction_____Waiting( const UMLRTMessage * msg );
    void transitionaction_____Initial( const UMLRTMessage * msg );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void transitionaction_____transition2( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    State state_____Exited( const UMLRTMessage * msg );
    State state_____Found( const UMLRTMessage * msg );
    State state_____Waiting( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass PreExecute;

#endif

