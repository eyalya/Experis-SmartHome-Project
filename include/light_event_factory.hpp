#ifndef LIGHT_EVENT_FACTORY
#define LIGHT_EVENT_FACTORY

#include "Ievent_factory.hpp"
#include "waitable_queue.hpp" //advcpp::WaitableQ
#include "thread.hpp"

namespace smartHome {
namespace eventor {

class LightEventFactory : public IEventFactory
{
public:

    explicit LightEventFactory(advcpp::WaitableQ<EventPtr>& a_eventQ);
    LightEventFactory(LightEventFactory const& a_other) = default;
    virtual ~LightEventFactory() = default;
    
    LightEventFactory& operator=(LightEventFactory const& a_other) = default;

    virtual void GenrateEvent(EventPtr a_event);

private:
    advcpp::WaitableQ<EventPtr>& m_events;
};

class DemoSensor : public advcpp::IRunnable
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

} // namespace eventor
} // namespace smartHome

#endif //LIGHT_EVENT_FACTORY