#include <memory> //shared_ptr

#include "demo_controller.hpp"
#include "booter.hpp"
#include "light_event_factory.hpp" //DemoCensor

namespace smartHome {
namespace hub {

Booter::Booter(ISubscribersRegister & a_registrator, eventor::IEventFactory& a_factory)
: m_registrator(a_registrator)
, m_factory(a_factory)
{
}

void Booter::LoadControllers()
{
    //TODO: change to load from file.
    auto controller = std::make_shared<DemoController>("demo controller", eventor::Location(5, 2));
    m_registrator.RegisterSubscriber(controller, eventor::Topic(0, eventor::Location(5, 2)));

    eventor::DemoSensor censor(m_factory);
    censor.Run();
}

} //namespace hub
} //namespace smartHome