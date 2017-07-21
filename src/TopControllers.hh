
#ifndef TOPCONTROLLERS_HH
#define TOPCONTROLLERS_HH

class UMLRTController;
struct UMLRTCommsPort;
struct UMLRTSlot;

enum CapsuleInstanceId
{
    InstId_Top,
    InstId_Top_calculation,
    InstId_Top_detection,
    InstId_Top_observer,
    InstId_Top_test,
    InstId_Top_testCont
};
extern UMLRTController * DefaultController;
extern UMLRTCommsPort borderports_Top_calculation[];
extern UMLRTCommsPort internalports_Top_calculation[];
extern UMLRTCommsPort borderports_Top_detection[];
extern UMLRTCommsPort internalports_Top_detection[];
extern UMLRTCommsPort internalports_Top_observer[];
extern UMLRTCommsPort borderports_Top_test[];
extern UMLRTCommsPort internalports_Top_test[];
extern UMLRTCommsPort borderports_Top_testCont[];
extern UMLRTCommsPort internalports_Top_testCont[];
extern UMLRTSlot Top_slots[];

#endif

