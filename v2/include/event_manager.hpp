#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <memory> //shared_ptr
#include <atomic> //std::atomic

#include "ievent.hpp" //IEvent
#include "ievent_store_remover.hpp" //IEventStoreRemover
#include "idistributor.hpp" //IDistributor
#include "event_proccesors.hpp" //EventProcessor
#include "thread_group.hpp" //ThreadGroup

namespace smartHome 
{
namespace hub 
{

class EventManager {
public:
    const size_t nWorkers = 1;

    EventManager(eventor::IEventStoreRemover& a_storeRemover, IDistributor& a_distributer);

    ~EventManager();
    EventManager(EventManager const& a_rhs) = default;
    EventManager& operator=(EventManager const& a_rhs) = default;

    void Run(size_t a_nWorkers = 1);
    void ShutDown();
    void Pause();

private:
    eventor::IEventStoreRemover& m_storeRemover;
    IDistributor& m_distributer;
    advcpp::ThreadsGroup<EventProcessor> m_workers;
    std::atomic<bool> m_state;
};

} //namespace hub
} //namespace smartHome 

#endif //EVENT_MANAGER_HPP