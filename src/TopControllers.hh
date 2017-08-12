
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
    InstId_Top_testCont,
    InstId_Top_zombieBehavior
};
extern UMLRTController * MainThread;
extern UMLRTController * CalculationThread;
extern UMLRTCommsPort borderports_Top_calculation[];
extern UMLRTCommsPort internalports_Top_calculation[];
extern UMLRTController * DetectionThread;
extern UMLRTCommsPort borderports_Top_detection[];
extern UMLRTCommsPort internalports_Top_detection[];
extern UMLRTController * ObserverThread;
extern UMLRTCommsPort internalports_Top_observer[];
extern UMLRTController * TestThread;
extern UMLRTCommsPort borderports_Top_test[];
extern UMLRTCommsPort internalports_Top_test[];
extern UMLRTCommsPort borderports_Top_testCont[];
extern UMLRTCommsPort internalports_Top_testCont[];
extern UMLRTController * ZombieThread;
extern UMLRTCommsPort borderports_Top_zombieBehavior[];
extern UMLRTCommsPort internalports_Top_zombieBehavior[];
extern UMLRTSlot Top_slots[];

#endif

