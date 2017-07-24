
#ifndef CALCULATION_HH
#define CALCULATION_HH

#include "Directions.hh"
#include "Observation.hh"
#include "Test.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

#include <vector>
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
        borderport_test
    };
protected:
    Directions::Base directions2;
public:
    enum InternalPortId
    {
        internalport_directions2,
        internalport_observation,
        internalport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
    Observation::Base observation;
    Test::Base test;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_directions,
        port_directions2,
        port_log,
        port_observation,
        port_test
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
private:
    int startR;
    int emptyR;
    Mat map;
    bool flag;
    int x;
    int y;
    int height;
    int width;
public:
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

