#include <functional>

#include "so_device_registrator.hpp"

namespace smartHome {
namespace booter {

//void RegisterSmokeDetectorBuilder(DeviceBuilders& a_builders)

std::string const SODeviceRegistrator::registerFuncName = "RegistrateBuilder";


void SODeviceRegistrator::Register(DeviceType const& a_type, DeviceBuilders& a_builders)
{
    std::string soLib(a_type + ".so");
    m_loaders.emplace_back(soLib);
    auto& handler = m_loaders.back();   
    auto rf = handler.GetFunc<void(DeviceBuilders&)>(registerFuncName.c_str());    
    rf(a_builders);
}

} // namespace booter
} // namespace smartHome
