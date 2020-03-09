#include <memory> //std::make_shared
#include <vector> //std::vector

#include "hardcoded_device_maker.hpp"
#include "smoke_detector.hpp" //SmokeDetector
#include "sprinkler_device.hpp" //Sprinklers

namespace smartHome {
namespace booter {

void HardCodedDeviceMaker::CreateDevices(hub::DeviceGroup& a_devices, SystemConnectorApi& a_connectors, 
                               IDeviceDataFactory& a_factory)
{
    a_factory.LoadDeviceData();

    std::vector<DeviceDataPtr> datas = a_factory.GetDeviceData();
    for(DeviceDataPtr data: datas)
    {
        //
        a_devices.AddDevice(CreateDevice(data, a_connectors));
    }
}

DevicePtr HardCodedDeviceMaker::CreateDevice(DeviceDataPtr a_data, SystemConnectorApi& a_connectors)
{
    if (a_data->m_type == std::string("Fire"))
    {
        DevicePtr device = std::make_shared<SmokeDetector>(a_data, a_connectors);
        device->Connect();
        return device;
    }
    else
    {
        DevicePtr device = std::make_shared<Sprinklers>(a_data, a_connectors);
        device->Connect();
        return device;
    }   
}

} //namespace booter
} //namespace smartHome
