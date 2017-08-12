
#include "Calculation.hh"

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

#include "Zombie.hh"
#include "external_resources/opencv/sources/modules/core/include/opencv2/core.hpp"
#include "external_resources/opencv/sources/modules/highgui/include/opencv2/highgui.hpp"
#include "external_resources/opencv/sources/modules/imgcodecs/include/opencv2/imgcodecs.hpp"
#include "external_resources/opencv/sources/modules/imgproc/include/opencv2/imgproc.hpp"
using namespace cv;

Capsule_Calculation::Capsule_Calculation( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( borderPorts[borderport_directions] )
, directions2( borderPorts[borderport_directions2] )
, directions3( internalPorts[internalport_directions3] )
, observation( internalPorts[internalport_observation] )
, test( borderPorts[borderport_test] )
, test2( borderPorts[borderport_test2] )
, startR( 85 )
, emptyR( 255 )
, zombieR( 170 )
, x( 0 )
, y( 0 )
, zombies( -1 )
, startDirection( 0 )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[CoordinateCalculater] = "CoordinateCalculater";
    stateNames[Exited] = "Exited";
    stateNames[Waiting] = "Waiting";
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
        case borderport_directions2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions2, index, true );
            break;
        case borderport_test:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test, index, true );
            break;
        case borderport_test2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test2, index, true );
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
        case borderport_directions2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_directions2, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_directions2], index );
            break;
        case borderport_test:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_test], index );
            break;
        case borderport_test2:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_test2, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_test2], index );
            break;
        }
}












void Capsule_Calculation::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Waiting:
        currentState = state_____Waiting( &message );
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
    currentState = Waiting;
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
    #define rtdata ( (void *)msg->getParam( 0 ) )
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

