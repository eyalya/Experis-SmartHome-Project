#include <memory> //std::make_shared

#include "publisher.hpp" 
#include "iagent.hpp" //IAgent
#include "event_base.hpp" //Topic

namespace smartHome 
{
namespace hub 
{

void Publisher::RegisterSubscriber(std::shared_ptr<IAgent> a_device, Topic const& a_topic)
{
    booter::EventHandlerPtr handler = a_device->GetHandler(a_topic);
    auto iter = m_groups.find(a_device);
    if (iter != m_groups.end())
    {
        // remove from old topic
        // add to new group by new combined topic
        // add to made events group 
    }
    else
    {
        //insert new to maps
        DgPtr newGroup = std::make_shared<DispatcherGroup>();
        newGroup->AddHandler(handler); 

        m_groups.insert({a_device, newGroup});
        m_devices.insert({newGroup, a_device});
        m_events.emplace({a_topic, DgPtrContainer({newGroup})});
    }
    

}

void Publisher::UnRegisterSubscriber(std::shared_ptr<IAgent> a_device, Topic const& a_topic)
{

}

DgPtrContainer const& Publisher::FindTopic(Topic const& a_topic)
{
    
}


} //namespace hub 
} //namespace smarthome