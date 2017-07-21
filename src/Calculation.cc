
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

#include "external_resources/opencv/sources/modules/core/include/opencv2/core.hpp"
#include "external_resources/opencv/sources/modules/highgui/include/opencv2/highgui.hpp"
#include "external_resources/opencv/sources/modules/imgcodecs/include/opencv2/imgcodecs.hpp"
#include "external_resources/opencv/sources/modules/imgproc/include/opencv2/imgproc.hpp"
using namespace cv;

Capsule_Calculation::Capsule_Calculation( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( borderPorts[borderport_directions] )
, directions2( internalPorts[internalport_directions2] )
, observation( internalPorts[internalport_observation] )
, test( borderPorts[borderport_test] )
, startR( 127 )
, emptyR( 255 )
, flag( false )
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
    test.isStartOut(x,y).send();
    flag = false;
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
    flag = (intensity.val[2] == startR);
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
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
    if (intensity.val[2] == emptyR){
    log.log("moved");
    directions.directionCalc(x,y).send();
    intensity.val[2]=startR;
    Vec3b pIntensity = map.at<Vec3b>(Y,X);
    pIntensity.val[2]=emptyR;
    Event e1;
    e1.setParam("x", x);
    e1.setParam("y", y);
    e1.setParam("r", intensity.val[2]);
    e1.setParam("g", intensity.val[1]);
    e1.setParam("b", intensity.val[0]);
    observation.event(e1).send();
    Event e2;
    e1.setParam("x", X);
    e1.setParam("y", Y);
    e1.setParam("r", pIntensity.val[2]);
    e1.setParam("g", pIntensity.val[1]);
    e1.setParam("b", pIntensity.val[0]);
    observation.event(e1).send();
    } else {
    log.log("wall");
    directions.directionCalc(X,Y).send();
    }
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Direction
    #undef Y
    #undef X
}

void Capsule_Calculation::transitionaction_____transition3( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation transition Waiting,subvertex4,isStartIn:test */
    Vec3b intensity = map.at<Vec3b>(Y, X);
    x = X;
    y = Y;
    flag = (intensity.val[2] == startR);
    width = map.size().width;
    height = map.size().height;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

bool Capsule_Calculation::guard_____found( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation guard subvertex4,CoordinateCalculater */
    return flag;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

bool Capsule_Calculation::guard_____notFound( const UMLRTMessage * msg )
{
    #define X ( *(int *)msg->getParam( 0 ) )
    #define Y ( *(int *)msg->getParam( 1 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Calculation guard subvertex4,subvertex4 */
    return !flag;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Y
    #undef X
}

void Capsule_Calculation::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( Waiting );
    entryaction_____Waiting( msg );
}

void Capsule_Calculation::actionchain_____found( const UMLRTMessage * msg )
{
    transitionaction_____found( msg );
    update_state( CoordinateCalculater );
    entryaction_____CoordinateCalculater( msg );
}

void Capsule_Calculation::actionchain_____notFound( const UMLRTMessage * msg )
{
    transitionaction_____notFound( msg );
}

void Capsule_Calculation::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( Exited );
    entryaction_____Exited( msg );
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
}

void Capsule_Calculation::actionchain_____transition6( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( Exited );
    entryaction_____Exited( msg );
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
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    case port_directions2:
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
    case port_directions2:
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
        case Test::signal_isStartIn:
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
    2,
    portroles_border,
    3,
    portroles_internal
};

