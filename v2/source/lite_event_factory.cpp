#include <unistd.h> //sleep

#include "lite_event_reciver.hpp"

namespace smartHome {
namespace eventor {

LiteEventReciver::LiteEventReciver(IEventStoreAdder& a_eventAdder)
: m_eventAdder(a_eventAdder)
{
}

void LiteEventReciver::RecvEvent(std::shared_ptr<IEvent> a_event)
{
    m_eventAdder.AddEvent(a_event);
}


} // namespace eventor
} // namespace smartHome