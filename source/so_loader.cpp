#include <functional>

#include "so_loader.hpp"

namespace smartHome {
namespace booter {

//void RegisterSmokeDetectorBuilder(DeviceBuilders& a_builders)

std::string const SODeviceRegistrator::registerFuncName = "RegistrateBuilder";

bool SODeviceRegistrator::LoadDeviceSO(DeviceType const& a_deviceType)
{
    try
    {
        m_loaders.emplace_back(a_deviceType);
        std::function<void(DeviceBuilders&)> registerFunc;
        m_loaders.back().GetFunc(registerFuncName, registerFunc);
        registerFunc(m_builders);
    }
    catch(const advcpp::SOException& e)
    {
        return false;
    }
    return true;
}

} // namespace booter
} // namespace smartHome
