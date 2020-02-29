#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <memory> //shared_ptr

#include "event.hpp" //Event
#include "events_pool.hpp" //EventsPool


namespace smartHome 
{
namespace hub 
{

class EventManger {
public:
    EventManger(EventsPool& a_eventsPool);

    ~EventManger() = default;
    EventManger(EventManger const& a_rhs) = default;
    EventManger& operator=(EventManger const& a_rhs) = default;

    void Resume();
    void ShutDown();

private:
    EventsPool& m_eventsPool;
};

} //namespace hub
} //namespace smartHome 

#endif //EVENT_MANAGER_HPP