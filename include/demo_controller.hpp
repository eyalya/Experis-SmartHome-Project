#ifndef DEMO_CONTROLLER_HPP
#define DEMO_CONTROLLER_HPP

#include "ievent_contorller.hpp"

namespace smartHome {
namespace hub {

class DemoController : public IEventController
{
public:
    DemoController();

    virtual void EventExec(EventPtr a_event);
};

#endif //DEMO_CONTROLLER_HPP