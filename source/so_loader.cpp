#include <functional>

#include "so_loader.hpp"

namespace smartHome {
namespace booter {

//void RegisterSmokeDetectorBuilder(DeviceBuilders& a_builders)

std::string const SODeviceRegistrator::registerFuncName = "RegistrateBuilder";

void SODeviceRegistrator::Register(DeviceType const& a_type, DeviceBuilders& a_builders)
{
    std::string soLib = a_type + ".so";
    m_loaders.emplace_back(soLib);

    // std::string soFunc = registerFuncName + a_type;
    std::function<void(DeviceBuilders&)> registerFunc;
    m_loaders.back().GetFunc(registerFuncName, registerFunc);

    registerFunc(a_builders);
}

} // namespace booter
} // namespace smartHome
