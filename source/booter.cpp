#include <memory> //shared_ptr

#include "demo_controller.hpp"
#include "booter.hpp"

namespace smartHome {
namespace hub {

Booter::Booter(ISubscribersRegister& a_registrator)
: m_registrator(a_registrator)
{
}

void Booter::LoadControllers()
{
    //TODO: change to load from file.
    auto controller = std::make_shared<DemoController>("demo controller", eventor::Location(5, 2));
    m_registrator.RegisterSubscriber(controller, eventor::Topic(0, eventor::Location(5, 2)));
}

} //namespace hub
} //namespace smartHome