#include "event_proccesors.hpp"

namespace smartHome 
{
namespace hub 
{

EventProcessor::EventProcessor(eventor::IEventStoreRemover& a_storeRemover, IDistributor& a_distributer, std::atomic<bool>& a_state)
: m_storeRemover(a_storeRemover)
, m_distributer(a_distributer)
, m_state(a_state)
, m_event()
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
