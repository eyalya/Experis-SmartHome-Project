#include <algorithm> //std::for_each
#include <utility> //std::pair

#include "basic_registrator.hpp"


namespace smartHome {
namespace booter{

BasicRegistrator::BasicRegistrator(hub::ISubscribersRegister& a_subRegister)
: m_subRegister(a_subRegister)
{
}

void BasicRegistrator::RegisterDevice(std::shared_ptr<Device> a_device)
{
    auto iter = a_device->GetTopicHandlers().begin();
    const auto end = a_device->GetTopicHandlers().end();

    while (iter != end)
    {
        m_subRegister.RegisterSubscriber(a_device, iter->first);
        ++iter;
    }
    // using HandlePtr = std::shared_ptr<hub::IEventHandler>;
    // using MapPair = std::pair<Topic, HandlePtr>;
    // std::for_each(iter, end, [m_subRegister& ,a_device](MapPair a_item){m_subRegister.RegisterSubscriber(a_device, a_item->first);});
}


} // namespace booter
} // namespace smartHome