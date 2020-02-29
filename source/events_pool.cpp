#include "events_pool.hpp"
#include "event_proccesors.hpp" //EventProcessor

namespace smartHome 
{
namespace hub 
{

EventsPool::EventsPool(ITopicDistributer& a_destributor, size_t a_nThread)
: advcpp::ThreadPool<>(a_nThread)
, m_destributor(a_destributor)
{
}

bool EventsPool::Submit(std::shared_ptr<eventor::Event> a_event)
{
    return advcpp::ThreadPool<>::Submit(std::make_shared<EventProcessor>(a_event, m_destributor));
}

} //namespace smartHome 
} //namespace hub 
