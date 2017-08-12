
#include "Observer.hh"

#include "Observation.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtsignal.hh"
#include "umlrtslot.hh"
#include "umlrttimerprotocol.hh"
#include <cstddef>
#include "EventObj.hh"
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

void Capsule_Observer::transitionaction_____command_received( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Observation::Observer transition OBSERVING,OBSERVING,timeout:timer */
    std::string data = this->method->read();
    std::stringstream ss;
    if (data != "") {
    std::istringstream iss(data);
    std::vector<std::string> cmd;
    while (iss) {
    std::string subs;
    iss >> subs; 
    if (iss != "") {
    cmd.push_back(subs);
    }
    }
    if (cmd.size() == 0)
    return;
    if (cmd.size() > 1 && cmd[0] == "list" && cmd[1] == "capsules") {
    ss  << "List of capsules:\n";
    std::map<std::string, size_t>::iterator iter;
    for(iter=capsules.begin(); iter!=capsules.end(); ++iter) {
    ss << " - " << iter->first << " ["<< capsuleTypes[iter->first]<< "]\n";
    }
    this->method->sendData(ss.str());
    }
    else if (cmd.size() > 2 && cmd[0] == "show" && cmd[1] == "capsule") {
    printf("capsule:%s|type:%s\n", cmd[1].c_str(), capsuleTypes[cmd[2]].c_str());
    if (capsuleTypes[cmd[2]] == "") {
    printf("error: %s\n", capsuleTypes[cmd[2]].c_str());
    return;
    }
    std::string capsuleType = capsuleTypes[cmd[2]];
    ss  << "Capsule: " << cmd[2];
    ss  << " type: " << capsuleTypes[cmd[2]] << "\n";
    ss  << "List of triggers:\n";
    if (capsuleType == "Gen") {
    ss << " - " << "generate()\n";
    this->method->sendData(ss.str());
    }
    }
    }
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Observer::transitionaction_____configure( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Observation::Observer transition subvertex0,OBSERVING */
    int n = config.load();
    log.show("Number of entries: %d\n", n);
    // Socket
    this->method = new Socket();
    this->method->configure(config.getConfigList());
    this->method->connect();
    // Text 
    this->serializer = new Text();
    this->serializer->configure(config.getConfigList());
    // Instantiating the timer
    timer.informEvery(UMLRTTimespec(0,500000000));
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Observer::transitionaction_____event_received( const UMLRTMessage * msg )
{
    #define data ( *(const EventObj * )msg->getParam( 0 ) )
    #define rtdata ( (const EventObj * )msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Observation::Observer transition OBSERVING,OBSERVING,event:observation */
    std::string str = this->serializer->serialize(data.event) + "\n";
    this->method->sendData(str);
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef data
}

void Capsule_Observer::transitionaction_____register_capsules( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/Engine/Engine.uml Engine::Observation::Observer transition OBSERVING,OBSERVING,rtBound:observation */
    std::stringstream ss;
    ss << msg->signal.getSrcPort()->slot->name << ":" << msg->signal.getSrcPort()->slot->capsuleIndex;
    printf("capsule name: %s\n", ss.str().c_str());
    capsules[ss.str()] = msg->srcPortIndex;
    capsuleTypes[ss.str()] = msg->signal.getSrcPort()->slot->capsuleClass->name;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Observer::actionchain_____command_received( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____command_received( msg );
    update_state( OBSERVING );
    /* Initialization: */
    std::string data = CLIUtils::trim(this->method->read());
    std::stringstream ss;
    if (data == "") return;
    std::vector<std::string> cmd = CLIUtils::tokenizeCommand(data);
    if (cmd.size() == 0) return;
    /* List all observable capsules: */
    if (cmd.size() > 1 && cmd[0] == "list" && cmd[1] == "capsules") {
    ss << "List of capsules\n";
    std::map<std::string, size_t>::iterator iter;
    for(iter = capsules.begin(); iter != capsules.end(); iter++) {
    ss << " - " << iter->first << " ["<< capsuleTypes[iter->first]<< "]\n";
    }
    this->method->sendData(ss.str());
    }
    /* Show a specific capsule: */
    if (cmd.size() > 2 && cmd[0] == "show" && cmd[1] == "capsule") {
    std::string capsuleType = capsuleTypes[cmd[2]];
    if (capsuleType == "") {
    printf("error: %s\n", capsuleType.c_str());
    return;
    }
    ss << "Capsule: " << cmd[2];
    ss  << " type: " << capsuleTypes[cmd[2]] << "\n";
    ss  << "List of triggers:\n";
    this->method->sendData(ss.str());
    }
    /* Trigger a capsule signal: */
    if (cmd.size() > 4 && cmd[0] == "send") {
    std::string capsule = cmd[4];
    std::string capsuleType = capsuleTypes[capsule];
    std::string trigger = cmd[1];
    }
}

void Capsule_Observer::actionchain_____configure( const UMLRTMessage * msg )
{
    transitionaction_____configure( msg );
    update_state( OBSERVING );
}

void Capsule_Observer::actionchain_____event_received( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____event_received( msg );
    update_state( OBSERVING );
}

void Capsule_Observer::actionchain_____register_capsules( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____register_capsules( msg );
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
            actionchain_____event_received( msg );
            return OBSERVING;
        case UMLRTSignal::rtBound:
            actionchain_____register_capsules( msg );
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
            actionchain_____command_received( msg );
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
        true,
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

