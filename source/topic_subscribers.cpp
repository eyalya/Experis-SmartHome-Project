#include "topic_subscribers.hpp" //TopicSubscribers

namespace smartHome 
{
namespace hub 
{

void TopicSubscribers::RegisterSubscriber(IEventController& a_controller, Topic const& a_topic)
{
    Iterator iter = m_subscribers.Find(a_topic);
    if (iter == m_subscribers.End())
    {
        CreateControllerContainer(a_topic, a_controller);
    }
    else
    {
        CreateControllerContainer(*iter, a_controller);
    }
}

void TopicSubscribers::CreateControllerContainer(a_topic, a_controller)
{
    m_subscribers.Insert(a_topic, ControllerContainer() a_controller)
}

void TopicSubscribers::CreateControllerContainer(*iter, a_controller)
{

}

void TopicSubscribers::UnRegisterSubscriber(IEventController& a_controller, Topic const& a_topic)
{

}

void TopicSubscribers::ExecuteTopic(eventor::Topic const& a_topic) const
{

}

};

} //namespace hub
} //namespace smartHome 
