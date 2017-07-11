
#include "TopControllers.hh"

#include "Calculation.hh"
#include "Detection.hh"
#include "PreExecute.hh"
#include "TestCont.hh"
#include "Top.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtcommsport.hh"
#include "umlrtcommsportfarend.hh"
#include "umlrtcontroller.hh"
#include "umlrtslot.hh"
#include <cstddef>


static UMLRTController DefaultController_( "DefaultController" );

UMLRTController * DefaultController = &DefaultController_;

static Capsule_Top top( &Top, &Top_slots[InstId_Top], NULL, NULL, true );

static UMLRTSlot * slots_Top[] = 
{
    &Top_slots[InstId_Top_calculation],
    &Top_slots[InstId_Top_detection],
    &Top_slots[InstId_Top_test],
    &Top_slots[InstId_Top_testCont]
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
        Capsule_Top::part_test,
        1,
        &slots_Top[2]
    },
    {
        &Top,
        Capsule_Top::part_testCont,
        1,
        &slots_Top[3]
    }
};

static UMLRTCommsPortFarEnd borderfarEndList_Top_calculation[] = 
{
    {
        0,
        &borderports_Top_testCont[Capsule_TestCont::borderport_directions2]
    },
    {
        0,
        &borderports_Top_test[Capsule_PreExecute::borderport_test2]
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
        Capsule_Calculation::borderport_test,
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
    }
};

static const UMLRTCommsPort * borderports_Top_calculation_ptrs[] = 
{
    &borderports_Top_calculation[0],
    &borderports_Top_calculation[1]
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
    }
};

UMLRTCommsPort internalports_Top_calculation[] = 
{
    {
        &Calculation,
        Capsule_Calculation::internalport_directions2,
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
    &internalports_Top_calculation[1]
};

static Capsule_Calculation top_calculation( &Calculation, &Top_slots[InstId_Top_calculation], borderports_Top_calculation_ptrs, internalports_Top_calculation_ptrs, true );

static UMLRTCommsPortFarEnd borderfarEndList_Top_detection[] = 
{
    {
        0,
        &borderports_Top_testCont[Capsule_TestCont::borderport_directions]
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
        &TestCont,
        Capsule_TestCont::borderport_directions,
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
        &TestCont,
        Capsule_TestCont::borderport_directions2,
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
        &TestCont,
        Capsule_TestCont::internalport_directions3,
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
        &TestCont,
        Capsule_TestCont::internalport_test,
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
        &TestCont,
        Capsule_TestCont::internalport_log,
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

static Capsule_TestCont top_testCont( &TestCont, &Top_slots[InstId_Top_testCont], borderports_Top_testCont_ptrs, internalports_Top_testCont_ptrs, true );

UMLRTSlot Top_slots[] = 
{
    {
        "Top",
        0,
        &Top,
        NULL,
        0,
        &top,
        &DefaultController_,
        4,
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
        &DefaultController_,
        0,
        NULL,
        2,
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
        &DefaultController_,
        0,
        NULL,
        1,
        borderports_Top_detection,
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
        &DefaultController_,
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
        &TestCont,
        &Top,
        Capsule_Top::part_testCont,
        &top_testCont,
        &DefaultController_,
        0,
        NULL,
        2,
        borderports_Top_testCont,
        NULL,
        true,
        false
    }
};

