#include "device_group.hpp"

using namespace std;

namespace smartHome 
{
namespace hub 
{
    
DeviceGroup::DeviceGroup(DevicePtr a_device)
: m_devices()
{
    m_devices.push_back(a_device);
}

void DeviceGroup::AddDevice(DevicePtr a_device)
{
    m_devices.push_back(a_device);
}

void DeviceGroup::RemoveDevice(DevicePtr a_device)
{
    //TODO: settel how to find a controller 
    (void) a_device;
}



} //namespace hub
} //namespace smartHome 