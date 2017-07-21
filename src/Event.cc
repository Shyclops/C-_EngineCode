
#include "Event.hh"


#include <string>
#include <sstream>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "umlrtobjectclass.hh"
#include "umlrtobjectclassgeneric.hh"

const UMLRTObject_field Event::fields[] = 
{
};



Event::Event(std::string capsuleInstance,
std::string sourceName,
EventSource eventSource,
EventKind eventKind,
long seconds,
long nanoseconds) {

this->generateEventId();
this->setCapsuleInstance(capsuleInstance);
this->setSourceName(sourceName);
this->setEventSource(eventSource);
this->setEventKind(eventKind);
}

const std::string Event::getCapsuleInstance() const {
return this->capsuleInstance;
}

void Event::setCapsuleInstance(const std::string capsuleInstance) {
this->capsuleInstance = capsuleInstance;
}

const std::string Event::getSourceName() const {
return this->sourceName;
}

void Event::setSourceName(const std::string sourceName) {
this->sourceName = sourceName;
}

const Event::EventSource Event::getEventSource() const {
return this->eventSource;
}

void Event::setEventSource(const Event::EventSource source) {
this->eventSource = source;
}

const Event::EventKind Event::getEventKind() const {
return this->eventKind;
}

void Event::setEventKind(const Event::EventKind kind) {
this->eventKind = kind;
}

const long Event::getSeconds() const {
return this->seconds;
}

const long Event::getNanoseconds() const {
return this->nanoseconds;
}

void Event::setTimestamp() {

long seconds, nanoseconds;

struct timeval tp;
gettimeofday(&tp, NULL);

seconds = tp.tv_sec;
nanoseconds = tp.tv_usec * 1000;

this->setTimestamp(seconds, nanoseconds);

}

void Event::setTimestamp(const long seconds, const long nanoseconds) {
setSeconds(seconds);
this->setNanoseconds(nanoseconds);
this->seconds = seconds;
this->nanoseconds = nanoseconds;
}

void Event::setSeconds(const long seconds) {
this->seconds = seconds;
}
void Event::setNanoseconds(const long nanoseconds) {
this->nanoseconds = nanoseconds;
}

const std::string Event::getEventId() const {
return this->eventId;
}

void Event::setEventId(const std::string eventId) {
this->eventId = eventId;
}

void Event::generateEventId() {

long seconds, nanoseconds;

struct timeval tp;
gettimeofday(&tp, NULL);

seconds = tp.tv_sec;
nanoseconds = tp.tv_usec * 1000;

std::stringstream ss;
int r;
r=random();

ss << seconds << nanoseconds << r;
this->eventId = ss.str();
}

const std::map<std::string, std::string> Event::getParams() const {
return params;
}

const std::string Event::getParam(std::string key) const {
bool n = this->params.count(key);
return (n) ? this->params.at(key) : "";
}

void Event::setParams(const  std::map<std::string, std::string> params) {
this->params = params;
}

void Event::setParam(const  std::string key, const std::string value) {
if (key.length() >= 1)
this->params[key] = value;
}

void Event::setParam(const  std::string key, const int value) {
std::stringstream v;
v << value;
this->setParam(key, v.str());
}

void Event::clearParams() {
this->params.clear();
}

const UMLRTObject_class UMLRTType_Event = 
{
UMLRTObjectInitialize<Event>,
UMLRTObjectCopy<Event>,
UMLRTObject_decode,
UMLRTObject_encode,
UMLRTObjectDestroy<Event>,
UMLRTObject_fprintf,
"Event",
NULL,
{
sizeof( Event ),
0,
Event::fields
},
UMLRTOBJECTCLASS_DEFAULT_VERSION,
UMLRTOBJECTCLASS_DEFAULT_BACKWARDS
};

