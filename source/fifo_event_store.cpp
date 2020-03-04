#include "fifo_event_store.hpp"

namespace smartHome {
namespace eventor {

FifoEventStore::FifoEventStore(size_t a_maxEventsInStore)
: m_events(a_maxEventsInStore)
{
}

void FifoEventStore::AddEvent(std::shared_ptr<IEvent> a_event)
{
    m_events.Enqueue(a_event);
}

std::shared_ptr<IEvent> FifoEventStore::RemoverEvent()
{
    std::shared_ptr<IEvent> event;
    m_events.Dequeue(event);
    return event;
}

size_t FifoEventStore::NumOfEventsInStore()
{
    return m_events.Size();
}

} // namespace eventor
} // namespace smartHome