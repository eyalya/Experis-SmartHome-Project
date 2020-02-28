#ifndef I_EVENT_CONTROLLER_HPP
#define I_EVENT_CONTROLLER_HPP

#include "event.hpp"

namespace smartHome 
{
namespace hub 
{

class IEventController {
public:
    
    virtual ~IEventController() = default; 

    virtual void EventExec(eventor::Event a_event) = 0;

protected:
    IEventController() = default;
    IEventController(IEventController const& a_rhs) = default;
    IEventController& operator=(IEventController const& a_rhs) = default;
};

} //namespace hub
} //namespace smartHome 

#endif //IEVENT_CONTROLLER_HPP