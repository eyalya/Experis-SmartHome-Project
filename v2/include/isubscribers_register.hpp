#ifndef SUBSCRIBERS_REGISTER_HPP
#define SUBSCRIBERS_REGISTER_HPP

#include "event.hpp" //Topic
#include "device.hpp" //Device

namespace smartHome {
namespace hub {

class ISubscribersRegister {
public:
    virtual ~ISubscribersRegister() = default;
    
    virtual void RegisterSubscriber(std::shared_ptr<Device> a_device, eventor::Topic const& a_topic) = 0;
    virtual void UnRegisterSubscriber(std::shared_ptr<Device> a_device, eventor::Topic const& a_topic) = 0;

protected:
    ISubscribersRegister() = default;
    ISubscribersRegister(ISubscribersRegister const& a_rhs) = default;
    ISubscribersRegister& operator=(ISubscribersRegister const& a_rhs) = default;
};


} //namespace hub
} //namespace smartHome 

#endif //SUBSCRIBERS_REGISTER_HPP