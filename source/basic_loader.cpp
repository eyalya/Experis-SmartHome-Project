#include <memory> //std::shared_ptr

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
    using namespace std;

    m_devices.AddDevice(make_shared<hub::DemoDevice>("demo device", Location(1, 1)));
}

} // namespace booter
} // namespace smartHome
