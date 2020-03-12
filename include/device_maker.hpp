#ifndef SO_DEVICE_MAKER_HPP
#define SO_DEVICE_MAKER_HPP

#include "idevice_maker.hpp" //IDeviceMaker
#include "device_builders.hpp" //DeviceBuilders
#include "idevice_data_factory.hpp" //IDeviceDataFactory
#include "device.hpp" //BaseAgent
#include "common_types.hpp" //DevicePtr, DeviceDataPtr

namespace smartHome {
namespace booter {

class DeviceMaker: public IDeviceMaker
{
public:
    DeviceMaker(DeviceBuilders& a_deviceBuilders);

    ~DeviceMaker() = default;
    DeviceMaker(DeviceMaker const& a_other) = default;
    DeviceMaker& operator=(DeviceMaker const& a_other) = default;
    

    virtual void CreateDevices(hub::DeviceGroup& a_devices, SystemConnectorApi& a_connectors, 
                               IDeviceDataFactory& a_factory);

private:
    DevicePtr CreateDevice(DeviceDataPtr a_data, SystemConnectorApi& a_connectors);

private:
    DeviceBuilders& m_deviceBuilders;
};

} //namespace booter
} //namespace smartHome

#endif //SO_DEVICE_MAKER_HPP