#ifndef EVENT_PROCESSOR_HPP
#define EVENT_PROCESSOR_HPP

#include <memory> //shared_ptr
#include <atomic> //atomic

#include "thread.hpp"
#include "ievent.hpp" //Event
#include "idistributor.hpp" //IDistributor
#include "ievent_store_remover.hpp" //IEventStoreRemover

namespace smartHome 
{
namespace hub 
{

class EventProcessor: public advcpp::IRunnable{
public:

    EventProcessor(eventor::IEventStoreRemover& a_storeRemover, IDistributor& a_distributer, std::atomic<bool>& a_state);

    ~EventProcessor() = default;
    EventProcessor(const EventProcessor& a_rhs) = default;
    EventProcessor& operator = (const EventProcessor& a_rhs) = default;

    void Run() noexcept;

private:
    eventor::IEventStoreRemover& m_storeRemover;
    IDistributor& m_distributer;
    std::atomic<bool>& m_state;

    EventPtr m_event;
};


} //namespace hub
} //namespace smartHome 

#endif //EVENT_PROCESSOR_HPP