#include "event_manager.hpp"

namespace smartHome 
{
namespace hub 
{

EventManager::EventManager(eventor::IEventStoreRemover& a_storeRemover, IDistributor& a_distributer)
: m_storeRemover(a_storeRemover)
, m_distributer(a_distributer)
, m_workers()
, m_state(false)
{
}

void EventManager::Run(size_t a_nWorkers)
{
    m_state = true;
    m_workers.AddThreads(a_nWorkers, m_storeRemover, m_distributer, m_state);
}

void EventManager::ShutDown()
{
    m_state = false;
    m_workers.JoinAll();
}

} //namespace hub
} //namespace smartHome 