#include <iostream> //std::cout

#include "demo_device.hpp"
#include "thread.hpp" //Thread

namespace smartHome {
namespace hub {

DemoDevice::DemoDevice(std::string const& a_name, Location a_location)
: Device(a_name, a_location)
{
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