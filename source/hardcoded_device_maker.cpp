#include <memory> //std::make_shared

#include "hardcoded_device_maker.hpp"
#include "fire_sensor.hpp"

namespace smartHome {
namespace booter {

void HardCodedDeviceMaker::CreateDevices(hub::DeviceGroup& a_devices, SystemConnectorApi& a_connectors, 
                               IDeviceDataFactory& a_factory)
{
    while (a_factory.HasMore())
    {
        a_devices.AddDevice(CreateDevice(a_factory.GetDeviceData(), a_connectors));
    }
}

DevicePtr HardCodedDeviceMaker::CreateDevice(DeviceDataPtr a_data, SystemConnectorApi& a_connectors)
{
    return  std::make_shared<FireSensor>(a_data, a_connectors);
}

} //namespace booter
} //namespace smartHome
