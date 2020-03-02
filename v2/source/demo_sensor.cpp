#include <memory>

#include "demo_sensor.hpp"

namespace smartHome {
namespace eventor {

DemoSensor::DemoSensor(IEventReciver& a_reciver, Location a_censorLocation,
                     EventType a_eventType, size_t a_numOfEvents)
: 
, m_location(a_censorLocation)
, m_type(a_eventType)
, m_eventReciver(a_reciver)
, m_numOfEvents(a_numOfEvents)
{
}

void DemoSensor::Run() noexcept
{
    for(size_t i = 0; i < m_numOfEvents ; ++i)
    {
        m_eventReciver.RecvEvent(
            std::make_shared<DemoEvent>(m_type, m_location, "payload"));
    }
}

} //namespace eventor
} //namespace smartHome