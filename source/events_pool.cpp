#include "events_pool.hpp"
#include "event_proccesors.hpp" //EventProcessor

namespace smartHome 
{
namespace hub 
{

EventsPool::EventsPool(ITopicDistributer& a_destributor, advcpp::ThreadPool<>& a_eventsPool)
: m_destributor(a_destributor)
, m_eventsPool(a_eventsPool)
{
}

bool EventsPool::Submit(std::shared_ptr<eventor::Event> a_event)
{
    return m_eventsPool.Submit(std::make_shared<EventProcessor>(a_event, m_destributor));
}

} //namespace smartHome 
} //namespace hub 
