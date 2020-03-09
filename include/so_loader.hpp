#ifndef SO_LOADER
#define SO_LOADER

#include <vector> //std::vector

#include "so_handler.hpp"
#include "common_types.hpp"
#include "device_builders.hpp"

namespace smartHome {
namespace booter {

class SODeviceRegistrator : public IDeviceRegistrator
{
public:
    SODeviceRegistrator(DeviceBuilders& m_builders);

    bool LoadDeviceSO(DeviceType const& a_deviceType);
    
private:
    static std::string const registerFuncName;

private:
    std::vector<advcpp::SOHandler> m_loaders;
    DeviceBuilders& m_builders;
};  
    
} // namespace booter
} // namespace smartHome
#endif // !SO_LOADER