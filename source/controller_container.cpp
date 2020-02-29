#include "controller_container.hpp"

using namespace std;

namespace smartHome 
{
namespace hub 
{
    
ControllerContainer::ControllerContainer(ControllerPtr a_controller)
: m_controllers()
{
    m_controllers.push_back(a_controller);
}

void ControllerContainer::AddController(ControllerPtr a_controller)
{
    m_controllers.push_back(a_controller);
}

void ControllerContainer::RemoveController(ControllerPtr a_controller)
{
    //TODO: settel how to find a controller 
    (void) a_controller;
}



} //namespace hub
} //namespace smartHome 