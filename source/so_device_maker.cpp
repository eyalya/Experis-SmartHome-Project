#include <memory> //std::make_shared
#include <vector> //std::vector

#include "so_device_maker.hpp"

namespace smartHome {
namespace booter {

SoDeviceMaker::SoDeviceMaker(DeviceBuilders& a_deviceBuilders)
: m_deviceBuilders(a_deviceBuilders)
{
}

void SoDeviceMaker::CreateDevices(hub::DeviceGroup& a_devices, SystemConnectorApi& a_connectors, 
                               IDeviceDataFactory& a_factory)
{
    a_factory.LoadDeviceData();

    std::vector<DeviceDataPtr> datas = a_factory.GetDeviceData();
    for(DeviceDataPtr data: datas)
    {
        a_devices.AddDevice(CreateDevice(data, a_connectors));
    }
}

DevicePtr SoDeviceMaker::CreateDevice(DeviceDataPtr a_data, SystemConnectorApi& a_connectors)
{
    if (a_data->m_type == std::string("Fire"))
    {
        DevicePtr device = m_deviceBuilders["smoke_detector"].Build(a_data, a_connectors);
        // DevicePtr device = std::make_shared<SmokeDetector>(a_data, a_connectors);
        device->Connect();
        return device;
    }
    else
    {
        DevicePtr device = m_deviceBuilders["sprinkler"].Build(a_data, a_connectors);
        device->Connect();
        return device;
    }   
}

} //namespace booter
} //namespace smartHome
