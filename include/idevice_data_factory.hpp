#ifndef IDEVICE_DATA_FACTORY_HPP
#define IDEVICE_DATA_FACTORY_HPP

#include "common_types.hpp" //DeviceDataPtr

namespace smartHome {
namespace booter {

class IDeviceDataFactory
{
public:
    virtual ~IDeviceDataFactory() = default;

    virtual void LoadDeviceData() = 0;
    virtual std::vector<DeviceDataPtr> const& GetDeviceData() = 0;

protected:
    IDeviceDataFactory() = default;
    IDeviceDataFactory(IDeviceDataFactory const& a_other) = default;
    IDeviceDataFactory& operator=(IDeviceDataFactory const& a_other) = default;
};

} // namespace booter
} // namespace smartHome

#endif //IDEVICE_DATA_FACTORY_HPP