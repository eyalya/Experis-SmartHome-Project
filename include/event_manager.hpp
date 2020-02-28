#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <memory> //shared_ptr

#include "event.hpp" //Event
#include "thread_pool.hpp" //ThreadPool


namespace smartHome 
{
namespace hub 
{

class EventManger {
public:
    EventManger(advcpp::ThreadPool<>& a_eventsPool);

    ~EventManger() = default;
    EventManger(EventManger const& a_rhs) = default;
    EventManger& operator=(EventManger const& a_rhs) = default;

    void Resume();
    void ShutDown();

private:
    advcpp::ThreadPool<>& m_eventsPool;
};

} //namespace hub
} //namespace smartHome 

#endif //EVENT_MANAGER_HPP