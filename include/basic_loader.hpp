#ifndef BASIC_LOADER_HPP
#define BASIC_LOADER_HPP

#include "iloader.hpp"
#include "device_group.hpp"

namespace smartHome {
namespace booter {

class BasicLoader : public ILoader
{
public:
    BasicLoader(hub::DeviceGroup& a_devices);

    virtual void LoadDevices();

private:
    hub::DeviceGroup& m_devices;
};

} //namespace booter
} //namespace smartHome

#endif //BASIC_LOADER_HPP