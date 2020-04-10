#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <unordered_map> //std::unordered_map
#include <unordered_set> //std::unordered_set
#include <set> //std::set
#include <vector> //std::vector

#include "event_base.hpp"
// #include "common_types.hpp" //DevicePtr
#include "dispatcher_group.hpp" //DispatcherGroup
#include "isubscribers_register.hpp" //ISubscribersRegister
#include "ifind_topic_subscriber.hpp" //IFindTopicSubscriber

namespace smartHome 
{
namespace hub 
{

class Publisher: public IFindTopicSubscriber, public ISubscribersRegister
{
using TopicsDispatcher = std::pair<std::set<Topic>, DgPtr>;
using DeviceKey = std::unordered_map<DevicePtr, TopicsDispatcher>;
using GroupKey = std::unordered_map<std::set<Topic>, DgPtr, SetTopicHash>;  
// using TopicCombination = std::unordered_map<std::vector<Topic>, DgPtr>; //TODO: possible not neccesasary
using Finder = std::unordered_map<Topic, DgPtrContainer, TopicHash>; //used in Find Topic

public:
    Publisher() = default;
    ~Publisher() = default;

    virtual void RegisterSubscriber(std::shared_ptr<IAgent> a_device, Topic const& a_topic);
    virtual void UnRegisterSubscriber(std::shared_ptr<IAgent> a_device, Topic const& a_topic);

    virtual std::optional<DgPtrContainer> FindTopic(Topic const& a_topic);

private:
    DeviceKey m_devices;
    GroupKey m_group;
    // TopicCombination m_dispatchers; //maybe redundant
    Finder m_finder;
};

} //namespace hub 
} //namespace smarthome
#endif //PUBLISHER_HPP