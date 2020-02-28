#include "controller_container.hpp"

using namespace std;

namespace smartHome 
{
namespace hub 
{
    
ControllerContainer::ControllerContainer(IEventController& a_controller)
: m_controllers()
{
    m_controllers.push_back(a_controller);
}

void ControllerContainer::AddController(IEventController& a_controller)
{
    m_controllers.push_back(a_controller);
}

void ControllerContainer::RemoveController(IEventController& a_controller)
{
    //TODO: settel how to find a controller 
}



} //namespace hub
} //namespace smartHome 