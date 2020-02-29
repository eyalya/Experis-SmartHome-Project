#include <iostream> //std::cout

#include "demo_controller.hpp"

namespace smartHome{
namespace hub {

DemoController::DemoController(std::string const& a_name, eventor::Location a_location)
: m_location(a_location)
, m_name(a_name)
, m_nRuns(0)
{
}

void DemoController::EventExec(EventPtr a_event)
{
    (void) a_event;
    ++m_nRuns;
}

size_t DemoController::GetNRuns() const
{
    return m_nRuns;
}

} //namespace hub
} //namespace smartHome