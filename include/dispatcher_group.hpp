#ifndef DISPATCHER_GROUP_HPP
#define DISPATCHER_GROUP_HPP

#include <vector> //std::vector
#include <mutex> //std::mutex, std::guard
#include <thread> //std::thread

#include "waitable_queue.hpp" 
#include "common_types.hpp" //booter::EventHandlerPtr

namespace smartHome {
namespace hub {

// using SmallSystem = std::vector;
// using EnterpriseSystem = std::vector;

using IExecuter = std::thread;

class DispatcherGroup
{
public:
    void AddHandler(booter::EventHandlerPtr a_handler);
    bool RemoveHandler(booter::EventHandlerPtr a_handler);
    void AddEvent(EventPtr a_event);

    bool Contains(booter::EventHandlerPtr a_handler) const;

    size_t hash();

private:
    static const size_t DEFAULT_QUEUE_SIZE = 50;

private:
    advcpp::WaitableQ<EventPtr> m_eventQ;
    std::vector<booter::EventHandlerPtr> m_handlers;
    IExecuter m_publisher;

    mutable std::mutex m_lock;
};
    
} // namespace hub
} // namespace smartHome

#endif //DISPATCHER_GROUP_HPP