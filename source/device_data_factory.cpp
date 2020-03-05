#include <memory> //make_shared

#include "device_data_factory.hpp"
#include "device.hpp" //DeviceData

namespace smartHome {
namespace booter {

DeviceDataPtr DeviceDataFactory::GetDeviceData()
{
    return make_shared<DeviceData>()
}

bool DeviceDataFactory::HasMore()
{
    return true;    
}


} // namespace booter
} // namespace smartHome
