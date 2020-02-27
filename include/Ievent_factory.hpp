#ifndef IEVENT_FACTOR_HPP
#define IEVENT_FACTOR_HPP

#include "event.hpp"

namespace smartHome {
namespace eventor {

class IEventFactory
{
public:
    virtual ~IEventFactory() = default;
    virtual void GenrateEvent(Event const& a_event);

protected:
    IEventFactory() = default;
    IEventFactory(IEventFactory const& a_other) = default;
    IEventFactory& operator=(IEventFactory const& a_other) = default;
};

} // namespace eventor
} // namespace smartHome

#endif //IEVENT_FACTOR_HPP