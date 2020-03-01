#ifndef DEMO_CENSOR_HPP
#define DEMO_CENSOR_HPP

#include "isensor.hpp"
#include "Ievent_factory.hpp"
#include "event.hpp" // location
#include "light_event_factory.hpp"

namespace smartHome{
namespace eventor{

class DemoSensor : public ISensor
{
public:
    explicit DemoSensor(IEventFactory& a_factory, size_t a_numOfEvents = 30);
    ~DemoSensor() = default;

    void Run() noexcept;

private:
    static const EventType DemoType = 0;
    static const Location DemoLoc;

    IEventFactory& m_factory;
    size_t m_numOfEvents;
};

} //namespace eventor
} // namespace smartHome

#endif // !DEMO_CENSOR_HPP