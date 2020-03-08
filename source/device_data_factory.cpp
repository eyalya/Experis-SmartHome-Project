#include <memory> //make_shared

#include "device_data_factory.hpp"
#include "device.hpp" //DeviceData

namespace smartHome {
namespace booter {

std::vector<DeviceDataPtr> const& DeviceDataFactory::GetDeviceData()
{
    return a_datas;
}

void DeviceDataFactory::LoadDeviceData()
{
    const size_t nPerDevice = 10;
    CreateFireSensorData(nPerDevice);
    CreateSprinklerData(nPerDevice);
}

void DeviceDataFactory::CreateFireSensorData(size_t a_nTopics)
{
    EventType type = "FireSensor";
    Floor floor = 0;
    Room room = 0;
    
    while(a_nTopics --> 0)
    {
        a_datas.push_back(std::make_shared<DeviceData>("Fire", Location (floor, room)));
        ++room;            
        ++floor;
    }
}

void DeviceDataFactory::CreateSprinklerData(size_t a_nTopics)
{
    EventType type = "Sprinkler";
    Floor floor = 0;
    Room room = 0;
    
    while(a_nTopics --> 0)
    {
        a_datas.push_back(std::make_shared<DeviceData>("Sprinkler", Location (floor, room)));
        ++room;            
        ++floor;
    }
}

} // namespace booter
} // namespace smartHome
