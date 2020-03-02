#include "basic_loader.hpp"

#include "device.hpp"

namespace smartHome {
namespace booter {
    
BasicLoader::BasicLoader(hub::DeviceGroup& a_devices)
: m_devices(a_devices)
{
}

void BasicLoader::LoadDevices()
{
    hub::Device device("demo device", Location(2, 5));
    // device.RegisterToTopic()
}

} // namespace booter
} // namespace smartHome