void Capsule_Calculation::entryaction_____Waiting( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation::Waiting entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____Initial( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition subvertex0,Waiting */
    map = imread("external_resources/map.png");
    width = map.size().width;
    height = map.size().height;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____found( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition subvertex4,CoordinateCalculater */
    VectorWrapper wrapper;
    wrapper.zombieVectorWrapper = zombieVector;

    test2.zombieOut(wrapper, zombies).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____notFound( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition subvertex4,subvertex4 */
    if (x != width){
    x++;
    } else {
    if (y != height){
    y++;
    x = 0;
    }else{
    log.log("FAILURE");
    while(true){};
    }}
    Vec3b intensity = map.at<Vec3b>(y, x);
    if  (intensity.val[2] == startR){
    test.isStartOut(x,y).send();
    } else if (intensity.val[2]==zombieR){
    Zombie tempZombie;
    tempZombie.move(x,y);
    tempZombie.changeDirection(startDirection);
    zombieVector.addZVector(tempZombie);
    zombies++;
    }
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::transitionaction_____transition2( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define Direction ( *(int *)msg->getParam( 2 ) )
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition CoordinateCalculater,CoordinateCalculater,directionsCalc:directions/directionsCalc:directions2 */
    //0 = up
    //1 = down
    //2 = left
    //3 = right
    if (Direction==0){
    x = X;
    y = Y-1;
    } else if (Direction==1){
    x = X;
    y = Y+1;
    } else if (Direction==2){
    x = X-1;
    y = Y;
    } else if (Direction==3){
    x = X+1;
    y = Y;
    }
    Vec3b intensity = map.at<Vec3b>(y, x);
    Vec3b pIntensity = map.at<Vec3b>(Y,X);
    if (intensity.val[2] == emptyR){
    if (pIntensity.val[2] == startR){
    directions.directionCalc(x,y).send();
    intensity.val[2]=startR;
    } else if (pIntensity.val[2] == zombieR){
    directions2.directionCalc(x,y).send();
    intensity.val[2]=zombieR;
    }
    map.at<Vec3b>(y,x) = intensity;
    pIntensity.val[2]=emptyR;
    map.at<Vec3b>(Y,X) = pIntensity;
    std::vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    imwrite("external_resources/map.png", map, compression_params);
    } else if (intensity.val[2]== zombieR){
    directions2.exit().send();
    }else {
    if (pIntensity.val[2] == startR){
    directions.directionCalc(X,Y).send();
    intensity.val[2]=startR;
    } else if (pIntensity.val[2] == zombieR){
    directions2.directionCalc(X,Y).send();
    intensity.val[2]=zombieR;
    }
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
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition Waiting,subvertex4,isStartIn:test */
    Vec3b intensity = map.at<Vec3b>(y, x);
    if  (intensity.val[2] == startR){
    test.isStartOut(x,y).send();
    } else if (intensity.val[2]==zombieR){
    Zombie tempZombie;
    tempZombie.move(x,y);
    tempZombie.changeDirection(startDirection);
    zombieVector.addZVector(tempZombie);
    }
    width = map.size().width;
    height = map.size().height;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

bool Capsule_Calculation::guard_____found( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation guard subvertex4,CoordinateCalculater */
    return y==height;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

bool Capsule_Calculation::guard_____notFound( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation guard subvertex4,subvertex4 */
    return (y!=height);
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Calculation::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( Waiting );
    entryaction_____Waiting( msg );
    std::stringstream ss;
    ss << this->slot->containerClass->name;
    ss << ".";
    ss << this->getName();
    ss << ":";
    ss << this->getIndex();
    EventObj eobj1;
    Event e1;
    e1.setSourceName("subvertex0");
    e1.setCapsuleInstance(ss.str().c_str());
    e1.setTimestamp();
    e1.setEventSource(Event::State);
    e1.setEventKind(Event::StateExitEnd);
    e1.setParam("capsuleName", "Calculation");
    eobj1.event = e1;
    observation.event(eobj1).send();
    EventObj eobj2;
    Event e2;
    e2.setSourceName("Waiting");
    e2.setCapsuleInstance(ss.str().c_str());
    e2.setTimestamp();
    e2.setEventSource(Event::State);
    e2.setEventKind(Event::StateEntryStart);
    e2.setParam("capsuleName", "Calculation");
    eobj2.event = e2;
    observation.event(eobj2).send();
}

void Capsule_Calculation::actionchain_____found( const UMLRTMessage * msg )
{
    transitionaction_____found( msg );
    update_state( CoordinateCalculater );
    entryaction_____CoordinateCalculater( msg );
    std::stringstream ss;
    ss << this->slot->containerClass->name;
    ss << ".";
    ss << this->getName();
    ss << ":";
    ss << this->getIndex();
    EventObj eobj1;
    Event e1;
    e1.setSourceName("subvertex4");
    e1.setCapsuleInstance(ss.str().c_str());
    e1.setTimestamp();
    e1.setEventSource(Event::State);
    e1.setEventKind(Event::StateExitEnd);
    e1.setParam("capsuleName", "Calculation");
    eobj1.event = e1;
    observation.event(eobj1).send();
    EventObj eobj2;
    Event e2;
    e2.setSourceName("CoordinateCalculater");
    e2.setCapsuleInstance(ss.str().c_str());
    e2.setTimestamp();
    e2.setEventSource(Event::State);
    e2.setEventKind(Event::StateEntryStart);
    e2.setParam("capsuleName", "Calculation");
    eobj2.event = e2;
    observation.event(eobj2).send();
}

void Capsule_Calculation::actionchain_____notFound( const UMLRTMessage * msg )
{
    transitionaction_____notFound( msg );
    std::stringstream ss;
    ss << this->slot->containerClass->name;
    ss << ".";
    ss << this->getName();
    ss << ":";
    ss << this->getIndex();
    EventObj eobj1;
    Event e1;
    e1.setSourceName("subvertex4");
    e1.setCapsuleInstance(ss.str().c_str());
    e1.setTimestamp();
    e1.setEventSource(Event::State);
    e1.setEventKind(Event::StateExitEnd);
    e1.setParam("capsuleName", "Calculation");
    eobj1.event = e1;
    observation.event(eobj1).send();
    EventObj eobj2;
    Event e2;
    e2.setSourceName("subvertex4");
    e2.setCapsuleInstance(ss.str().c_str());
    e2.setTimestamp();
    e2.setEventSource(Event::State);
    e2.setEventKind(Event::StateEntryStart);
    e2.setParam("capsuleName", "Calculation");
    eobj2.event = e2;
    observation.event(eobj2).send();
}

void Capsule_Calculation::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( Exited );
    entryaction_____Exited( msg );
    std::stringstream ss;
    ss << this->slot->containerClass->name;
    ss << ".";
    ss << this->getName();
    ss << ":";
    ss << this->getIndex();
    EventObj eobj1;
    Event e1;
    e1.setSourceName("Waiting");
    e1.setCapsuleInstance(ss.str().c_str());
    e1.setTimestamp();
    e1.setEventSource(Event::State);
    e1.setEventKind(Event::StateExitEnd);
    e1.setParam("capsuleName", "Calculation");
    eobj1.event = e1;
    observation.event(eobj1).send();
    EventObj eobj2;
    Event e2;
    e2.setSourceName("Exited");
    e2.setCapsuleInstance(ss.str().c_str());
    e2.setTimestamp();
    e2.setEventSource(Event::State);
    e2.setEventKind(Event::StateEntryStart);
    e2.setParam("capsuleName", "Calculation");
    eobj2.event = e2;
    observation.event(eobj2).send();
}

void Capsule_Calculation::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition2( msg );
    update_state( CoordinateCalculater );
    entryaction_____CoordinateCalculater( msg );
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define Direction ( *(int *)msg->getParam( 2 ) )
    std::stringstream ss;
    ss << this->slot->containerClass->name;
    ss << ".";
    ss << this->getName();
    ss << ":";
    ss << this->getIndex();
    EventObj eobj1;
    Event e1;
    e1.setSourceName("CoordinateCalculater");
    e1.setCapsuleInstance(ss.str().c_str());
    e1.setTimestamp();
    e1.setEventSource(Event::State);
    e1.setEventKind(Event::StateExitEnd);
    e1.setParam("capsuleName", "Calculation");
    e1.setParam("X", X);
    e1.setParam("Y", Y);
    e1.setParam("Direction", Direction);
    eobj1.event = e1;
    observation.event(eobj1).send();
    EventObj eobj2;
    Event e2;
    e2.setSourceName("CoordinateCalculater");
    e2.setCapsuleInstance(ss.str().c_str());
    e2.setTimestamp();
    e2.setEventSource(Event::State);
    e2.setEventKind(Event::StateEntryStart);
    e2.setParam("capsuleName", "Calculation");
    e2.setParam("X", X);
    e2.setParam("Y", Y);
    e2.setParam("Direction", Direction);
    eobj2.event = e2;
    observation.event(eobj2).send();
    #undef X
    #undef Y
    #undef Direction
}

void Capsule_Calculation::actionchain_____transition3( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition3( msg );
    std::stringstream ss;
    ss << this->slot->containerClass->name;
    ss << ".";
    ss << this->getName();
    ss << ":";
    ss << this->getIndex();
    EventObj eobj1;
    Event e1;
    e1.setSourceName("Waiting");
    e1.setCapsuleInstance(ss.str().c_str());
    e1.setTimestamp();
    e1.setEventSource(Event::State);
    e1.setEventKind(Event::StateExitEnd);
    e1.setParam("capsuleName", "Calculation");
    eobj1.event = e1;
    observation.event(eobj1).send();
    EventObj eobj2;
    Event e2;
    e2.setSourceName("subvertex4");
    e2.setCapsuleInstance(ss.str().c_str());
    e2.setTimestamp();
    e2.setEventSource(Event::State);
    e2.setEventKind(Event::StateEntryStart);
    e2.setParam("capsuleName", "Calculation");
    eobj2.event = e2;
    observation.event(eobj2).send();
}

void Capsule_Calculation::actionchain_____transition6( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( Exited );
    entryaction_____Exited( msg );
    std::stringstream ss;
    ss << this->slot->containerClass->name;
    ss << ".";
    ss << this->getName();
    ss << ":";
    ss << this->getIndex();
    EventObj eobj1;
    Event e1;
    e1.setSourceName("CoordinateCalculater");
    e1.setCapsuleInstance(ss.str().c_str());
    e1.setTimestamp();
    e1.setEventSource(Event::State);
    e1.setEventKind(Event::StateExitEnd);
    e1.setParam("capsuleName", "Calculation");
    eobj1.event = e1;
    observation.event(eobj1).send();
    EventObj eobj2;
    Event e2;
    e2.setSourceName("Exited");
    e2.setCapsuleInstance(ss.str().c_str());
    e2.setTimestamp();
    e2.setEventSource(Event::State);
    e2.setEventKind(Event::StateEntryStart);
    e2.setParam("capsuleName", "Calculation");
    eobj2.event = e2;
    observation.event(eobj2).send();
}

Capsule_Calculation::State Capsule_Calculation::choice_____subvertex4( const UMLRTMessage * msg )
{
    if( guard_____found( msg ) )
    {
        actionchain_____found( msg );
        return CoordinateCalculater;
    }
    else if( guard_____notFound( msg ) )
    {
        actionchain_____notFound( msg );
        return choice_____subvertex4( msg );
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
        case Directions::signal_directionsCalc:
            actionchain_____transition2( msg );
            return CoordinateCalculater;
            actionchain_____transition2( msg );
            return CoordinateCalculater;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    case port_directions3:
        switch( msg->getSignalId() )
        {
        case Directions::signal_exit:
            actionchain_____transition6( msg );
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

Capsule_Calculation::State Capsule_Calculation::state_____Waiting( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_directions3:
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
    case port_test:
        switch( msg->getSignalId() )
        {
        case Status::signal_isStartIn:
            actionchain_____transition3( msg );
            return choice_____subvertex4( msg );
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
        Capsule_Calculation::port_directions2,
        "Directions",
        "directions2",
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
        "Status",
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
    },
    {
        Capsule_Calculation::port_test2,
        "Status",
        "test2",
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
        Capsule_Calculation::port_directions3,
        "Directions",
        "directions3",
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
        Capsule_Calculation::port_observation,
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
    4,
    portroles_border,
    3,
    portroles_internal
};

