#ifndef DEMO_CONTROLLER_HPP
#define DEMO_CONTROLLER_HPP

#include <string> //std::string

#include "event.hpp" //location
#include "ievent_contorller.hpp"

namespace smartHome {
namespace hub {

class DemoController : public IEventController
{
public:
    DemoController(std::string const& a_name, eventor::Location a_location);

    virtual void EventExec(EventPtr a_event);

private:
    eventor::Location m_location;
    std::string m_name;
};

} //namespace smartHome
} //namespace hub

#endif //DEMO_CONTROLLER_HPP