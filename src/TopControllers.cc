
#include "TopControllers.hh"

#include "Calculation.hh"
#include "Detection.hh"
#include "Observer.hh"
#include "PreExecute.hh"
#include "Running.hh"
#include "Top.hh"
#include "ZombieBehavior.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtcommsport.hh"
#include "umlrtcommsportfarend.hh"
#include "umlrtcontroller.hh"
#include "umlrtslot.hh"
#include <cstddef>


static UMLRTController MainThread_( "MainThread" );

UMLRTController * MainThread = &MainThread_;

static Capsule_Top top( &Top, &Top_slots[InstId_Top], NULL, NULL, true );

static UMLRTSlot * slots_Top[] = 
{
    &Top_slots[InstId_Top_calculation],
    &Top_slots[InstId_Top_detection],
    &Top_slots[InstId_Top_observer],
    &Top_slots[InstId_Top_test],
    &Top_slots[InstId_Top_testCont],
    &Top_slots[InstId_Top_zombieBehavior]
};

static UMLRTCapsulePart parts_Top[] = 
{
    {
        &Top,
        Capsule_Top::part_calculation,
        1,
        &slots_Top[0]
    },
    {
        &Top,
        Capsule_Top::part_detection,
        1,
        &slots_Top[1]
    },
    {
        &Top,
        Capsule_Top::part_observer,
        1,
        &slots_Top[2]
    },
    {
        &Top,
        Capsule_Top::part_test,
        1,
        &slots_Top[3]
    },
    {
        &Top,
        Capsule_Top::part_testCont,
        1,
        &slots_Top[4]
    },
    {
        &Top,
        Capsule_Top::part_zombieBehavior,
        1,
        &slots_Top[5]
    }
};

static UMLRTController CalculationThread_( "CalculationThread" );

UMLRTController * CalculationThread = &CalculationThread_;

static UMLRTCommsPortFarEnd borderfarEndList_Top_calculation[] = 
{
    {
        0,
        &borderports_Top_testCont[Capsule_Running::borderport_directions2]
    },
    {
        0,
        &borderports_Top_zombieBehavior[Capsule_ZombieBehavior::borderport_directions]
    },
    {
        0,
        &borderports_Top_test[Capsule_PreExecute::borderport_test2]
    },
    {
        0,
        &borderports_Top_zombieBehavior[Capsule_ZombieBehavior::borderport_test]
    }
};

