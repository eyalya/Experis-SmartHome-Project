#ifndef BOOTER_HPP
#define BOOTER_HPP

#include "isubscribers_register.hpp" //ISubscribersRegister
#include "controller_container.hpp"//ControllerContainer

namespace smartHome{
namespace hub {

class Booter
{
public:
    Booter(ISubscribersRegister & a_registrator);
    ~Booter() = default;

    void LoadControllers();

private:
    ISubscribersRegister & m_registrator;
    ControllerContainer m_controllers;
};

} //namespace eventor 
} //namespace smartHome

#endif //BOOTER_HPP