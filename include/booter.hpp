#ifndef BOOTER_HPP
#define BOOTER_HPP

#include "iregistrator.hpp"
#include "system_connector_api.hpp"
#include "device_group.hpp"
#include "device.hpp"
namespace smartHome {
namespace booter{
    
// class Booter
// {
// public:
//     Booter(ILoader& a_loader, IRegistrator& a_registrator);

//     void BootSystem();

// private:
//     ILoader& m_loader;
//     IRegistrator& m_registrator;
//     hub::DeviceGroup m_group;
// };

// class DeviceRegister
// {
// public:
//     DeviceRegister(IRegistrator& a_registrator);

//     void operator()(std::shared_ptr<hub::Device> a_device);

// private: 
//     IRegistrator& m_registrator;
// };


} //namespace booter
} //namespace smartHome
#endif //BOOTER_HPP