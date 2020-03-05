#ifndef DEVICE_DATA_FACTORY_HPP
#define DEVICE_DATA_FACTORY_HPP

#include "idevice_data_factory.hpp"

namespace smartHome {
namespace booter {

class DeviceDataFactory {
public:
    DeviceDataFactory() = default;

    ~DeviceDataFactory() = default;
    DeviceDataFactory(DeviceDataFactory const& a_rhs) = default;
    DeviceDataFactory& operator=(DeviceDataFactory const& a_rhs) = default;

    virtual DeviceDataPtr GetDeviceData();
    virtual bool HasMore();

private:
    // T m_mmb;
};

} // namespace booter
} // namespace smartHome

#endif //DEVICE_DATA_FACTORY_HPP