#ifndef I_EVENT_CONTROLLER_HPP
#define I_EVENT_CONTROLLER_HPP

namespace advcpp 
{

template <typename T> 
class IEventController {
public:
    
    virtual ~IEventController() = default; 

    virtual void EventExec() = 0;
protected:
    IEventController(const IEventController<T>& a_rhs) = default;
    IEventController& operator=(const IEventController<T> a_rhs) = default;
};

} //namespace advcpp 

#endif //IEVENT_CONTROLLER_HPP