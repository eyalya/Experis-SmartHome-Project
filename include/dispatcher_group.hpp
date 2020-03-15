#ifndef DISPATCHER_GROUP_HPP
#define DISPATCHER_GROUP_HPP

#include <vector> //std::vector
#include <mutex> //std::mutex, std::guard
#include <thread> //std::thread
#include <functional> //std::hash

#include "waitable_queue.hpp" //advcpp::WaitableQ
#include "common_types.hpp" //booter::EventHandlerPtr
#include "ievent.hpp" //EventPtr
#include "ievent_handler.hpp"//IEventHandler

namespace smartHome {
namespace hub {

// using SmallSystem = std::vector;
// using EnterpriseSystem = std::vector;

using IExecutor = std::thread;

class DispatcherGroup
{
public:
    using Container = std::vector<booter::EventHandlerPtr>;

    void AddHandler(booter::EventHandlerPtr a_handler);
    bool RemoveHandler(booter::EventHandlerPtr a_handler);
    void AddEvent(EventPtr a_event);

    bool Contains(booter::EventHandlerPtr a_handler) const;

    size_t hash() const;

private:
    auto FindHandler(booter::EventHandlerPtr a_handler) const;

    void CopyHandlersContainer(Container& a_handlerContainer) const;

    void NotifyHandlers(EventPtr a_event) const;

    static const size_t DEFAULT_QUEUE_SIZE = 50;

private:
    Container m_handlers;
    IExecutor m_publisher;

    mutable advcpp::WaitableQ<EventPtr> m_eventQ;
    mutable std::mutex m_lock;
};

} // namespace hub
} // namespace smartHome

namespace std
{
    template <>
    struct hash<smartHome::hub::DispatcherGroup>
    {
        size_t operator()(const smartHome::hub::DispatcherGroup& a_dispatchGroup) const;
    };
}


#endif //DISPATCHER_GROUP_HPP