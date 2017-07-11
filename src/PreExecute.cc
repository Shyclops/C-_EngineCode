
#include "PreExecute.hh"

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

#include <X11/Xlib.h>
#include "external_resources/opencv/sources/modules/core/include/opencv2/core.hpp"
#include "external_resources/opencv/sources/modules/highgui/include/opencv2/highgui.hpp"
#include "external_resources/opencv/sources/modules/imgcodecs/include/opencv2/imgcodecs.hpp"
#include "external_resources/opencv/sources/modules/imgproc/include/opencv2/imgproc.hpp"
using namespace cv;

Capsule_PreExecute::Capsule_PreExecute( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, directions( internalPorts[internalport_directions] )
, test( internalPorts[internalport_test] )
, test2( borderPorts[borderport_test2] )
, x( 0 )
, y( 0 )
, height( 0 )
, width( 0 )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[Exited] = "Exited";
    stateNames[Finished] = "Finished";
    stateNames[Main] = "Main";
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
    case Main:
        currentState = state_____Main( &message );
        break;
    case Finished:
        currentState = state_____Finished( &message );
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
    currentState = Main;
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

void Capsule_PreExecute::entryaction_____Finished( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute::Finished entry  */
    log.log("Pre-execution done");
    test.isReadyIn(x,y,height,width).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::entryaction_____Main( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute::Main entry  */
    Vec3b intensity = map.at<Vec3b>(y, x);
    r = intensity.val[2];
    test2.isStartIn(r).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::exitaction_____Main( const UMLRTMessage * msg )
{
    #define Flag ( *(bool *)msg->getParam( 0 ) )
    #define rtdata ( (bool *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute::Main exit  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Flag
}

void Capsule_PreExecute::transitionaction_____Initial( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition subvertex0,Main */
    map = imread("external_resources/map.png");
    width = map.size().width;
    height = map.size().height;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define Flag ( *(bool *)msg->getParam( 0 ) )
    #define rtdata ( (bool *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition Main,subvertex4,isStartOut:test2 */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Flag
}

void Capsule_PreExecute::transitionaction_____transition2( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition Finished,Exited,exit:directions */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::transitionaction_____transition3( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition subvertex4,Finished */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_PreExecute::transitionaction_____transition4( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute transition subvertex4,Main */
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
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

bool Capsule_PreExecute::guard_____transition3( const UMLRTMessage * msg )
{
    #define Flag ( *(bool *)msg->getParam( 0 ) )
    #define rtdata ( (bool *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute guard subvertex4,Finished */
    return Flag;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Flag
}

bool Capsule_PreExecute::guard_____transition4( const UMLRTMessage * msg )
{
    #define Flag ( *(bool *)msg->getParam( 0 ) )
    #define rtdata ( (bool *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::PreExecute guard subvertex4,Main */
    return !Flag;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef Flag
}

void Capsule_PreExecute::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( Main );
    entryaction_____Main( msg );
}

void Capsule_PreExecute::actionchain_____transition1( const UMLRTMessage * msg )
{
    exitaction_____Main( msg );
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
}

void Capsule_PreExecute::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition2( msg );
    update_state( Exited );
    entryaction_____Exited( msg );
}

void Capsule_PreExecute::actionchain_____transition3( const UMLRTMessage * msg )
{
    transitionaction_____transition3( msg );
    update_state( Finished );
    entryaction_____Finished( msg );
}

void Capsule_PreExecute::actionchain_____transition4( const UMLRTMessage * msg )
{
    transitionaction_____transition4( msg );
    update_state( Main );
    entryaction_____Main( msg );
}

Capsule_PreExecute::State Capsule_PreExecute::choice_____subvertex4( const UMLRTMessage * msg )
{
    if( guard_____transition3( msg ) )
    {
        actionchain_____transition3( msg );
        return Finished;
    }
    else if( guard_____transition4( msg ) )
    {
        actionchain_____transition4( msg );
        return Main;
    }
    return currentState;
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

Capsule_PreExecute::State Capsule_PreExecute::state_____Finished( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_directions:
        switch( msg->getSignalId() )
        {
        case Directions::signal_exit:
            actionchain_____transition2( msg );
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

Capsule_PreExecute::State Capsule_PreExecute::state_____Main( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_test2:
        switch( msg->getSignalId() )
        {
        case Test::signal_isStartOut:
            actionchain_____transition1( msg );
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
        Capsule_PreExecute::port_test2,
        "Test",
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
        "Test",
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

