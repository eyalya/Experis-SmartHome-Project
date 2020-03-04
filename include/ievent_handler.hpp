#ifndef IEVENT_HANDLER_HPP
#define IEVENT_HANDLER_HPP

#include <memory> //std::shared_ptr

#include "ievent.hpp" //IEvent

namespace smartHome {
namespace hub {

class IEventHandler
{
public:
    typedef std::shared_ptr<IEvent> EventPtr;
    
    virtual ~IEventHandler() = default;
    virtual void Handle(EventPtr a_event) = 0;

protected:
    IEventHandler() = default;
    IEventHandler(IEventHandler const& a_other) = default;
    IEventHandler& operator=(IEventHandler const& a_other) = default;
};

} // namespace hub
} // namespace smartHome

#endif //IEVENT_HANDLER_HPP