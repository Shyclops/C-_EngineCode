
#include "Detection.hh"

#include "Status.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include "umlrttimerprotocol.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

#include <stdio.h>
#include <iostream>
using namespace std;

Capsule_Detection::Capsule_Detection( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( borderPorts[borderport_directions] )
, test( internalPorts[internalport_test] )
, timing( internalPorts[internalport_timing] )
, ESC_KEY( 27 )
, delay( 1 )
, flag( true )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[Playing] = "Playing";
    stateNames[Waiting] = "Waiting";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}









void Capsule_Detection::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_directions:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions, index, true );
            break;
        }
}

void Capsule_Detection::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_directions:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_directions], index );
            break;
        }
}




void Capsule_Detection::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Playing:
        currentState = state_____Playing( &message );
        break;
    case Waiting:
        currentState = state_____Waiting( &message );
        break;
    default:
        break;
    }
}

void Capsule_Detection::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = Waiting;
}

const char * Capsule_Detection::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Detection::update_state( Capsule_Detection::State newState )
{
    currentState = newState;
}

void Capsule_Detection::entryaction_____Playing( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Detection::Playing entry  */
    //0 = up
    //1 = down
    //2 = left
    //3 = right
    int c = 0; 
    switch((c=fgetc(stdin))){
    case 119:
    directions.directions(0).send();
    break;
    case 115:
    directions.directions(1).send();
    break;
    case 97:
    directions.directions(2).send();
    break;
    case 100:
    directions.directions(3).send();
    break;
    case 27:
    directions.exits().send();
    log.log("Exiting");
    flag = false;
    break;
    }
    timing.informIn(UMLRTTimespec(this->delay,0));
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Detection::entryaction_____Waiting( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Detection::Waiting entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Detection::transitionaction_____Initial( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Detection transition subvertex0,Waiting */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Detection::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Detection transition Playing,Playing,timeout:timing */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Detection::transitionaction_____transition2( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Detection transition Waiting,Playing,isReadyIn:test */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

bool Capsule_Detection::guard_____transition1( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Detection guard Playing,Playing,timeout:timing */
    return flag;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Detection::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( Waiting );
    entryaction_____Waiting( msg );
}

void Capsule_Detection::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( Playing );
    entryaction_____Playing( msg );
}

void Capsule_Detection::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition2( msg );
    update_state( Playing );
    entryaction_____Playing( msg );
}

Capsule_Detection::State Capsule_Detection::state_____Playing( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_timing:
        switch( msg->getSignalId() )
        {
        case UMLRTTimerProtocol::signal_timeout:
            if( guard_____transition1( msg ) )
            {
                actionchain_____transition1( msg );
                return Playing;
            }
            break;
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

Capsule_Detection::State Capsule_Detection::state_____Waiting( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_test:
        switch( msg->getSignalId() )
        {
        case Status::signal_isReadyIn:
            actionchain_____transition2( msg );
            return Playing;
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


static const UMLRTCommsPortRole portroles_border[] = 
{
    {
        Capsule_Detection::port_directions,
        "Directions",
        "directions",
        "",
        1,
        true,
        true,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPortRole portroles_internal[] = 
{
    {
        Capsule_Detection::port_test,
        "Status",
        "test",
        "",
        1,
        true,
        false,
        false,
        false,
        true,
        false,
        false
    },
    {
        Capsule_Detection::port_timing,
        "Timing",
        "timing",
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
        Capsule_Detection::port_log,
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

static void instantiate_Detection( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &Detection );
    slot->capsule = new Capsule_Detection( &Detection, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass Detection = 
{
    "Detection",
    NULL,
    instantiate_Detection,
    0,
    NULL,
    1,
    portroles_border,
    3,
    portroles_internal
};

