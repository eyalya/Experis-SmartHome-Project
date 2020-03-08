#include "booter.hpp"

namespace smartHome {
namespace booter{

Booter::Booter(SystemConnectorApi& a_connectors, IDeviceMaker& a_maker, IDeviceDataFactory& a_factory)
: m_connectors(a_connectors)
, m_maker(a_maker)
, m_factory(a_factory)
, m_group()
{
}

void Booter::BootSystem()
{
    m_maker.CreateDevices(m_group, m_connectors, m_factory);
}

// DeviceRegister::DeviceRegister(IRegistrator& a_registrator)
// : m_registrator(a_registrator)
// {
// }

// void DeviceRegister::operator()(std::shared_ptr<hub::BaseAgent> a_device)
// {
//     m_registrator.RegisterDevice(a_device);
// }

}// namespace booter
} // namespace smartHome