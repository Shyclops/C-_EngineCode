
#ifndef OBSERVER_HH
#define OBSERVER_HH

#include "Observation.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
#include "umlrttimerprotocol.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

#include "Method.hh"
#include "Socket.hh"
#include "Serializer.hh"
#include "Text.hh"
#include "CLIUtils.hh"
#include "Config.hh"

class Capsule_Observer : public UMLRTCapsule
{
public:
    Capsule_Observer( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    UMLRTLogProtocol_baserole log;
    Observation::Conj observation;
public:
    enum InternalPortId
    {
        internalport_observation,
        internalport_timer,
        internalport_log
    };
protected:
    UMLRTTimerProtocol_baserole timer;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_log,
        port_observation,
        port_timer
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
private:
    Method* method;
    Serializer* serializer;
    std::map<std::string, size_t> capsules;
    std::map<std::string, std::string> capsuleTypes;
    Config config;

public:
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        OBSERVING,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[3];
    State currentState;
    void update_state( State newState );
    void transitionaction_____command_received( const UMLRTMessage * msg );
    void transitionaction_____configure( const UMLRTMessage * msg );
    void transitionaction_____event_received( const UMLRTMessage * msg );
    void transitionaction_____register_capsules( const UMLRTMessage * msg );
    void actionchain_____command_received( const UMLRTMessage * msg );
    void actionchain_____configure( const UMLRTMessage * msg );
    void actionchain_____event_received( const UMLRTMessage * msg );
    void actionchain_____register_capsules( const UMLRTMessage * msg );
    State state_____OBSERVING( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Observer;

#endif

