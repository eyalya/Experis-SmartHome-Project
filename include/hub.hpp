#ifndef HUB_HPP
#define HUB_HPP

#include "events_pool.hpp"
#include "event_manager.hpp"
#include "light_event_factory.hpp"
#include "booter.hpp"
#include "topic_subscribers.hpp" 

namespace smartHome{
namespace hub {

class Hub
{
public:
    Hub();
    ~Hub();

    void Run();

private:
    TopicSubscribers m_subscribers;
    eventor::LightEventFactory m_factory;
    Booter m_systemBooter;
    EventsPool m_eventsPool;
    EventManager m_eventManager;
};

} //namespace hub
} //namespace smartHome

#endif // !HUB_HPP