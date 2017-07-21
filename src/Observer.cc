
#include "Observer.hh"

#include "Observation.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include "umlrttimerprotocol.hh"
#include <cstddef>
#include "Event.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_Observer::Capsule_Observer( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, observation( internalPorts[internalport_observation] )
, timer( internalPorts[internalport_timer] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[OBSERVING] = "OBSERVING";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}







void Capsule_Observer::bindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Observer::unbindPort( bool isBorder, int portId, int index )
{
}



void Capsule_Observer::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case OBSERVING:
        currentState = state_____OBSERVING( &message );
        break;
    default:
        break;
    }
}

void Capsule_Observer::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____configure( &message );
    currentState = OBSERVING;
}

const char * Capsule_Observer::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Observer::update_state( Capsule_Observer::State newState )
{
    currentState = newState;
}

void Capsule_Observer::transitionaction_____configure( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Observation::Observer transition subvertex0,OBSERVING */
    config.load();
    // Socket
    this->method = new ClientSocket();
    this->method->configure(config.getConfigList());
    this->method->establishConnection();
    // Text 
    this->serializer = new Text();
    this->serializer->configure(config.getConfigList());
    // Instantiating the timer
    timer.informEvery(UMLRTTimespec(0,500000000));
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Observer::transitionaction_____read( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Observation::Observer transition OBSERVING,OBSERVING,timeout:timer */
    this->method->read();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Observer::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define data ( *(const Event * )msg->getParam( 0 ) )
    #define rtdata ( (const Event * )msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Observation::Observer transition OBSERVING,OBSERVING,event:observation */
    std::string str = this->serializer->serialize(data) + "\n";
    this->method->sendData(str);
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef data
}

void Capsule_Observer::actionchain_____configure( const UMLRTMessage * msg )
{
    transitionaction_____configure( msg );
    update_state( OBSERVING );
}

void Capsule_Observer::actionchain_____read( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____read( msg );
    update_state( OBSERVING );
}

void Capsule_Observer::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( OBSERVING );
}

Capsule_Observer::State Capsule_Observer::state_____OBSERVING( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_observation:
        switch( msg->getSignalId() )
        {
        case Observation::signal_event:
            actionchain_____transition1( msg );
            return OBSERVING;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    case port_timer:
        switch( msg->getSignalId() )
        {
        case UMLRTTimerProtocol::signal_timeout:
            actionchain_____read( msg );
            return OBSERVING;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}


static const UMLRTCommsPortRole portroles_internal[] = 
{
    {
        Capsule_Observer::port_observation,
        "Observation",
        "observation",
        "",
        20,
        true,
        true,
        false,
        false,
        false,
        true,
        false
    },
    {
        Capsule_Observer::port_timer,
        "Timing",
        "timer",
        "",
        0,
        false,
        false,
        false,
        false,
        true,
        false,
        false
    },
    {
        Capsule_Observer::port_log,
        "Log",
        "log",
        "",
        0,
        false,
        false,
        false,
        false,
        true,
        false,
        false
    }
};

static void instantiate_Observer( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &Observer );
    slot->capsule = new Capsule_Observer( &Observer, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass Observer = 
{
    "Observer",
    NULL,
    instantiate_Observer,
    0,
    NULL,
    0,
    NULL,
    3,
    portroles_internal
};

