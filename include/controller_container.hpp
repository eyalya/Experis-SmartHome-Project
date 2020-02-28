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

    template <typename Context>
    void ControllerExec(Context a_contex);

    size_t Size() const;
    
private:
    std::vector<IEventController&> m_controllers;
};

inline size_t ControllerContainer::Size() const
{
    return m_controllers.size();
}

} //namespace hub
} //namespace smartHome 

#include "inl/controller_container.inl"
#endif //CONTORLLER_CONTAINER_HPP