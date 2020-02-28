#ifndef CONTORLLER_CONTAINER_HPP
#define CONTORLLER_CONTAINER_HPP

#include <vector> //std::vector
#include <memory> //shared_ptr

#include "ievent_contorller.hpp" //IEventController

namespace smartHome 
{
namespace hub 
{

class ControllerContainer {
public:
    typedef std::vector<std::shared_ptr<IEventController> >::iterator iterator;

    ControllerContainer() = default;
    ControllerContainer(IEventController& a_controller);

    ~ControllerContainer() = default;
    ControllerContainer(ControllerContainer const& a_rhs) = default;
    ControllerContainer& operator=(ControllerContainer const& a_rhs) = default;

    void AddController(IEventController& a_controller);
    void RemoveController(IEventController& a_controller);

    template <typename Context>
    void ControllerExec(Context a_contex);

    size_t Size() const;
    
private:
    std::vector<std::shared_ptr<IEventController> > m_controllers;
};

} //namespace hub
} //namespace smartHome 

#include "inl/controller_container.inl"
#endif //CONTORLLER_CONTAINER_HPP