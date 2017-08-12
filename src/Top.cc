
#include "Top.hh"

#include "Calculation.hh"
#include "Detection.hh"
#include "Observer.hh"
#include "PreExecute.hh"
#include "Running.hh"
#include "ZombieBehavior.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtcommsport.hh"
#include "umlrtframeservice.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsulerole.hh"
class UMLRTRtsInterface;

Capsule_Top::Capsule_Top( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, calculation( &slot->parts[part_calculation] )
, detection( &slot->parts[part_detection] )
, observer( &slot->parts[part_observer] )
, test( &slot->parts[part_test] )
, testCont( &slot->parts[part_testCont] )
, zombieBehavior( &slot->parts[part_zombieBehavior] )
{
}








void Capsule_Top::bindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::unbindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::initialize( const UMLRTMessage & msg )
{
}

void Capsule_Top::inject( const UMLRTMessage & msg )
{
}


static const UMLRTCapsuleRole roles[] = 
{
    {
        "calculation",
        &Calculation,
        1,
        1,
        false,
        false
    },
    {
        "detection",
        &Detection,
        1,
        1,
        false,
        false
    },
    {
        "observer",
        &Observer,
        1,
        1,
        false,
        false
    },
    {
        "test",
        &PreExecute,
        1,
        1,
        false,
        false
    },
    {
        "testCont",
        &Running,
        1,
        1,
        false,
        false
    },
    {
        "zombieBehavior",
        &ZombieBehavior,
        1,
        1,
        false,
        false
    }
};

static void instantiate_Top( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    UMLRTFrameService::connectPorts( &slot->parts[Capsule_Top::part_calculation].slots[0]->ports[Capsule_Calculation::borderport_directions], 0, &slot->parts[Capsule_Top::part_testCont].slots[0]->ports[Capsule_Running::borderport_directions2], 0 );
    UMLRTFrameService::connectPorts( &slot->parts[Capsule_Top::part_calculation].slots[0]->ports[Capsule_Calculation::borderport_directions2], 0, &slot->parts[Capsule_Top::part_zombieBehavior].slots[0]->ports[Capsule_ZombieBehavior::borderport_directions], 0 );
    UMLRTFrameService::connectPorts( &slot->parts[Capsule_Top::part_calculation].slots[0]->ports[Capsule_Calculation::borderport_test], 0, &slot->parts[Capsule_Top::part_test].slots[0]->ports[Capsule_PreExecute::borderport_test2], 0 );
    UMLRTFrameService::connectPorts( &slot->parts[Capsule_Top::part_calculation].slots[0]->ports[Capsule_Calculation::borderport_test2], 0, &slot->parts[Capsule_Top::part_zombieBehavior].slots[0]->ports[Capsule_ZombieBehavior::borderport_test], 0 );
    UMLRTFrameService::connectPorts( &slot->parts[Capsule_Top::part_detection].slots[0]->ports[Capsule_Detection::borderport_directions], 0, &slot->parts[Capsule_Top::part_testCont].slots[0]->ports[Capsule_Running::borderport_directions], 0 );
    Calculation.instantiate( NULL, slot->parts[Capsule_Top::part_calculation].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_calculation].slots[0], Calculation.numPortRolesBorder ) );
    Detection.instantiate( NULL, slot->parts[Capsule_Top::part_detection].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_detection].slots[0], Detection.numPortRolesBorder ) );
    Observer.instantiate( NULL, slot->parts[Capsule_Top::part_observer].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_observer].slots[0], Observer.numPortRolesBorder ) );
    PreExecute.instantiate( NULL, slot->parts[Capsule_Top::part_test].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_test].slots[0], PreExecute.numPortRolesBorder ) );
    Running.instantiate( NULL, slot->parts[Capsule_Top::part_testCont].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_testCont].slots[0], Running.numPortRolesBorder ) );
    ZombieBehavior.instantiate( NULL, slot->parts[Capsule_Top::part_zombieBehavior].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_zombieBehavior].slots[0], ZombieBehavior.numPortRolesBorder ) );
    slot->capsule = new Capsule_Top( &Top, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Top = 
{
    "Top",
    NULL,
    instantiate_Top,
    6,
    roles,
    0,
    NULL,
    0,
    NULL
};

