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

DemoSensor::DemoSensor(IEventFactory& a_factory, size_t a_numOfEvents)
: m_factory(a_factory)
, m_numOfEvents(a_numOfEvents)
{
}

const Location DemoSensor::DemoLoc = Location(5, 2);

void DemoSensor::Run() noexcept
{
    for (size_t i = 0; i < m_numOfEvents ; ++i)
    {
        m_factory.GenrateEvent(std::make_shared<Event>(0, DemoLoc, "5:05"));
    }
}

} // namespace eventor
} // namespace smartHome