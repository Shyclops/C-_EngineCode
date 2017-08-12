
#include "PreExecute.hh"

#include "Directions.hh"
#include "Status.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtframeservice.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_PreExecute::Capsule_PreExecute( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( internalPorts[internalport_directions] )
, test( internalPorts[internalport_test] )
, test2( borderPorts[borderport_test2] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[Exited] = "Exited";
    stateNames[Found] = "Found";
    stateNames[Waiting] = "Waiting";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}









void Capsule_PreExecute::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_test2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test2, index, true );
            break;
        }
}

void Capsule_PreExecute::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_test2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test2, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_test2], index );
            break;
        }
}

void Capsule_PreExecute::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Waiting:
        currentState = state_____Waiting( &message );
        break;
    case Found:
        currentState = state_____Found( &message );
        break;
    case Exited:
        currentState = state_____Exited( &message );
        break;
    default:
        break;
    }
}

void Capsule_PreExecute::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = Waiting;
}

const char * Capsule_PreExecute::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_PreExecute::update_state( Capsule_PreExecute::State newState )
{
    currentState = newState;
}

void Capsule_PreExecute::entryaction_____Exited( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute::Exited entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::entryaction_____Found( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute::Found entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_PreExecute::entryaction_____Waiting( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute::Waiting entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::exitaction_____Waiting( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute::Waiting exit  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_PreExecute::transitionaction_____Initial( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition subvertex0,Waiting */
    test2.isStartIn().send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition Found,Exited,exit:directions */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::transitionaction_____transition2( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition Waiting,Found,isStartOut:test2 */
    log.log("Pre-execution done");
    test.isReadyIn(X,Y).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_PreExecute::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( Waiting );
    entryaction_____Waiting( msg );
}

void Capsule_PreExecute::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( Exited );
    entryaction_____Exited( msg );
}

void Capsule_PreExecute::actionchain_____transition2( const UMLRTMessage * msg )
{
    exitaction_____Waiting( msg );
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition2( msg );
    update_state( Found );
    entryaction_____Found( msg );
}

Capsule_PreExecute::State Capsule_PreExecute::state_____Exited( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_PreExecute::State Capsule_PreExecute::state_____Found( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_directions:
        switch( msg->getSignalId() )
        {
        case Directions::signal_exit:
            actionchain_____transition1( msg );
            return Exited;
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

Capsule_PreExecute::State Capsule_PreExecute::state_____Waiting( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_test2:
        switch( msg->getSignalId() )
        {
        case Status::signal_isStartOut:
            actionchain_____transition2( msg );
            return Found;
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
        Capsule_PreExecute::port_test2,
        "Status",
        "test2",
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
        Capsule_PreExecute::port_directions,
        "Directions",
        "directions",
        "",
        1,
        true,
        true,
        false,
        false,
        true,
        false,
        false
    },
    {
        Capsule_PreExecute::port_test,
        "Status",
        "test",
        "",
        2,
        true,
        true,
        false,
        false,
        false,
        true,
        false
    },
    {
        Capsule_PreExecute::port_log,
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

static void instantiate_PreExecute( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &PreExecute );
    slot->capsule = new Capsule_PreExecute( &PreExecute, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass PreExecute = 
{
    "PreExecute",
    NULL,
    instantiate_PreExecute,
    0,
    NULL,
    1,
    portroles_border,
    3,
    portroles_internal
};

