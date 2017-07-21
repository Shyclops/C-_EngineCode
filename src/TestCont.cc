
#include "TestCont.hh"

#include "Directions.hh"
#include "Test.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtframeservice.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_TestCont::Capsule_TestCont( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( borderPorts[borderport_directions] )
, directions2( borderPorts[borderport_directions2] )
, directions3( internalPorts[internalport_directions3] )
, observation( internalPorts[internalport_observation] )
, test( internalPorts[internalport_test] )
, x( 0 )
, y( 0 )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[Finished] = "Finished";
    stateNames[Playing] = "Playing";
    stateNames[Waiting] = "Waiting";
    stateNames[checkingDirection] = "checkingDirection";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}











void Capsule_TestCont::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_directions:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions, index, true );
            break;
        case borderport_directions2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions2, index, true );
            break;
        }
}

void Capsule_TestCont::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_directions:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_directions], index );
            break;
        case borderport_directions2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions2, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_directions2], index );
            break;
        }
}



void Capsule_TestCont::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Waiting:
        currentState = state_____Waiting( &message );
        break;
    case Playing:
        currentState = state_____Playing( &message );
        break;
    case Finished:
        currentState = state_____Finished( &message );
        break;
    case checkingDirection:
        currentState = state_____checkingDirection( &message );
        break;
    default:
        break;
    }
}

void Capsule_TestCont::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = Waiting;
}

const char * Capsule_TestCont::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_TestCont::update_state( Capsule_TestCont::State newState )
{
    currentState = newState;
}

void Capsule_TestCont::entryaction_____Finished( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont::Finished entry  */
    log.log("Game Exited");
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_TestCont::entryaction_____Playing( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont::Playing entry  */
    log.log("X: %d, Y: %d", x, y);
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_TestCont::entryaction_____Waiting( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont::Waiting entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_TestCont::transitionaction_____Initial( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont transition subvertex0,Waiting */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_TestCont::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define Direction ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont transition Playing,checkingDirection,directions:directions */
    directions2.directionsCalc(x,y,Direction).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Direction
}

void Capsule_TestCont::transitionaction_____transition2( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont transition Playing,Finished,exits:directions */
    directions3.exit().send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_TestCont::transitionaction_____transition3( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont transition Waiting,Playing,isReadyIn:test */
    x = X;
    y = Y;
    Event e1;
    e1.setSourceName(this->getName());
    e1.setParam("x", x);
    e1.setParam("y", y);
    observation.event(e1).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_TestCont::transitionaction_____transition4( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::TestCont transition checkingDirection,Playing,directionCalc:directions2 */
    x = X;
    y = Y;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_TestCont::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( Waiting );
    entryaction_____Waiting( msg );
}

void Capsule_TestCont::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( checkingDirection );
}

void Capsule_TestCont::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition2( msg );
    update_state( Finished );
    entryaction_____Finished( msg );
}

void Capsule_TestCont::actionchain_____transition3( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition3( msg );
    update_state( Playing );
    entryaction_____Playing( msg );
}

void Capsule_TestCont::actionchain_____transition4( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition4( msg );
    update_state( Playing );
    entryaction_____Playing( msg );
}

Capsule_TestCont::State Capsule_TestCont::state_____Finished( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_TestCont::State Capsule_TestCont::state_____Playing( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_directions:
        switch( msg->getSignalId() )
        {
        case Directions::signal_directions:
            actionchain_____transition1( msg );
            return checkingDirection;
        case Directions::signal_exits:
            actionchain_____transition2( msg );
            return Finished;
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

Capsule_TestCont::State Capsule_TestCont::state_____Waiting( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_test:
        switch( msg->getSignalId() )
        {
        case Test::signal_isReadyIn:
            actionchain_____transition3( msg );
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

Capsule_TestCont::State Capsule_TestCont::state_____checkingDirection( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_directions2:
        switch( msg->getSignalId() )
        {
        case Directions::signal_directionCalc:
            actionchain_____transition4( msg );
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
        Capsule_TestCont::port_directions,
        "Directions",
        "directions",
        "",
        1,
        true,
        false,
        false,
        false,
        false,
        false,
        true
    },
    {
        Capsule_TestCont::port_directions2,
        "Directions",
        "directions2",
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
        Capsule_TestCont::port_directions3,
        "Directions",
        "directions3",
        "",
        2,
        true,
        false,
        false,
        false,
        false,
        true,
        false
    },
    {
        Capsule_TestCont::port_observation,
        "Observation",
        "observation",
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
        Capsule_TestCont::port_test,
        "Test",
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
        Capsule_TestCont::port_log,
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

static void instantiate_TestCont( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &TestCont );
    slot->capsule = new Capsule_TestCont( &TestCont, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass TestCont = 
{
    "TestCont",
    NULL,
    instantiate_TestCont,
    0,
    NULL,
    2,
    portroles_border,
    4,
    portroles_internal
};

