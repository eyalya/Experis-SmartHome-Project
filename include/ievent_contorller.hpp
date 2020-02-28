#ifndef I_EVENT_CONTROLLER_HPP
#define I_EVENT_CONTROLLER_HPP

namespace smartHome 
{
namespace hub 
{

class IEventController {
public:
    
    virtual ~IEventController() = default; 

    virtual void EventExec() = 0;
protected:
    IEventController() = default;
    IEventController(const IEventController& a_rhs) = default;
    IEventController& operator=(const IEventController a_rhs) = default;
};

} //namespace hub
} //namespace smartHome 

#endif //IEVENT_CONTROLLER_HPP