#ifndef DEVICE_GROUP_INL
#define DEVICE_GROUP_INL

namespace smartHome 
{
namespace hub 
{


inline size_t DeviceGroup::Size() const
{
    return m_devices.size();
}

inline DeviceGroup::DevicePtr DeviceGroup::operator[](size_t a_index)
{
    return m_devices.operator[](a_index);
}

inline DeviceGroup::DevicePtr DeviceGroup::operator[](size_t a_index) const
{
    return m_devices.operator[](a_index);
}

} //namespace hub
} //namespace smartHome 

#endif //DEVICE_GROUP_INL