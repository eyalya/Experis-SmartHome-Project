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
    auto oldDeviceIter = m_devices.find(a_device);
    std::set<Topic> topics; 
    DgPtr group = NULL;

    //inserting to devices
    if (oldDeviceIter != m_devices.end())
    {
        topics = oldDeviceIter->second.first;
    }

    topics.insert(a_topic);
    TopicsDispatcher td = std::make_pair(topics, group);
    auto mapVal = std::make_pair(a_device, td);
    auto newDeviceIter = m_devices.insert(mapVal).first; //FIXME: deal if failed to return 


    //inserting to groups
    auto groupIter = m_group.find(topics);

    if (groupIter != m_group.end())
    {
        group = groupIter->second;
    }
    else
    {
        group = std::make_shared<DispatcherGroup>();
        auto val = std::make_pair(topics, group);
        m_group.insert(val);
        
        //update finder
        for (auto &topic: topics)
        {
            auto iter = m_finder.find(topic);
            if (iter != m_finder.end())
            {
                iter->second.push_back(group);
            }
            else
            {
                auto finderVal = std::make_pair(topic, std::vector<DgPtr>{group});
                m_finder.insert(finderVal);        
            }
        }
    }
    // TODO: change all to emplace
    
    newDeviceIter->second.second = group;
    

    // remove  
    if(oldDeviceIter != m_devices.end())
    {   
        m_devices.erase(oldDeviceIter);
    }    
}

// void UpdateFinder(Topic const& a_topic, )

void Publisher::UnRegisterSubscriber(std::shared_ptr<IAgent>, Topic const&)
{

}

std::optional<DgPtrContainer> Publisher::FindTopic(Topic const& a_topic)
{
    auto iter = m_finder.find(a_topic);

    if(iter != m_finder.end())
    {
        return iter->second;
    }

    return std::nullopt;
}


} //namespace hub 
} //namespace smarthome