#include <cassert> //assert

#include "topic_subscribers.hpp" //TopicSubscribers

namespace smartHome 
{
namespace hub 
{

void TopicSubscribers::RegisterSubscriber(IEventController& a_controller, eventor::Topic const& a_topic)
{
    Iterator iter = m_subscribers.Find(a_topic);
    if (iter == m_subscribers.End())
    {
        m_subscribers.insert(a_topic, ControllerContainer(a_controller));
    }
    else
    {
        iter->AddController(a_controller);
    }
}

void TopicSubscribers::UnRegisterSubscriber(IEventController& a_controller, eventor::Topic const& a_topic)
{
    Iterator iter = m_subscribers.Find(a_topic);

    if (iter != m_subscribers.End())
    {
        iter->RemoveController(a_controller);
    }
}

void TopicSubscribers::ExecuteTopic(eventor::Topic const& a_topic, eventor::Event a_event) const
{
    Iterator iter = m_subscribers.Find(a_topic);

    if (iter != m_subscribers.End())
    {
        iter->ControllerExec(a_event);
    }
}

};

} //namespace hub
} //namespace smartHome 
