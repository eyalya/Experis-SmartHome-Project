#ifndef BOOTER_HPP
#define BOOTER_HPP

#include "iregistrator.hpp"
#include "iloader.hpp"
#include "device_group.hpp"
#include "device.hpp"
namespace smartHome {
namespace booter{
class Booter
{
public:
    Booter(ILoader& a_loader, IRegistrator& a_registrator);

    void BootSystem();

private:
    ILoader& a_loader;
    IRegistrator& a_registrator;
    hub::DeviceGroup m_group;
};

class DeviceRegister
{
public:
    DeviceRegister(IRegistrator& a_registrator);

    void operator()(hub::Device const& a_device);

private: 
    IRegistrator& m_registrator;
};


} //namespace booter
} //namespace smartHome
#endif //BOOTER_HPP