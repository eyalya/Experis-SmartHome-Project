#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <memory> //shared_ptr

#include "waitable_queue.hpp" //WaitableQ
#include "event.hpp" //Event
#include "thread_pool.hpp" //ThreadPool


namespace smartHome 
{
namespace hub 
{

class EventManger {
public:
    typedef std::shared_ptr<eventor::Event> EventPtr;

    EventManger(advcpp::WaitableQ<EventPtr>& a_eventQ);

    ~EventManger() = default;
    EventManger(EventManger const& a_rhs) = default;
    EventManger& operator=(EventManger const& a_rhs) = default;


private:
    advcpp::WaitableQ<EventPtr>& m_events;
    ThreadPool m_pool;
};

} //namespace hub
} //namespace smartHome 

// #include "inl/class.inl"
#endif //EVENT_MANAGER_HPP