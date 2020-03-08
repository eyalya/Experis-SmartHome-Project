#ifndef DEVICE_DATA_FACTORY_HPP
#define DEVICE_DATA_FACTORY_HPP

#include <vector> //std:vector
#include "idevice_data_factory.hpp"
#include "common_types.hpp"

namespace smartHome {
namespace booter {

class DeviceDataFactory: public IDeviceDataFactory  {
public:
    
    DeviceDataFactory() = default;

    ~DeviceDataFactory() = default;
    DeviceDataFactory(DeviceDataFactory const& a_rhs) = default;
    DeviceDataFactory& operator=(DeviceDataFactory const& a_rhs) = default;

    virtual void LoadDeviceData();
    virtual std::vector<DeviceDataPtr> const& GetDeviceData();

private:
    void CreateFireSensorData(size_t a_nTopics);
    void CreateSprinklerData(size_t a_nTopics);
private: 
    std::vector<DeviceDataPtr> a_datas;
};

} // namespace booter
} // namespace smartHome

#endif //DEVICE_DATA_FACTORY_HPP