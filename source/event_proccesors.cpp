#include "event_proccesors.hpp"
#include "itopic_distributer.hpp"

namespace smartHome 
{
namespace hub 
{

EventProcessor::EventProcessor(std::shared_ptr<eventor::Event> a_event, ITopicDistributer& a_destributor)
: m_event(a_event)
, m_destributor(a_destributor)
{
}

void EventProcessor::Run() noexcept
{
    eventor::Topic topic(m_event->m_type, m_event->m_location);
    m_destributor.ExecuteTopic(topic, *m_event);
}



} //namespace hub
} //namespace smartHome 
