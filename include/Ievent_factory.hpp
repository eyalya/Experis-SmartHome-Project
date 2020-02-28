#ifndef IEVENT_FACTOR_HPP
#define IEVENT_FACTOR_HPP

#include "event.hpp"

namespace smartHome {
namespace eventor {

class IEventFactory
{
public:
    typedef std::shared_ptr<Event> EventPtr;

    virtual ~IEventFactory() = default;
    virtual void GenrateEvent(EventPtr a_event) = 0;

protected:
    IEventFactory() = default;
    IEventFactory(IEventFactory const& a_other) = default;
    IEventFactory& operator=(IEventFactory const& a_other) = default;
};

} // namespace eventor
} // namespace smartHome

#endif //IEVENT_FACTOR_HPP