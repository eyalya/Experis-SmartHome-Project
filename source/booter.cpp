// #include "booter.hpp"

// namespace smartHome {
// namespace booter{

// Booter::Booter(ILoader& a_loader, IRegistrator& a_registrator)
// : m_loader(a_loader)
// , m_registrator(a_registrator)
// {
// }

// void Booter::BootSystem()
// {
//     // m_loader.LoadDevices();
    
//     m_group.Foreach(DeviceRegister(m_registrator));
// }

// DeviceRegister::DeviceRegister(IRegistrator& a_registrator)
// : m_registrator(a_registrator)
// {
// }

// void DeviceRegister::operator()(std::shared_ptr<hub::Device> a_device)
// {
//     m_registrator.RegisterDevice(a_device);
// }

// }// namespace booter
// } // namespace smartHome