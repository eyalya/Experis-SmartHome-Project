#ifndef IEVENT_FACTOR_HPP
#define IEVENT_FACTOR_HPP

#include <memory> //std::shared_ptr

#include "ievent.hpp"

namespace smartHome {
namespace eventor {

class IEventReciver
{
public:
    virtual ~IEventReciver() = default;
    virtual void RecvEvent(std::shared_ptr<IEvent> a_event) = 0;

protected:
    IEventReciver() = default;
    IEventReciver(IEventReciver const& a_other) = default;
    IEventReciver& operator=(IEventReciver const& a_other) = default;
};

} // namespace eventor
} // namespace smartHome

#endif //IEVENT_FACTOR_HPP