#ifndef DEVICE_GROUP_INL
#define DEVICE_GROUP_INL

#include <algorithm> //std::for_each

namespace smartHome 
{
namespace hub 
{


inline size_t DeviceGroup::Size() const
{
    return m_devices.size();
}

inline DevicePtr DeviceGroup::operator[](size_t a_index)
{
    return m_devices.operator[](a_index);
}

inline DevicePtr DeviceGroup::operator[](size_t a_index) const
{
    return m_devices.operator[](a_index);
}

template <typename Action>
void DeviceGroup::Foreach(Action a_action)
{
    std::for_each(m_devices.begin(), m_devices.end(), a_action);
}

} //namespace hub
} //namespace smartHome 

#endif //DEVICE_GROUP_INL