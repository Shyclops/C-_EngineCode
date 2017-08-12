
#ifndef DETECTION_HH
#define DETECTION_HH

#include "Directions.hh"
#include "Status.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
#include "umlrttimerprotocol.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Detection : public UMLRTCapsule
{
public:
    Capsule_Detection( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    Directions::Conj directions;
public:
    enum BorderPortId
    {
        borderport_directions
    };
protected:
    UMLRTLogProtocol_baserole log;
    Status::Base test;
public:
    enum InternalPortId
    {
        internalport_test,
        internalport_timing,
        internalport_log
    };
protected:
    UMLRTTimerProtocol_baserole timing;
public:
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
    int ESC_KEY;
    int delay;
public:
    bool flag;
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        Playing,
        Waiting,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[4];
    State currentState;
    void update_state( State newState );
    void entryaction_____Playing( const UMLRTMessage * msg );
    void entryaction_____Waiting( const UMLRTMessage * msg );
    void transitionaction_____Initial( const UMLRTMessage * msg );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void transitionaction_____transition2( const UMLRTMessage * msg );
    bool guard_____transition1( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    State state_____Playing( const UMLRTMessage * msg );
    State state_____Waiting( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Detection;

#endif

