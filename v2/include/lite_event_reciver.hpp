#ifndef LIGHT_EVENT_FACTORY
#define LIGHT_EVENT_FACTORY

#include "ievent_reciver.hpp"
#include "waitable_queue.hpp" 
#include "isensor.hpp"
#include "events_pool.hpp" 
#include "thread.hpp"

namespace smartHome {
namespace eventor {

class LiteEventReciver : public IEventReciver
{
public:
    explicit LiteEventReciver(hub::EventsPool& a_eventPool);
    LiteEventReciver(LiteEventReciver const& a_other) = default;
    virtual ~LiteEventReciver() = default;
    
    LiteEventReciver& operator=(LiteEventReciver const& a_other) = default;

    virtual void GenrateEvent(EventPtr a_event);

private:
    hub::EventsPool & m_events;
};

} // namespace eventor
} // namespace smartHome

#endif //LIGHT_EVENT_FACTORY