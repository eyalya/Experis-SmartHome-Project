#ifndef CONTORLLER_CONTAINER_HPP
#define CONTORLLER_CONTAINER_HPP

#include <vector> //std::vector

#include "ievent_contorller.hpp" //IEventController

namespace smartHome 
{
namespace hub 
{

class ControllerContainer {
public:
    typedef std::vector<IEventController&>::iterator iterator;

    ControllerContainer(IEventController& a_controller);

    ~ControllerContainer() = default;
    ControllerContainer(ControllerContainer const& a_rhs) = default;
    ControllerContainer& operator=(ControllerContainer const& a_rhs) = default;

    void AddController(IEventController& a_controller);
    void RemoveController(IEventController& a_controller);

    void ControllerExec();
    

private:
    std::vector<IEventController&> m_controllers;
};

} //namespace hub
} //namespace smartHome 

#endif //CONTORLLER_CONTAINER_HPP