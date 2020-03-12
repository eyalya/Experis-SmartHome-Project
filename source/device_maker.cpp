#include <memory> //std::make_shared
#include <vector> //std::vector
#include <map>

#include "device_maker.hpp"

namespace smartHome {
namespace booter {

DeviceMaker::DeviceMaker(DeviceBuilders& a_deviceBuilders)
: m_deviceBuilders(a_deviceBuilders)
{
}

void DeviceMaker::CreateDevices(hub::DeviceGroup& a_devices, SystemConnectorApi& a_connectors, 
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




DevicePtr DeviceMaker::CreateDevice(DeviceDataPtr a_data, SystemConnectorApi& a_connectors)
{
    //TODO: hardcoded? hardeCoded?? HARDCODED????
    //std::map<std::string, std::string> soMap = { {"Fire", "smoke_detector"}, {"Fire??", "sprinkler"} };
    
    if (a_data->m_type == std::string("Fire"))
    {
        auto b = m_deviceBuilders["smoke_detector"];
        DevicePtr device = b->Build(a_data, a_connectors);
        // DevicePtr device = std::make_shared<SmokeDetector>(a_data, a_connectors);
        device->Connect();
        return device;
    }
    else
    {
        DevicePtr device = m_deviceBuilders["sprinkler"]->Build(a_data, a_connectors);
        device->Connect();
        return device;
    }   
}

} //namespace booter
} //namespace smartHome
