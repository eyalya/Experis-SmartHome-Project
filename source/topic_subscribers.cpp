#include <cassert> //assert

#include "topic_subscribers.hpp" //TopicSubscribers

namespace smartHome {
namespace hub {

void TopicSubscribers::RegisterSubscriber(std::shared_ptr<BaseAgent> a_device, Topic const& a_topic)
{
    iterator iter = m_subscribers.Find(a_topic.m_id);
    if (iter == m_subscribers.End())
    {
        DeviceGroup deviceGroup(a_device);
        m_subscribers.Insert(a_topic.m_id, deviceGroup);
    }
    else
    {
        iter->m_value.AddDevice(a_device);
    }
}

void TopicSubscribers::UnRegisterSubscriber(std::shared_ptr<BaseAgent> a_device, Topic const& a_topic)
{
    iterator iter = m_subscribers.Find(a_topic.m_id);

    if (iter != m_subscribers.End())
    {
        iter->m_value.RemoveDevice(a_device);
    }
}

// DeviceGroup const& TopicSubscribers::FindTopic(Topic const& a_topic)
// {
//     iterator iter = m_subscribers.Find(a_topic.m_id);

//     if (iter != m_subscribers.End())
//     {
//         return iter->m_value;
//     }
//     //TODO: return if not 
//     return iter->m_value;
// }

} //namespace hub
} //namespace smartHome 