UMLRTCommsPort borderports_Top_calculation[] = 
{
    {
        &Calculation,
        Capsule_Calculation::borderport_directions,
        &Top_slots[InstId_Top_calculation],
        1,
        borderfarEndList_Top_calculation,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    },
    {
        &Calculation,
        Capsule_Calculation::borderport_directions2,
        &Top_slots[InstId_Top_calculation],
        1,
        &borderfarEndList_Top_calculation[1],
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    },
    {
        &Calculation,
        Capsule_Calculation::borderport_test,
        &Top_slots[InstId_Top_calculation],
        1,
        &borderfarEndList_Top_calculation[2],
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    },
    {
        &Calculation,
        Capsule_Calculation::borderport_test2,
        &Top_slots[InstId_Top_calculation],
        1,
        &borderfarEndList_Top_calculation[3],
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_calculation_ptrs[] = 
{
    &borderports_Top_calculation[0],
    &borderports_Top_calculation[1],
    &borderports_Top_calculation[2],
    &borderports_Top_calculation[3]
};

static UMLRTCommsPortFarEnd internalfarEndList_Top_calculation[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_calculation[] = 
{
    {
        &Calculation,
        Capsule_Calculation::internalport_directions3,
        &Top_slots[InstId_Top_calculation],
        1,
        internalfarEndList_Top_calculation,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &Calculation,
        Capsule_Calculation::internalport_observation,
        &Top_slots[InstId_Top_calculation],
        1,
        &internalfarEndList_Top_calculation[2],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &Calculation,
        Capsule_Calculation::internalport_log,
        &Top_slots[InstId_Top_calculation],
        1,
        &internalfarEndList_Top_calculation[1],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_calculation_ptrs[] = 
{
    &internalports_Top_calculation[0],
    &internalports_Top_calculation[1],
    &internalports_Top_calculation[2]
};

static Capsule_Calculation top_calculation( &Calculation, &Top_slots[InstId_Top_calculation], borderports_Top_calculation_ptrs, internalports_Top_calculation_ptrs, true );

static UMLRTController DetectionThread_( "DetectionThread" );

UMLRTController * DetectionThread = &DetectionThread_;

static UMLRTCommsPortFarEnd borderfarEndList_Top_detection[] = 
{
    {
        0,
        &borderports_Top_testCont[Capsule_Running::borderport_directions]
    }
};

UMLRTCommsPort borderports_Top_detection[] = 
{
    {
        &Detection,
        Capsule_Detection::borderport_directions,
        &Top_slots[InstId_Top_detection],
        1,
        borderfarEndList_Top_detection,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_detection_ptrs[] = 
{
    &borderports_Top_detection[0]
};

static UMLRTCommsPortFarEnd internalfarEndList_Top_detection[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_detection[] = 
{
    {
        &Detection,
        Capsule_Detection::internalport_test,
        &Top_slots[InstId_Top_detection],
        1,
        &internalfarEndList_Top_detection[1],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &Detection,
        Capsule_Detection::internalport_timing,
        &Top_slots[InstId_Top_detection],
        1,
        &internalfarEndList_Top_detection[2],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &Detection,
        Capsule_Detection::internalport_log,
        &Top_slots[InstId_Top_detection],
        1,
        internalfarEndList_Top_detection,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_detection_ptrs[] = 
{
    &internalports_Top_detection[0],
    &internalports_Top_detection[1],
    &internalports_Top_detection[2]
};

static Capsule_Detection top_detection( &Detection, &Top_slots[InstId_Top_detection], borderports_Top_detection_ptrs, internalports_Top_detection_ptrs, true );

static UMLRTController ObserverThread_( "ObserverThread" );

UMLRTController * ObserverThread = &ObserverThread_;

static UMLRTCommsPortFarEnd internalfarEndList_Top_observer[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_observer[] = 
{
    {
        &Observer,
        Capsule_Observer::internalport_observation,
        &Top_slots[InstId_Top_observer],
        20,
        &internalfarEndList_Top_observer[1],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        true,
        false,
        false,
        false,
        true,
        false,
        false
    },
    {
        &Observer,
        Capsule_Observer::internalport_timer,
        &Top_slots[InstId_Top_observer],
        1,
        &internalfarEndList_Top_observer[21],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &Observer,
        Capsule_Observer::internalport_log,
        &Top_slots[InstId_Top_observer],
        1,
        internalfarEndList_Top_observer,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_observer_ptrs[] = 
{
    &internalports_Top_observer[0],
    &internalports_Top_observer[1],
    &internalports_Top_observer[2]
};

static Capsule_Observer top_observer( &Observer, &Top_slots[InstId_Top_observer], NULL, internalports_Top_observer_ptrs, true );

static UMLRTController TestThread_( "TestThread" );

UMLRTController * TestThread = &TestThread_;

static UMLRTCommsPortFarEnd borderfarEndList_Top_test[] = 
{
    {
        0,
        &borderports_Top_calculation[Capsule_Calculation::borderport_test]
    }
};

UMLRTCommsPort borderports_Top_test[] = 
{
    {
        &PreExecute,
        Capsule_PreExecute::borderport_test2,
        &Top_slots[InstId_Top_test],
        1,
        borderfarEndList_Top_test,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_test_ptrs[] = 
{
    &borderports_Top_test[0]
};

static UMLRTCommsPortFarEnd internalfarEndList_Top_test[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_test[] = 
{
    {
        &PreExecute,
        Capsule_PreExecute::internalport_directions,
        &Top_slots[InstId_Top_test],
        1,
        internalfarEndList_Top_test,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &PreExecute,
        Capsule_PreExecute::internalport_test,
        &Top_slots[InstId_Top_test],
        2,
        &internalfarEndList_Top_test[2],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        false,
        true,
        false,
        false
    },
    {
        &PreExecute,
        Capsule_PreExecute::internalport_log,
        &Top_slots[InstId_Top_test],
        1,
        &internalfarEndList_Top_test[1],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_test_ptrs[] = 
{
    &internalports_Top_test[0],
    &internalports_Top_test[1],
    &internalports_Top_test[2]
};

static Capsule_PreExecute top_test( &PreExecute, &Top_slots[InstId_Top_test], borderports_Top_test_ptrs, internalports_Top_test_ptrs, true );

static UMLRTCommsPortFarEnd borderfarEndList_Top_testCont[] = 
{
    {
        0,
        &borderports_Top_detection[Capsule_Detection::borderport_directions]
    },
    {
        0,
        &borderports_Top_calculation[Capsule_Calculation::borderport_directions]
    }
};

UMLRTCommsPort borderports_Top_testCont[] = 
{
    {
        &Running,
        Capsule_Running::borderport_directions,
        &Top_slots[InstId_Top_testCont],
        1,
        borderfarEndList_Top_testCont,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    },
    {
        &Running,
        Capsule_Running::borderport_directions2,
        &Top_slots[InstId_Top_testCont],
        1,
        &borderfarEndList_Top_testCont[1],
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_testCont_ptrs[] = 
{
    &borderports_Top_testCont[0],
    &borderports_Top_testCont[1]
};

static UMLRTCommsPortFarEnd internalfarEndList_Top_testCont[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_testCont[] = 
{
    {
        &Running,
        Capsule_Running::internalport_directions3,
        &Top_slots[InstId_Top_testCont],
        2,
        internalfarEndList_Top_testCont,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        false,
        true,
        false,
        false
    },
    {
        &Running,
        Capsule_Running::internalport_test,
        &Top_slots[InstId_Top_testCont],
        1,
        &internalfarEndList_Top_testCont[3],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &Running,
        Capsule_Running::internalport_log,
        &Top_slots[InstId_Top_testCont],
        1,
        &internalfarEndList_Top_testCont[2],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_testCont_ptrs[] = 
{
    &internalports_Top_testCont[0],
    &internalports_Top_testCont[1],
    &internalports_Top_testCont[2]
};

static Capsule_Running top_testCont( &Running, &Top_slots[InstId_Top_testCont], borderports_Top_testCont_ptrs, internalports_Top_testCont_ptrs, true );

static UMLRTController ZombieThread_( "ZombieThread" );

UMLRTController * ZombieThread = &ZombieThread_;

static UMLRTCommsPortFarEnd borderfarEndList_Top_zombieBehavior[] = 
{
    {
        0,
        &borderports_Top_calculation[Capsule_Calculation::borderport_directions2]
    },
    {
        0,
        &borderports_Top_calculation[Capsule_Calculation::borderport_test2]
    }
};

UMLRTCommsPort borderports_Top_zombieBehavior[] = 
{
    {
        &ZombieBehavior,
        Capsule_ZombieBehavior::borderport_directions,
        &Top_slots[InstId_Top_zombieBehavior],
        1,
        borderfarEndList_Top_zombieBehavior,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    },
    {
        &ZombieBehavior,
        Capsule_ZombieBehavior::borderport_test,
        &Top_slots[InstId_Top_zombieBehavior],
        1,
        &borderfarEndList_Top_zombieBehavior[1],
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_zombieBehavior_ptrs[] = 
{
    &borderports_Top_zombieBehavior[0],
    &borderports_Top_zombieBehavior[1]
};

static UMLRTCommsPortFarEnd internalfarEndList_Top_zombieBehavior[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_zombieBehavior[] = 
{
    {
        &ZombieBehavior,
        Capsule_ZombieBehavior::internalport_timing,
        &Top_slots[InstId_Top_zombieBehavior],
        1,
        &internalfarEndList_Top_zombieBehavior[1],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &ZombieBehavior,
        Capsule_ZombieBehavior::internalport_log,
        &Top_slots[InstId_Top_zombieBehavior],
        1,
        internalfarEndList_Top_zombieBehavior,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_zombieBehavior_ptrs[] = 
{
    &internalports_Top_zombieBehavior[0],
    &internalports_Top_zombieBehavior[1]
};

static Capsule_ZombieBehavior top_zombieBehavior( &ZombieBehavior, &Top_slots[InstId_Top_zombieBehavior], borderports_Top_zombieBehavior_ptrs, internalports_Top_zombieBehavior_ptrs, true );

UMLRTSlot Top_slots[] = 
{
    {
        "Top",
        0,
        &Top,
        NULL,
        0,
        &top,
        &MainThread_,
        6,
        parts_Top,
        0,
        NULL,
        NULL,
        true,
        false
    },
    {
        "Top.calculation",
        0,
        &Calculation,
        &Top,
        Capsule_Top::part_calculation,
        &top_calculation,
        &CalculationThread_,
        0,
        NULL,
        4,
        borderports_Top_calculation,
        NULL,
        true,
        false
    },
    {
        "Top.detection",
        0,
        &Detection,
        &Top,
        Capsule_Top::part_detection,
        &top_detection,
        &DetectionThread_,
        0,
        NULL,
        1,
        borderports_Top_detection,
        NULL,
        true,
        false
    },
    {
        "Top.observer",
        0,
        &Observer,
        &Top,
        Capsule_Top::part_observer,
        &top_observer,
        &ObserverThread_,
        0,
        NULL,
        0,
        NULL,
        NULL,
        true,
        false
    },
    {
        "Top.test",
        0,
        &PreExecute,
        &Top,
        Capsule_Top::part_test,
        &top_test,
        &TestThread_,
        0,
        NULL,
        1,
        borderports_Top_test,
        NULL,
        true,
        false
    },
    {
        "Top.testCont",
        0,
        &Running,
        &Top,
        Capsule_Top::part_testCont,
        &top_testCont,
        &TestThread_,
        0,
        NULL,
        2,
        borderports_Top_testCont,
        NULL,
        true,
        false
    },
    {
        "Top.zombieBehavior",
        0,
        &ZombieBehavior,
        &Top,
        Capsule_Top::part_zombieBehavior,
        &top_zombieBehavior,
        &ZombieThread_,
        0,
        NULL,
        2,
        borderports_Top_zombieBehavior,
        NULL,
        true,
        false
    }
};

