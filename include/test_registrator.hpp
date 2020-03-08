#ifndef TEST_REGISTRATOR_HPP
#define TEST_REGISTRATOR_HPP

#include "idevice_registrator.hpp"
#include "device_builders.hpp"

namespace smartHome {
namespace booter {
    
class TestRegistrator : public IDeviceRegistrator
{
public:
    virtual void Registrate(DeviceType const& a_type, DeviceBuilders& a_builders);
};

void RegistrateFireBuilder(DeviceBuilders& a_builders);
void RegistrateSprinklerBuilder(DeviceBuilders& a_builders);

} // namespace booter
} // namespace smartHome


#endif //TEST_REGISTRATOR_HPP
  