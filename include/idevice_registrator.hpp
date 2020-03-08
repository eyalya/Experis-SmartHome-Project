#ifndef IDEVICE_REGISTRATOR_HPP
#define IDEVICE_REGISTRATOR_HPP

#include "common_types.hpp"

namespace smartHome {
namespace booter
{
    
class IDeviceRegistrator
{
public:
    virtual ~IDeviceRegistrator() = default;

    virtual void Registrate(DeviceType const& a_type, DeviceBuilders& a_builders);

protected:
    IDeviceRegistrator() = default;
    IDeviceRegistrator(IDeviceRegistrator const& a_other) = default;
    IDeviceRegistrator& operator=(IDeviceRegistrator const& a_rhs) = default;
};
  

  

} // namespace booter
} // namespace smartHome


#endif //IDEVICE_REGISTRATOR_HPP