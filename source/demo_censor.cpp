#include "demo_censor.hpp"

namespace smartHome {
namespace eventor {

DemoSensor::DemoSensor(IEventFactory& a_factory, size_t a_numOfEvents)
: m_factory(a_factory)
, m_numOfEvents(a_numOfEvents)
{
}

const Location DemoSensor::DemoLoc = Location(5, 2);

void DemoSensor::Run() noexcept
{
    for(size_t i = 0; i < m_numOfEvents ; ++i)
    {
        m_factory.GenrateEvent(std::make_shared<Event>(0, DemoLoc, "5:05"));
    }
}

} //namespace eventor
} //namespace smartHome