#include "event_proccesors.hpp"
#include "itopic_distributer.hpp"

namespace smartHome 
{
namespace hub 
{

EventProcessor::EventProcessor(eventor::IEventStoreRemover& a_storeRemover, IDistributor& a_distributer, std::atomic<bool>& a_state)
: m_storeRemover(a_storeRemover)
, m_distributer(a_destributor)
, m_event()
, m_state(a_state)
{
}

void EventProcessor::Run() noexcept
{
    while(m_state)
    {
        m_event = m_storeRemover.RemoverEvent();
        m_distributer.DistributeToDevice(m_event);
    }
}



} //namespace hub
} //namespace smartHome 
