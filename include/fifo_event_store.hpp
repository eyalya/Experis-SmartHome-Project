#ifndef FIFO_EVENT_STORE_HPP
#define FIFO_EVENT_STORE_HPP

#include "ievent_store_adder.hpp"
#include "ievent_store_remover.hpp"
#include "waitable_queue.hpp" //advcpp::WaitableQ
#include "ievent.hpp"

namespace smartHome {
namespace eventor {

class FifoEventStore : public IEventStoreAdder, public IEventStoreRemover
{
public:
    explicit FifoEventStore(size_t a_maxEventsInStore = 100);
    ~FifoEventStore() = default;

    FifoEventStore(FifoEventStore const & a_other) = delete;
    FifoEventStore& operator=(FifoEventStore const & a_other) = delete;

    virtual void AddEvent(std::shared_ptr<IEvent> a_event);
    virtual std::shared_ptr<IEvent> RemoverEvent();

    size_t NumOfEventsInStore();

private:
    advcpp::WaitableQ<std::shared_ptr<IEvent> > m_events;
};

} //namespace eventor
} //namespace smartHome


#endif //FIFO_EVENT_STORE_HPP