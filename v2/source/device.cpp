#include "device.hpp"

namespace smartHome {
namespace hub {

Device::Device(std::string const& a_name, Location a_location, size_t a_hashSize)
: m_topicHandlers(a_hashSize)
, m_location(a_location)
, m_name(a_name)
{
}

void Device::RegisterToTopic(Topic a_topic, HandlerPtr a_handler)
{
    m_topicHandlers.insert(std::make_pair(a_topic, a_handler));
}

void Device::RegisterToTopic(ISubscribersRegister& a_subscriber)
{
    for (auto const& pair : m_topicHandlers)
    {
        a_subscriber.RegisterSubscriber(shared_from_this(), pair.first);
    }
}

Device::HandlerPtr Device::GetHandler(Topic a_topic)
{
    auto res = m_topicHandlers.find(a_topic);
    if(res == m_topicHandlers.end())
    {
        return 0;
    }
    return res->second;
}

std::unordered_map<Topic, Device::HandlerPtr, TopicHash> const& Device::GetTopicHandlers()
{
    return m_topicHandlers;
}

} //namespace smartHome
} //namespace hub
