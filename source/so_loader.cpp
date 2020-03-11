#include <functional>

#include "so_loader.hpp"

namespace smartHome {
namespace booter {

//void RegisterSmokeDetectorBuilder(DeviceBuilders& a_builders)

std::string const SODeviceRegistrator::registerFuncName = "RegistrateBuilder";


void SODeviceRegistrator::Register(DeviceType const& a_type, DeviceBuilders& a_builders)
{
    std::string soLib(a_type + ".so");
    auto handler = advcpp::SOHandler{soLib};    
    auto rf = handler.GetFunc<void(DeviceBuilders&)>(registerFuncName.c_str());    
    rf(a_builders);
    m_loaders.push_back(handler);
}

} // namespace booter
} // namespace smartHome
