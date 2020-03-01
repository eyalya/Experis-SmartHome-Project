#ifndef LIGHT_EVENT_FACTORY
#define LIGHT_EVENT_FACTORY

#include "Ievent_factory.hpp"
#include "waitable_queue.hpp" 
#include "isensor.hpp"
#include "events_pool.hpp" 
#include "thread.hpp"

namespace smartHome {
namespace eventor {

class LightEventFactory : public IEventFactory
{
public:
    explicit LightEventFactory(hub::EventsPool& a_eventPool);
    LightEventFactory(LightEventFactory const& a_other) = default;
    virtual ~LightEventFactory() = default;
    
    LightEventFactory& operator=(LightEventFactory const& a_other) = default;

    virtual void GenrateEvent(EventPtr a_event);

private:
    hub::EventsPool & m_events;
};

} // namespace eventor
} // namespace smartHome

#endif //LIGHT_EVENT_FACTORY