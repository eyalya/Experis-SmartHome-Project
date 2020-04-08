#ifndef IFIND_TOPIC_SUBSCRIBER_HPP
#define IFIND_TOPIC_SUBSCRIBER_HPP

#include <vector> //std::vector
#include <memory> //std::shared_pointer
#include <optional> //std::optional

#include "common_types.hpp" //DgPtrContainer

namespace smartHome 
{
class Topic;

namespace hub 
{
class IFindTopicSubscriber {
public:
    
    virtual ~IFindTopicSubscriber() = default;
    
    virtual std::optional<DgPtrContainer> FindTopic(Topic const& a_topic) = 0;

protected:
    IFindTopicSubscriber() = default;
    IFindTopicSubscriber(IFindTopicSubscriber const& a_rhs) = default;
    IFindTopicSubscriber& operator=(IFindTopicSubscriber const& a_rhs) = default;

};


} //namespace hub
} //namespace smartHome 

#endif //IFIND_TOPIC_SUBSCRIBER_HPP