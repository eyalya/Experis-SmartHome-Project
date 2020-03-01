#include <unistd.h> //sleep

#include "light_event_factory.hpp"

namespace smartHome {
namespace eventor {

LightEventFactory::LightEventFactory(hub::EventsPool& a_eventPool)
: m_events(a_eventPool)
{
}

void LightEventFactory::GenrateEvent(EventPtr a_event)
{
    m_events.Submit(a_event);
}


} // namespace eventor
} // namespace smartHome