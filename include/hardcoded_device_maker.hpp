#ifndef HARDCODED_DEVICE_MAKER_HPP
#define HARDCODED_DEVICE_MAKER_HPP

#include "idevice_maker.hpp" //IDeviceMaker
#include "idevice_data_factory.hpp" //IDeviceDataFactory
#include "device.hpp" //Device
#include "common_types.hpp" //DevicePtr, DeviceDataPtr

namespace smartHome {
namespace booter {

class HardCodedDeviceMaker: public IDeviceMaker
{
public:
    HardCodedDeviceMaker() = default;

    ~HardCodedDeviceMaker() = default;
    HardCodedDeviceMaker(HardCodedDeviceMaker const& a_other) = default;
    HardCodedDeviceMaker& operator=(HardCodedDeviceMaker const& a_other) = default;
    

    virtual void CreateDevices(hub::DeviceGroup& a_devices, SystemConnectorApi& a_connectors, 
                               IDeviceDataFactory& a_factory);

private:
    DevicePtr CreateDevice(DeviceDataPtr a_data, SystemConnectorApi& a_connectors);
};

} //namespace booter
} //namespace smartHome

#endif //HARDCODED_DEVICE_MAKER_HPP