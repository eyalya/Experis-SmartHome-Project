#ifndef DEMO_CENSOR_HPP
#define DEMO_CENSOR_HPP

#include "isensor.hpp"
#include "ievent_reciver.hpp"
#include "demo_event.hpp"

namespace smartHome{
namespace eventor{

class DemoSensor : public ISensor
{
public:
    explicit DemoSensor(IEventReciver& a_reciver, Location a_censorLocation, EventType a_eventType, size_t a_numOfEvents = 30);
    ~DemoSensor() = default;

    void Run() noexcept;

private:
    Location m_location;
    EventType m_type;

    IEventReciver& m_eventReciver;
    size_t m_numOfEvents;
};

} //namespace eventor
} // namespace smartHome

#endif // !DEMO_CENSOR_HPP