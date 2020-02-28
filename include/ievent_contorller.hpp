#ifndef I_EVENT_CONTROLLER_HPP
#define I_EVENT_CONTROLLER_HPP

#include <memory> //std::shared_ptr
#include "event.hpp"

namespace smartHome {
namespace hub {

class IEventController {
public:

    typedef std::shared_ptr<eventor::Event> EventPtr;

    virtual ~IEventController() = default; 

    virtual void EventExec(EventPtr a_event) = 0;

protected:
    IEventController() = default;
    IEventController(IEventController const& a_rhs) = default;
    IEventController& operator=(IEventController const& a_rhs) = default;
};

} //namespace hub
} //namespace smartHome 

#endif //IEVENT_CONTROLLER_HPP