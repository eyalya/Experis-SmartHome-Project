#include <iostream> //std::cout

#include "demo_controller.hpp"

namespace smartHome{
namespace hub {

DemoController::DemoController(std::string const& a_name, eventor::Location a_location)
: m_name(a_name)
, m_location(a_location)
{
}

void DemoController::EventExec(EventPtr a_event)
{
    std::cout << "executed an event";
}

} //namespace hub
} //namespace smartHome