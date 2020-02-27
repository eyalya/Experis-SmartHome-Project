#ifndef LIGHT_EVENT_FACTORY
#define LIGHT_EVENT_FACTORY

#include <memory> //std::shared_ptr

#include "Ievent_factory.hpp"
#include "waitable_queue.hpp" //advcpp::WaitableQ
#include "thread.hpp"

namespace smartHome {
namespace eventor {

class LightEventFactory : public IEventFactory
{
public:
    typedef std::shared_ptr<Event> EventPtr;

    LightEventFactory(advcpp::WaitableQ<EventPtr>& a_eventQ);
    LightEventFactory(LightEventFactory const& a_other) = default;
    virtual ~LightEventFactory() = default;
    
    LightEventFactory& operator=(LightEventFactory const& a_other) = default;

    virtual void GenrateEvent(EventPtr a_event);

private:
    advcpp::WaitableQ<EventPtr>& m_events;
};

class DemoCensor : 
{
public:
    DemoCensor(IEventFactory& a_factory);
    ~DemoCensor() = default;

    void DemoEvent();

private:
    IEventFactory& m_factory;
};

} // namespace eventor
} // namespace smartHome

#endif //LIGHT_EVENT_FACTORY