#ifndef SYSTEM_EVENTS_HPP
#define SYSTEM_EVENTS_HPP

#include "event_base.hpp" //Topic, Location

namespace smartHome {
namespace systemEvents {


const Topic g_systemOnTopic("SystemOn", Location(0,0));
const Topic g_shutDownTopic("ShutDown", Location(0,0));

struct SystemEvent: public EventBase {
    SystemEvent(EventType a_type, Location a_location, std::string const& Payload = " ", TimeStamp a_timeStamp = "00:00");
};



} //namespace systemEvents
} //namespace smartHome

#endif //SYSTEM_EVENTS_HPP