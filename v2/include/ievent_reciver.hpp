#ifndef IEVENT_FACTOR_HPP
#define IEVENT_FACTOR_HPP

#include "event.hpp"
#include <memory> //std::shared_ptr

namespace smartHome {
namespace eventor {

class IEventReciver
{
public:
    typedef std::shared_ptr<Event> EventPtr;

    virtual ~IEventReciver() = default;
    virtual void GenrateEvent(EventPtr a_event) = 0;

protected:
    IEventReciver() = default;
    IEventReciver(IEventReciver const& a_other) = default;
    IEventReciver& operator=(IEventReciver const& a_other) = default;
};

} // namespace eventor
} // namespace smartHome

#endif //IEVENT_FACTOR_HPP