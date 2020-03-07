#include <memory> //make_shared

#include "device_data_factory.hpp"
#include "device.hpp" //DeviceData

namespace smartHome {
namespace booter {

DeviceDataPtr DeviceDataFactory::GetDeviceData()
{
    return std::make_shared<DeviceData>("temp", Location (1,1));
}

bool DeviceDataFactory::HasMore()
{
    static size_t nLoops = 1;
    while(nLoops > 0)
    {
        return true;
    }
    return false;
}


} // namespace booter
} // namespace smartHome
