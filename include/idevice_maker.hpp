#ifndef IDEVICE_MAKER_HPP
#define IDEVICE_MAKER_HPP

#include "device_group.hpp" //DeviceGroup
#include "system_connector_api.hpp" //SystemConnectorApi
#include "idevice_data_factory.hpp" //IDeviceDataFactory

namespace smartHome {
namespace booter {

class IDeviceMaker
{
public:
    virtual ~IDeviceMaker() = default;

    virtual void CreateDevices(hub::DeviceGroup& a_devices, SystemConnectorApi& a_connectors, 
                               IDeviceDataFactory& a_factory) = 0;

protected:
    IDeviceMaker() = default;
    IDeviceMaker(IDeviceMaker const& a_other) = default;
    IDeviceMaker& operator=(IDeviceMaker const& a_other) = default;
};

} //namespace booter
} //namespace smartHome

#endif //IDEVICE_MAKER_HPP