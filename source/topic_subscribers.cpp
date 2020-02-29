#include <cassert> //assert

#include "topic_subscribers.hpp" //TopicSubscribers

namespace smartHome 
{
namespace hub 
{

void TopicSubscribers::RegisterSubscriber(std::shared_ptr<IEventController> a_controller, eventor::Topic const& a_topic)
{
    iterator iter = m_subscribers.Find(a_topic.m_id);
    if (iter == m_subscribers.End())
    {
        ControllerContainer cont(a_controller);
        m_subscribers.Insert(a_topic.m_id, cont);
    }
    else
    {
        iter->m_value.AddController(a_controller);
    }
}

void TopicSubscribers::UnRegisterSubscriber(std::shared_ptr<IEventController> a_controller, eventor::Topic const& a_topic)
{
    iterator iter = m_subscribers.Find(a_topic.m_id);

    if (iter != m_subscribers.End())
    {
        iter->m_value.RemoveController(a_controller);
    }
}

void TopicSubscribers::ExecuteTopic(eventor::Topic const& a_topic, std::shared_ptr<eventor::Event> a_event)
{
    iterator iter = m_subscribers.Find(a_topic.m_id);

    if (iter != m_subscribers.End())
    {
        iter->m_value.ControllerExec(a_event);
    }
}

} //namespace hub
} //namespace smartHome 
