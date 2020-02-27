#include <unistd.h> //sleep

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

const Location DemoCensor::DemoLoc = Location(5, 2);

void DemoCensor::Run() noexcept
{
    for (size_t i = 0; i < NumOfEvents ; ++i)
    {
        Event(DemoType, DemoLoc, "5:05");
        sleep(3);
    }
}

} // namespace eventor
} // namespace smartHome