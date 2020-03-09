#ifndef BOOTER_HPP
#define BOOTER_HPP

#include "system_connector_api.hpp" //SystemConnectorApi
#include "thread_group.hpp" //ThreadsGroup
#include "idevice_maker.hpp" //IDeviceMaker
#include "idevice_data_factory.hpp" //IDeviceDataFactory

namespace smartHome {
namespace booter {
    
class Booter
{
public:
    Booter(SystemConnectorApi& a_connectors, IDeviceMaker& a_maker, IDeviceDataFactory& a_factory);

    void BootSystem();
    void DisconnectDevices();

private:
    SystemConnectorApi& m_connectors;
    IDeviceMaker& m_maker;
    IDeviceDataFactory& m_factory;
    hub::DeviceGroup m_deviceGroup;    
};

} //namespace booter
} //namespace smartHome

#endif //BOOTER_HPP