#include <iostream> //std::cout
#include <vector> //std::vector

#include "demo_device.hpp"
#include "thread.hpp" //Thread
#include "demo_config_file.hpp" //CreateTopic

namespace smartHome {
namespace hub {

DemoDevice::DemoDevice(std::string const& a_name, Location a_location)
: BaseAgent(a_name, a_location)
{   
    RegisterHandlers();
}

void DemoDevice::RegisterHandlers()
{
    std::vector<Topic> topics;
    booter::CreateTopics(topics, nTopics);

    for (size_t i = 0; i < nTopics; ++i)
    {
        BaseAgent::m_topicHandlers.emplace(topics[i], std::make_shared<DemoHandler>());
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