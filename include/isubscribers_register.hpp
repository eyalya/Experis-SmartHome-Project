#ifndef SUBSCRIBERS_REGISTER_HPP
#define SUBSCRIBERS_REGISTER_HPP

#include <vector> //std::vector

#include "event.hpp" //Topic
#include "ievent_contorller.hpp" //eventControllers
#include "topic_Subscribers.hpp" //TopicSubscribers

namespace smartHome 
{
namespace hub 
{

class ISubscribersRegister {
public:
    virtual ~ISubscribersRegister() = default;
    
    virtual void RegisterSubscriber(IEventController& a_controller, Topic const& a_topic) = 0;
    virtual void UnRegisterSubscriber(IEventController& a_controller, Topic const& a_topic) = 0;

protected:
    ISubscribersRegister() = default;
    ISubscribersRegister(ISubscribersRegister const& a_rhs) = default;
    ISubscribersRegister& operator=(ISubscribersRegister const& a_rhs) = default;
};


} //namespace hub
} //namespace smartHome 

#endif //SUBSCRIBERS_REGISTER_HPP