#ifndef DEMO_EVENT_HPP
#define DEMO_EVENT_HPP

#include <string> //std::string

#include "event_base.hpp"

namespace smartHome {

struct DemoEvent : public EventBase
{
    DemoEvent(EventType a_type, Location a_location, std::string const& Payload = " ", TimeStamp a_timeStamp = "00:00");
    
    std::string m_payload;
};

} // namespace smartHome

#endif //DEMO_EVENT_HPP