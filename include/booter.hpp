#ifndef BOOTER_HPP
#define BOOTER_HPP

#include "isubscribers_register.hpp" //ISubscribersRegister
#include "controller_container.hpp"//ControllerContainer
#include "Ievent_factory.hpp"

namespace smartHome{
namespace hub {

class Booter
{
public:
    Booter(ISubscribersRegister & a_registrator, eventor::IEventFactory& a_factory);
    ~Booter() = default;

    void LoadControllers();

private:
    ISubscribersRegister & m_registrator;
    eventor::IEventFactory& m_factory;
    ControllerContainer m_controllers;
};

} //namespace eventor 
} //namespace smartHome

#endif //BOOTER_HPP