#include "booter.hpp"

namespace smartHome {
namespace booter{

Booter::Booter(ILoader& a_loader, IRegistrator& a_registrator)
: m_loader(a_loader)
, m_registrator(a_registrator)
{
}

void Booter::BootSystem()
{
    a_loader.LoadDevices();
    
    m_group.ForEach(RegisterDevice(m_registrator));
}

DeviceRegister::DeviceRegister(IRegistrator& a_registrator)
: m_registrator(a_registrator)
{
}

void DeviceRegister::operator()(hub::Device const& a_device)
{
    m_registrator(a_device);
}

}// namespace booter
} // namespace smartHome