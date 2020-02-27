#include "controller_container.hpp"

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
    iterator iter = m_controllers.find()
    m_controllers.erase(a_controller);
}




} //namespace hub
} //namespace smartHome 

#endif //CONTORLLER_CONTAINER_HPP