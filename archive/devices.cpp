#include "devices.hpp"

namespace smartHome {
namespace hub {

BaseAgent::BaseAgent(std::string const& a_name, Location a_location, size_t a_hashSize)
: m_topicHandlers(a_hashSize)
, m_location(a_location)
, m_name(a_name)
{
}

void BaseAgent::RegisterHandlerToTopic(Topic a_topic, HandlerPtr a_handler)
{
    m_topicHandlers.insert(std::make_pair(a_topic, a_handler));
}

void BaseAgent::SubscribeTopics(ISubscribersRegister& a_subscriber)
{
    for (auto const& pair : m_topicHandlers)
    {
        a_subscriber.RegisterSubscriber(shared_from_this(), pair.first);
    }
}

BaseAgent::HandlerPtr BaseAgent::GetHandler(Topic a_topic)
{
    auto res = m_topicHandlers.find(a_topic);
    if(res == m_topicHandlers.end())
    {
        return 0;
    }
    return res->second;
}

std::unordered_map<Topic, BaseAgent::HandlerPtr, TopicHash> const& BaseAgent::GetTopicHandlers()
{
    return m_topicHandlers;
}

} //namespace smartHome
} //namespace hub
