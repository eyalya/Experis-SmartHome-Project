#ifndef DISPATCHER_GROUP_HPP
#define DISPATCHER_GROUP_HPP

#include <vector> //std::vector
#include <mutex> //std

#include "waitable_queue.hpp" 
#include "common_types.hpp" //booter::EventHandlerPtr

namespace smartHome {
namespace hub {

template <typename Executor>
class DispatcherGroup
{
public:
    DispatcherGroup();

    void AddHandler(booter::EventHandlerPtr a_handler);
    bool RemoveHandler(booter::EventHandlerPtr a_handler);
    void AddEvent(EventPtr a_event);

    bool Contains(booter::EventHandlerPtr a_handler) const;

    size_t Hash();

private:
    static const size_t DEFAULT_QUEUE_SIZE = 50;
    static const size_t DEFAULT_QUEUE_SIZE = 50;

private:
    advcpp::WaitableQ<EventPtr> m_eventQ;
    std::vector<booter::EventHandlerPtr> m_handlers;
    Executor m_publisher;

    mutabale std::mutex m_lock;
};
    
} // namespace hub
} // namespace smartHome

#include "inl/dispatcher_group.inl"

#endif //DISPATCHER_GROUP_HPP