#include <algorithm> //std::for_each

#include "basic_registrator.hpp"


namespace smartHome {
namespace booter{

BasicRegistrator::BasicRegistrator(hub::ISubscribersRegister& a_subRegister)
: m_subRegister(a_subRegister)
{
}

void BasicRegistrator::RegisterDevice(std::shared_ptr<hub::Device> a_device)
{
    auto iter = a_device->GetTopicHandlers().begin();
    const auto end = a_device->GetTopicHandlers().end();
    while (iter != end)
    {
        m_subRegister.RegisterSubscriber(a_device, iter->first);
        ++iter;
    }
}


} // namespace booter
} // namespace smartHome