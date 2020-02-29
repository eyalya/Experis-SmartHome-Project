#ifndef CONTORLLER_CONTAINER_HPP
#define CONTORLLER_CONTAINER_HPP

#include <vector> //std::vector
#include <memory> //shared_ptr

#include "ievent_contorller.hpp" //IEventController
#include "event.hpp" //Event 

namespace smartHome {
namespace hub {

class ControllerContainer {
public:
    typedef std::shared_ptr<IEventController> ControllerPtr;
    typedef std::vector<ControllerPtr >::iterator iterator;

    ControllerContainer() = default;
    ControllerContainer(ControllerPtr a_controller);

    ~ControllerContainer() = default;
    ControllerContainer(ControllerContainer const& a_rhs) = default;
    ControllerContainer& operator=(ControllerContainer const& a_rhs) = default;

    void AddController(ControllerPtr a_controller);
    void RemoveController(ControllerPtr a_controller);

    void ControllerExec(std::shared_ptr<eventor::Event> a_event);

    ControllerPtr operator[](size_t a_index);
    ControllerPtr operator[](size_t a_index) const;
    size_t Size() const;
    
private:
    std::vector<ControllerPtr > m_controllers;
};

} //namespace hub
} //namespace smartHome 

#include "inl/controller_container.inl"
#endif //CONTORLLER_CONTAINER_HPP