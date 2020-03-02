#ifndef IFIND_TOPIC_SUBSCRIBER_HPP
#define IFIND_TOPIC_SUBSCRIBER_HPP

#include "event_base.hpp" //Topic
#include "device_group.hpp" //DeviceGroup

namespace smartHome 
{
namespace hub 
{

class IFindTopicSubscriber {
public:
    
    virtual ~IFindTopicSubscriber() = default;
    
    virtual DeviceGroup const& FindTopic(Topic const& a_topic) = 0;

protected:
    IFindTopicSubscriber() = default;
    IFindTopicSubscriber(IFindTopicSubscriber const& a_rhs) = default;
    IFindTopicSubscriber& operator=(IFindTopicSubscriber const& a_rhs) = default;

};


} //namespace hub
} //namespace smartHome 

#endif //IFIND_TOPIC_SUBSCRIBER_HPP