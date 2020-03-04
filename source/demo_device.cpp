#include <iostream> //std::cout
#include <vector> //std::vector

#include "demo_device.hpp"
#include "thread.hpp" //Thread

namespace smartHome {
namespace hub {

DemoDevice::DemoDevice(std::string const& a_name, Location a_location)
: Device(a_name, a_location)
{   
    RegisterHandlers();
}

void DemoDevice::RegisterHandlers()
{
    std::vector<Topic> topics;
    CreateTopics(topics, nTopics);

    for (size_t i = 0; i < nTopics; ++i)
    {
        Device::m_topicHandlers.emplace(topics[i], std::make_shared<DemoHandler>());
    }
}

void DemoDevice::CreateTopics(std::vector<Topic>& a_topics, size_t a_nTopics)
{
    EventType type = "counter";
    Floor floor = 0;
    Room room = 0;
    
    while(a_nTopics --> 0)
    {
        // cout << "create topic: 1" << floor << room << endl;
        a_topics.push_back(Topic(type, Location(floor, room)));
        ++room;            
        ++floor;
    }
}

DemoHandler::DemoHandler()
: m_nRuns(0)
{
}

void DemoHandler::Handle(EventPtr a_event)
{
    (void) a_event;
    ++m_nRuns;
}

size_t DemoHandler::GetNRuns() const
{
    return m_nRuns;
}

ShutDownHandler::ShutDownHandler(EventManager& a_manager)
: m_manager(a_manager)
{
}

void ShutDownHandler::Handle(EventPtr a_event)
{
    (void) a_event;
    m_manager.Pause();
}

} //namespace hub
} //namespace smartHome