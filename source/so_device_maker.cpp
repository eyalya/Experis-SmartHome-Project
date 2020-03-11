#include <memory> //std::make_shared
#include <vector> //std::vector
#include <map>

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
    //TODO: std::vector<DeviceDataPtr> afistFullOfDatas = a_deviceConfig.load()  from class DeviceConfigFactory
    a_factory.LoadDeviceData();

    std::vector<DeviceDataPtr> afistFullOfDatas = a_factory.GetDeviceData();
    for(auto& data: afistFullOfDatas)
    {
        const auto& dev = CreateDevice(data, a_connectors);
        a_devices.AddDevice(dev);
    }
}




DevicePtr SoDeviceMaker::CreateDevice(DeviceDataPtr a_data, SystemConnectorApi& a_connectors)
{
    //TODO: hardcoded? hardeCoded?? HARDCODED????
    //std::map<std::string, std::string> soMap = { {"Fire", "smoke_detector"}, {"Fire??", "sprinkler"} };
    
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
