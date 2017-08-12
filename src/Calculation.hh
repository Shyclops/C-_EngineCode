
#ifndef CALCULATION_HH
#define CALCULATION_HH

#include "Directions.hh"
#include "Observation.hh"
#include "Status.hh"
#include "Vector.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

#include "Zombie.hh"
#include "external_resources/opencv/sources/modules/core/include/opencv2/core.hpp"
#include "external_resources/opencv/sources/modules/highgui/include/opencv2/highgui.hpp"
#include "external_resources/opencv/sources/modules/imgcodecs/include/opencv2/imgcodecs.hpp"
#include "external_resources/opencv/sources/modules/imgproc/include/opencv2/imgproc.hpp"
using namespace cv;

class Capsule_Calculation : public UMLRTCapsule
{
public:
    Capsule_Calculation( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    Directions::Base directions;
public:
    enum BorderPortId
    {
        borderport_directions,
        borderport_directions2,
        borderport_test,
        borderport_test2
    };
protected:
    Directions::Base directions2;
    Directions::Base directions3;
public:
    enum InternalPortId
    {
        internalport_directions3,
        internalport_observation,
        internalport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
    Observation::Base observation;
    Status::Base test;
    Status::Base test2;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_directions,
        port_directions2,
        port_directions3,
        port_log,
        port_observation,
        port_test,
        port_test2
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
private:
    int startR;
    int emptyR;
    int zombieR;
    Mat map;
    int x;
    int y;
    int height;
    int width;
    Vector zombieVector;
    int zombies;
public:
    int startDirection;
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        CoordinateCalculater,
        Exited,
        Waiting,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[5];
    State currentState;
    void update_state( State newState );
    void entryaction_____CoordinateCalculater( const UMLRTMessage * msg );
    void entryaction_____Exited( const UMLRTMessage * msg );
    void entryaction_____Waiting( const UMLRTMessage * msg );
    void transitionaction_____Initial( const UMLRTMessage * msg );
    void transitionaction_____found( const UMLRTMessage * msg );
    void transitionaction_____notFound( const UMLRTMessage * msg );
    void transitionaction_____transition2( const UMLRTMessage * msg );
    void transitionaction_____transition3( const UMLRTMessage * msg );
    bool guard_____found( const UMLRTMessage * msg );
    bool guard_____notFound( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____found( const UMLRTMessage * msg );
    void actionchain_____notFound( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    void actionchain_____transition3( const UMLRTMessage * msg );
    void actionchain_____transition6( const UMLRTMessage * msg );
    State choice_____subvertex4( const UMLRTMessage * msg );
    State state_____CoordinateCalculater( const UMLRTMessage * msg );
    State state_____Exited( const UMLRTMessage * msg );
    State state_____Waiting( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Calculation;

#endif

