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
    SODeviceRegistrator() = default;

    virtual void Register(DeviceType const& a_type, DeviceBuilders& a_builders);
    
private:
    static std::string const registerFuncName;

private:
    std::vector<advcpp::SOHandler> m_loaders;
};  
    
} // namespace booter
} // namespace smartHome
#endif // !SO_LOADER