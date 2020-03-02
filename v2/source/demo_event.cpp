#include "demo_event.hpp"

namespace smartHome{

DemoEvent::DemoEvent(EventType a_type, Location a_location, std::string const& a_payload, TimeStamp a_timeStamp)
: EventBase(a_type, a_location, a_timeStamp)
, m_payload(a_payload)
{
}

} //namespace smartHome