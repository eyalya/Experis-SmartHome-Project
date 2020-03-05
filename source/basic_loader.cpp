#include <memory> //std::shared_ptr

#include "demo_config_file.hpp" 
#include "basic_loader.hpp"
#include "device.hpp"
#include "demo_device.hpp" //DemoDevice

namespace smartHome {
namespace booter {
    
BasicLoader::BasicLoader(hub::DeviceGroup& a_devices, eventor::IEventStoreRemover& a_storeRemover)
: m_devices(a_devices)
, m_storeRemover(a_storeRemover)
{
}

void BasicLoader::LoadDevices()
{
    using namespace std;

    //TODO: change to load from file 
    const size_t nDevices = 100;
    
    CreateDevices(m_devices, nDevices);
    // CreateSensors(m_sensors, m_storeRemover);
}


} // namespace booter
} // namespace smartHome
