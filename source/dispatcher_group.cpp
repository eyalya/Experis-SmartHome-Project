#include <algorithm> //std::find, std::copy

#include "dispatcher_group.hpp"

namespace smartHome {
namespace hub {

void DispatcherGroup::AddHandler(booter::EventHandlerPtr a_handler)
{
    std::lock_guard<std::mutex> guard(m_lock);
    m_handlers.push_back(a_handler);
}

bool DispatcherGroup::RemoveHandler(booter::EventHandlerPtr a_handler)
{
    std::lock_guard<std::mutex> guard(m_lock);

    auto result = FindHandler(a_handler);
    if(result == m_handlers.end())
    {
        return false;
    }
    
    m_handlers.erase(result);
    return true;
}

void DispatcherGroup::AddEvent(EventPtr a_event)
{
    m_eventQ.Enqueue(a_event); 
}

bool DispatcherGroup::Contains(booter::EventHandlerPtr a_handler) const
{
    std::lock_guard<std::mutex> guard(m_lock);

    auto result = FindHandler(a_handler);
    if(result == m_handlers.end())
    {
        return false;
    }
    return true;
}

DispatcherGroup::Container::const_iterator DispatcherGroup::FindHandler(booter::EventHandlerPtr a_handler) const
{
    return std::find(m_handlers.begin(), m_handlers.end(), a_handler);
}

void DispatcherGroup::NotifyHandlers(EventPtr a_event) const
{
    EventPtr event;
    m_eventQ.Dequeue(event);

    Container handlersCopy;
    CopyHandlersContainer(handlersCopy);

    for (auto &&handler : handlersCopy)
    {
        handler->Handle(a_event);
    }
}

void DispatcherGroup::CopyHandlersContainer(Container& a_handlerContainer) const
{
    std::lock_guard<std::mutex> guard(m_lock);
    a_handlerContainer = m_handlers;
    // std::copy(m_handlers.begin(), m_handlers.end(). a_handlerContainer.begin());
}

}//namespace hub
}//namespace smartHome 

namespace std{

size_t hash<smartHome::hub::DispatcherGroup>::operator()(const smartHome::hub::DispatcherGroup& a_dispatchGroup) const
{
    size_t a = reinterpret_cast<size_t>(&a_dispatchGroup);
    return std::hash<size_t>{}(a);
}

}// namespace std