#ifndef BOOTER_HPP
#define BOOTER_HPP

#include "system_connector_api.hpp" //SystemConnectorApi
#include "device_group.hpp" //DeviceGroup
#include "idevice_maker.hpp" //IDeviceMaker
#include "idevice_data_factory.hpp" //IDeviceDataFactory

namespace smartHome {
namespace booter{
    
class Booter
{
public:
    Booter(SystemConnectorApi& a_connectors, IDeviceMaker& a_maker, IDeviceDataFactory& a_factory);

    void BootSystem();

private:
    SystemConnectorApi& m_connectors;
    IDeviceMaker& m_maker;
    IDeviceDataFactory& m_factory;
    hub::DeviceGroup m_group;
};

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