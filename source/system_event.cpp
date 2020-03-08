#include "system_events.hpp" 

namespace smartHome {
namespace systemEvents {


SystemEvent::SystemEvent(EventType a_type, Location a_location, std::string const&, TimeStamp a_timeStamp)
: EventBase(a_type, a_location, a_timeStamp)
{
}

} //namespace systemEvents
} //namespace smartHome
