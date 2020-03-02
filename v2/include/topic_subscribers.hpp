#ifndef TOPIC_SUBSCRIBERS_HPP
#define TOPIC_SUBSCRIBERS_HPP

#include <string> //std::string
#include <memory> //std::shared_ptr

#include "event_base.hpp" //Topic
#include "hash_table.hpp" //HashTable
#include "ifind_topic_subscriber.hpp" //IFindTopicSubscriber
#include "isubscribers_register.hpp" //ISubscribersRegister
#include "device_group.hpp" //DeviceGroup


namespace smartHome {
namespace hub {

class TopicSubscribers: public IFindTopicSubscriber, public ISubscribersRegister {
public:
    TopicSubscribers() = default;

    ~TopicSubscribers() = default;
    TopicSubscribers(TopicSubscribers const& a_rhs) = default;
    TopicSubscribers& operator=(TopicSubscribers const& a_rhs) = default;

    virtual void RegisterSubscriber(std::shared_ptr<Device> a_device, Topic const& a_topic);
    virtual void UnRegisterSubscriber(std::shared_ptr<Device> a_device, Topic const& a_topic);

    virtual DeviceGroup const& FindTopic(Topic const& a_topic);

private:
    typedef std::string TopicId;
    typedef advcpp::HashTable<TopicId, DeviceGroup>::iterator iterator;
    typedef advcpp::HashTable<TopicId, DeviceGroup>::const_iterator const_iterator;

private:
    advcpp::HashTable<TopicId, DeviceGroup> m_subscribers;
};


} //namespace hub
} //namespace smartHome 


#endif //TOPIC_SUBSCRIBERS_HPP