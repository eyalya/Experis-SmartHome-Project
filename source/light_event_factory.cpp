#include "light_event_factory.hpp"

namespace smartHome {
namespace eventor {

LightEventFactory::LightEventFactory(advcpp::WaitableQ<EventPtr>& a_eventQ)
: m_events(a_eventQ)
{
}

void LightEventFactory::GenrateEvent(EventPtr a_event)
{
    m_events.Enqueue(a_event);
}

DemoCensor::DemoCensor(IEventFactory& a_factory)
: m_factory(a_factory)
{
}

} // namespace eventor
} // namespace smartHome