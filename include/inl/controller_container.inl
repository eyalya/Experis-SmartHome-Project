#ifndef CONTORLLER_CONTAINER_INL
#define CONTORLLER_CONTAINER_INL

namespace smartHome 
{
namespace hub 
{


template <typename Context>
void ControllerContainer::ControllerExec(Context a_contex)
{
    iterator controller = m_controllers.begin();
    iterator end = m_controllers.end();

    while (controller != end)
    {
        //TODO: controller->Execute(a_contex);
    }
}

inline size_t ControllerContainer::Size() const
{
    return m_controllers.size();
}

} //namespace hub
} //namespace smartHome 

#endif //CONTORLLER_CONTAINER_INL