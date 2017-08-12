
#include "ZombieBehavior.hh"

#include "Directions.hh"
#include "Status.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include "umlrttimerprotocol.hh"
#include <cstddef>
#include "VectorWrapper.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

#include <iostream>

Capsule_ZombieBehavior::Capsule_ZombieBehavior( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( borderPorts[borderport_directions] )
, test( borderPorts[borderport_test] )
, timing( internalPorts[internalport_timing] )
, delay( 1 )
, notFirstZombie( false )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[Recieved] = "Recieved";
    stateNames[Start] = "Start";
    stateNames[Waiting] = "Waiting";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}









void Capsule_ZombieBehavior::bindPort( bool isBorder, int portId, int index )
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

void Capsule_ZombieBehavior::unbindPort( bool isBorder, int portId, int index )
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








void Capsule_ZombieBehavior::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Waiting:
        currentState = state_____Waiting( &message );
        break;
    case Recieved:
        currentState = state_____Recieved( &message );
        break;
    case Start:
        currentState = state_____Start( &message );
        break;
    default:
        break;
    }
}

void Capsule_ZombieBehavior::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = Waiting;
}

const char * Capsule_ZombieBehavior::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_ZombieBehavior::update_state( Capsule_ZombieBehavior::State newState )
{
    currentState = newState;
}

void Capsule_ZombieBehavior::entryaction_____Recieved( const UMLRTMessage * msg )
{
    #define data ( *(const VectorWrapper * )msg->getParam( 0 ) )
    #define max ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (const VectorWrapper * )msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::ZombieBehavior::Recieved entry  */
    if (notFirstZombie){
    Zombie tempZombie = zombieVector.getZombie(index);
    if (x ==  tempZombie.getX() && y == tempZombie.getY()){
    switch(tempZombie.currentDirection()){
    case 0: 
    tempZombie.changeDirection(1);
    break;
    case 1: 
    tempZombie.changeDirection(0);
    break;
    case 2: 
    tempZombie.changeDirection(3);
    break;
    case 3: 
    tempZombie.changeDirection(2);
    break;
    }
    zombieVector.zVector.at(index) = tempZombie;
    }
    index = index + 1;
    if (index <= maxZombie){
    x = zombieVector.getZombie(index).getX();
    y = zombieVector.getZombie(index).getY();
    directions.directionsCalc(x, y, zombieVector.getZombie(index).currentDirection()).send();
    }
    }
    if (index > maxZombie){
    index = 0;
    notFirstZombie = false;
    timing.informIn(UMLRTTimespec(this->delay,0));
    }
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef max
    #undef data
}

void Capsule_ZombieBehavior::entryaction_____Start( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::ZombieBehavior::Start entry  */
    x = zombieVector.getZombie(index).getX();
    y = zombieVector.getZombie(index).getY();
    directions.directionsCalc(x, y, zombieVector.getZombie(index).currentDirection()).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ZombieBehavior::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define data ( *(const VectorWrapper * )msg->getParam( 0 ) )
    #define max ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (const VectorWrapper * )msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::ZombieBehavior transition Waiting,Recieved,zombieOut:test */
    zombieVector = data.zombieVectorWrapper;
    maxZombie = max;
    index = max+1;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef max
    #undef data
}

void Capsule_ZombieBehavior::transitionaction_____transition2( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::ZombieBehavior transition Recieved,Start,timeout:timing */
    notFirstZombie = true;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ZombieBehavior::transitionaction_____transition3( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::ZombieBehavior transition Start,Recieved,directionCalc:directions */
    Zombie tempZombie = zombieVector.getZombie(index);
    tempZombie.move(X,Y);
    zombieVector.zVector.at(index) = tempZombie;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_ZombieBehavior::transitionaction_____transition4( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::ZombieBehavior transition Recieved,Recieved,directionCalc:directions */
    Zombie tempZombie = zombieVector.getZombie(index);
    tempZombie.move(X,Y);
    zombieVector.zVector.at(index) = tempZombie;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_ZombieBehavior::actionchain_____Initial( const UMLRTMessage * msg )
{
    update_state( Waiting );
}

void Capsule_ZombieBehavior::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( Recieved );
    entryaction_____Recieved( msg );
}

void Capsule_ZombieBehavior::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition2( msg );
    update_state( Start );
    entryaction_____Start( msg );
}

void Capsule_ZombieBehavior::actionchain_____transition3( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition3( msg );
    update_state( Recieved );
    entryaction_____Recieved( msg );
}

void Capsule_ZombieBehavior::actionchain_____transition4( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition4( msg );
    update_state( Recieved );
    entryaction_____Recieved( msg );
}

Capsule_ZombieBehavior::State Capsule_ZombieBehavior::state_____Recieved( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_timing:
        switch( msg->getSignalId() )
        {
        case UMLRTTimerProtocol::signal_timeout:
            actionchain_____transition2( msg );
            return Start;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    case port_directions:
        switch( msg->getSignalId() )
        {
        case Directions::signal_directionCalc:
            actionchain_____transition4( msg );
            return Recieved;
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

Capsule_ZombieBehavior::State Capsule_ZombieBehavior::state_____Start( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_directions:
        switch( msg->getSignalId() )
        {
        case Directions::signal_directionCalc:
            actionchain_____transition3( msg );
            return Recieved;
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

Capsule_ZombieBehavior::State Capsule_ZombieBehavior::state_____Waiting( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_test:
        switch( msg->getSignalId() )
        {
        case Status::signal_zombieOut:
            actionchain_____transition1( msg );
            return Recieved;
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
        Capsule_ZombieBehavior::port_directions,
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
    },
    {
        Capsule_ZombieBehavior::port_test,
        "Status",
        "test",
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
        Capsule_ZombieBehavior::port_timing,
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
        Capsule_ZombieBehavior::port_log,
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

static void instantiate_ZombieBehavior( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &ZombieBehavior );
    slot->capsule = new Capsule_ZombieBehavior( &ZombieBehavior, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass ZombieBehavior = 
{
    "ZombieBehavior",
    NULL,
    instantiate_ZombieBehavior,
    0,
    NULL,
    2,
    portroles_border,
    2,
    portroles_internal
};

