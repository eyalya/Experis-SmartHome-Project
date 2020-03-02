#ifndef LITE_EVENT_FACTORY
#define LITE_EVENT_FACTORY

#include "ievent_reciver.hpp"
#include "ievent_store_adder.hpp"
#include "waitable_queue.hpp" 
#include "isensor.hpp"
#include "thread.hpp"

namespace smartHome {
namespace eventor {

class LiteEventReciver : public IEventReciver
{
public:
    explicit LiteEventReciver(IEventStoreAdder& a_eventAdder);
    LiteEventReciver(LiteEventReciver const& a_other) = default;
    virtual ~LiteEventReciver() = default;
    
    LiteEventReciver& operator=(LiteEventReciver const& a_other) = default;

    virtual void RecvEvent(std::shared_ptr<IEvent> a_event);

private:
    IEventStoreAdder& m_eventAdder;
};

} // namespace eventor
} // namespace smartHome

#endif //LITE_EVENT_FACTORY