
#include "Calculation.hh"

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

Capsule_Calculation::Capsule_Calculation( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( borderPorts[borderport_directions] )
, directions2( internalPorts[internalport_directions2] )
, test( borderPorts[borderport_test] )
, startR( 127 )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[CoordinateCalculater] = "CoordinateCalculater";
    stateNames[Exited] = "Exited";
    stateNames[Testing] = "Testing";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}









void Capsule_Calculation::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_directions:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions, index, true );
            break;
        case borderport_test:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test, index, true );
            break;
        }
}

void Capsule_Calculation::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_directions:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_directions], index );
            break;
        case borderport_test:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_test], index );
            break;
        }
}


void Capsule_Calculation::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Testing:
        currentState = state_____Testing( &message );
        break;
    case CoordinateCalculater:
        currentState = state_____CoordinateCalculater( &message );
        break;
    case Exited:
        currentState = state_____Exited( &message );
        break;
    default:
        break;
    }
}

void Capsule_Calculation::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = Testing;
}

const char * Capsule_Calculation::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Calculation::update_state( Capsule_Calculation::State newState )
{
    currentState = newState;
}

void Capsule_Calculation::entryaction_____CoordinateCalculater( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define Direction ( *(int *)msg->getParam( 2 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation::CoordinateCalculater entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Direction
    #undef Y
    #undef X
}

void Capsule_Calculation::entryaction_____Exited( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation::Exited entry  */
    log.log("calculation exit");
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::entryaction_____Testing( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation::Testing entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____Initial( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition subvertex0,Testing */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define R ( *(unsigned char *)msg->getParam( 0 ) )
    #define rtdata ( (unsigned char *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition Testing,subvertex4,isStartIn:test */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef R
}

void Capsule_Calculation::transitionaction_____transition2( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define Direction ( *(int *)msg->getParam( 2 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition CoordinateCalculater,CoordinateCalculater,directionsCalc:directions */
    //0 = up
    //1 = down
    //2 = left
    //3 = right
    if (Direction==0){
    directions.directionCalc(X,--Y).send();
    } else if (Direction==1){
    directions.directionCalc(X,++Y).send();
    } else if (Direction==2){
    directions.directionCalc(--X,Y).send();
    } else if (Direction==3){
    directions.directionCalc(++X,Y).send();
    }
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Direction
    #undef Y
    #undef X
}

void Capsule_Calculation::transitionaction_____transition3( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition Testing,Exited,exit:directions2 */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____transition4( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition CoordinateCalculater,Exited,exit:directions2 */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____transition5( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition subvertex4,Testing */
    test.isStartOut(false).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____transition6( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition subvertex4,CoordinateCalculater */
    test.isStartOut(true).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

bool Capsule_Calculation::guard_____transition5( const UMLRTMessage * msg )
{
    #define R ( *(unsigned char *)msg->getParam( 0 ) )
    #define rtdata ( (unsigned char *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation guard subvertex4,Testing */
    if (R != startR){
    return true;
    }
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef R
}

bool Capsule_Calculation::guard_____transition6( const UMLRTMessage * msg )
{
    #define R ( *(unsigned char *)msg->getParam( 0 ) )
    #define rtdata ( (unsigned char *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation guard subvertex4,CoordinateCalculater */
    if (R == startR){
    return true;
    }
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef R
}

void Capsule_Calculation::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( Testing );
    entryaction_____Testing( msg );
}

void Capsule_Calculation::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
}

void Capsule_Calculation::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition2( msg );
    update_state( CoordinateCalculater );
    entryaction_____CoordinateCalculater( msg );
}

void Capsule_Calculation::actionchain_____transition3( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition3( msg );
    update_state( Exited );
    entryaction_____Exited( msg );
}

void Capsule_Calculation::actionchain_____transition4( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition4( msg );
    update_state( Exited );
    entryaction_____Exited( msg );
}

void Capsule_Calculation::actionchain_____transition5( const UMLRTMessage * msg )
{
    transitionaction_____transition5( msg );
    update_state( Testing );
    entryaction_____Testing( msg );
}

void Capsule_Calculation::actionchain_____transition6( const UMLRTMessage * msg )
{
    transitionaction_____transition6( msg );
    update_state( CoordinateCalculater );
    entryaction_____CoordinateCalculater( msg );
}

Capsule_Calculation::State Capsule_Calculation::choice_____subvertex4( const UMLRTMessage * msg )
{
    if( guard_____transition5( msg ) )
    {
        actionchain_____transition5( msg );
        return Testing;
    }
    else if( guard_____transition6( msg ) )
    {
        actionchain_____transition6( msg );
        return CoordinateCalculater;
    }
    return currentState;
}

Capsule_Calculation::State Capsule_Calculation::state_____CoordinateCalculater( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_directions:
        switch( msg->getSignalId() )
        {
        case Directions::signal_directionsCalc:
            actionchain_____transition2( msg );
            return CoordinateCalculater;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    case port_directions2:
        switch( msg->getSignalId() )
        {
        case Directions::signal_exit:
            actionchain_____transition4( msg );
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

Capsule_Calculation::State Capsule_Calculation::state_____Exited( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_Calculation::State Capsule_Calculation::state_____Testing( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_test:
        switch( msg->getSignalId() )
        {
        case Test::signal_isStartIn:
            actionchain_____transition1( msg );
            return choice_____subvertex4( msg );
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    case port_directions2:
        switch( msg->getSignalId() )
        {
        case Directions::signal_exit:
            actionchain_____transition3( msg );
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


static const UMLRTCommsPortRole portroles_border[] = 
{
    {
        Capsule_Calculation::port_directions,
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
        Capsule_Calculation::port_test,
        "Test",
        "test",
        "",
        1,
        true,
        false,
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
        Capsule_Calculation::port_directions2,
        "Directions",
        "directions2",
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
        Capsule_Calculation::port_log,
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

static void instantiate_Calculation( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &Calculation );
    slot->capsule = new Capsule_Calculation( &Calculation, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass Calculation = 
{
    "Calculation",
    NULL,
    instantiate_Calculation,
    0,
    NULL,
    2,
    portroles_border,
    2,
    portroles_internal
};

