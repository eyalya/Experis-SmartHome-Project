#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <unordered_map> //std::unordered_map
#include <unordered_set> //std::unordered_set

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
using GroupByDevice = std::unordered_map<DevicePtr, DgPtr>;
using DeviceByGroup = std::unordered_map<DgPtr, DevicePtr>;
using GroupContByEvents = std::unordered_map<EventType, DgPtrContainer>;

public:
    Publisher(/* args */) = default;
    ~Publisher() = default;

    virtual void RegisterSubscriber(std::shared_ptr<IAgent> a_device, Topic const& a_topic);
    virtual void UnRegisterSubscriber(std::shared_ptr<IAgent> a_device, Topic const& a_topic);

    virtual DgPtrContainer const& FindTopic(Topic const& a_topic);

private:
    GroupByDevice m_groups;
    DeviceByGroup m_devices;
    GroupContByEvents m_events;
};

} //namespace hub 
} //namespace smarthome
#endif //PUBLISHER_HPP