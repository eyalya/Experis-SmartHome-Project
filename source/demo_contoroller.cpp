#include <iostream> //std::cout

#include "demo_controller.hpp"

namespace smartHome{
namespace hub {

DemoController::DemoController(std::string const& a_name, eventor::Location a_location)
: m_location(a_location)
, m_name(a_name)
{
}

void DemoController::EventExec(EventPtr a_event)
{
    std::cout << "executed an event " << a_event->m_type << std::endl;
}

} //namespace hub
} //namespace smartHome