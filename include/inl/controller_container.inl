#ifndef CONTORLLER_CONTAINER_INL
#define CONTORLLER_CONTAINER_INL

namespace smartHome 
{
namespace hub 
{


inline void ControllerContainer::ControllerExec(std::shared_ptr<eventor::Event> a_event)
{
    iterator controller = m_controllers.begin();
    iterator end = m_controllers.end();

    while (controller != end)
    {
        IEventController* cont = controller->get();
        cont->EventExec(a_event);
        ++controller;
    }
}

inline size_t ControllerContainer::Size() const
{
    return m_controllers.size();
}

inline ControllerContainer::ControllerPtr ControllerContainer::operator[](size_t a_index)
{
    return m_controllers.operator[](a_index);
}

inline ControllerContainer::ControllerPtr ControllerContainer::operator[](size_t a_index) const
{
    return m_controllers.operator[](a_index);
}

} //namespace hub
} //namespace smartHome 

#endif //CONTORLLER_CONTAINER_INL