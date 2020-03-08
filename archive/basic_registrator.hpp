#ifndef BASIC_REGISTRATOR_HPP
#define BASIC_REGISTRATOR_HPP

#include "iregistrator.hpp"
#include "isubscribers_register.hpp"

namespace smartHome {
namespace booter{

class BasicRegistrator : public IRegistrator
{
public:
    BasicRegistrator(hub::ISubscribersRegister& a_subRegister);

    virtual void RegisterDevice(std::shared_ptr<hub::BaseAgent> a_device);

private:
    hub::ISubscribersRegister& m_subRegister;
};

} //namespace booter
} //namespace smartHome

#endif //BASIC_REGISTRATOR_HPP