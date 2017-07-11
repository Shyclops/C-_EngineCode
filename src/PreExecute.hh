
#ifndef PREEXECUTE_HH
#define PREEXECUTE_HH

#include "Directions.hh"
#include "Test.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

#include <X11/Xlib.h>
#include "external_resources/opencv/sources/modules/core/include/opencv2/core.hpp"
#include "external_resources/opencv/sources/modules/highgui/include/opencv2/highgui.hpp"
#include "external_resources/opencv/sources/modules/imgcodecs/include/opencv2/imgcodecs.hpp"
#include "external_resources/opencv/sources/modules/imgproc/include/opencv2/imgproc.hpp"
using namespace cv;

class Capsule_PreExecute : public UMLRTCapsule
{
public:
    Capsule_PreExecute( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    Directions::Conj directions;
public:
    enum InternalPortId
    {
        internalport_directions,
        internalport_test,
        internalport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
    Test::Conj test;
    Test::Conj test2;
public:
    enum BorderPortId
    {
        borderport_test2
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_directions,
        port_log,
        port_test,
        port_test2
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
private:
    int x;
    int y;
    Mat map;
    int height;
    int width;
    unsigned char r;
public:
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        Exited,
        Finished,
        Main,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[5];
    State currentState;
    void update_state( State newState );
    void entryaction_____Exited( const UMLRTMessage * msg );
    void entryaction_____Finished( const UMLRTMessage * msg );
    void entryaction_____Main( const UMLRTMessage * msg );
    void exitaction_____Main( const UMLRTMessage * msg );
    void transitionaction_____Initial( const UMLRTMessage * msg );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void transitionaction_____transition2( const UMLRTMessage * msg );
    void transitionaction_____transition3( const UMLRTMessage * msg );
    void transitionaction_____transition4( const UMLRTMessage * msg );
    bool guard_____transition3( const UMLRTMessage * msg );
    bool guard_____transition4( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    void actionchain_____transition3( const UMLRTMessage * msg );
    void actionchain_____transition4( const UMLRTMessage * msg );
    State choice_____subvertex4( const UMLRTMessage * msg );
    State state_____Exited( const UMLRTMessage * msg );
    State state_____Finished( const UMLRTMessage * msg );
    State state_____Main( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass PreExecute;

#endif

