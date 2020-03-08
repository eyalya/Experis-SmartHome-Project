#ifndef DEVICE_GROUP_HPP
#define DEVICE_GROUP_HPP

#include <vector> //std::vector
#include <memory> //shared_ptr

#include "device.hpp" //BaseAgent
#include "common_types.hpp" //DevicePtr

namespace smartHome {
namespace hub {

class DeviceGroup {
public:
    typedef std::vector<DevicePtr>::iterator iterator;

    DeviceGroup() = default;
    DeviceGroup(DevicePtr a_device);

    ~DeviceGroup() = default;
    DeviceGroup(DeviceGroup const& a_rhs) = default;
    DeviceGroup& operator=(DeviceGroup const& a_rhs) = default;

    void AddDevice(DevicePtr a_device);
    void RemoveDevice(DevicePtr a_device);

    template <typename Action>
    void Foreach(Action a_action); 

    //GetHandler(iterator a_iter);

    DevicePtr operator[](size_t a_index);
    DevicePtr operator[](size_t a_index) const;
    size_t Size() const;
    
private:
    std::vector<DevicePtr> m_devices;
};

} //namespace hub
} //namespace smartHome 

#include "inl/device_group.inl"
#endif //DEVICE_GROUP_HPP