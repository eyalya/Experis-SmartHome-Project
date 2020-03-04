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

ShutDownHandler::ShutDownHandler(std::atomic<bool>& a_state)
: m_state(a_state)
{
}

void ShutDownHandler::Handle(EventPtr a_event)
{
    (void) a_event;
    m_state = false;
}

} //namespace hub
} //namespace smartHome