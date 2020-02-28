#ifndef EVENT_POOL_HPP
#define EVENT_POOL_HPP

#include <memory> //std::shared_ptr

#include "thread_pool.hpp" //ThreadPool
#include "event.hpp" //Event
#include "itopic_distributer.hpp" //ITopicDistributer

namespace smartHome 
{
namespace hub 
{
//TODO: deside on workers number for pool
class EventsPool: public advcpp::UnCopiable {
public:
    EventsPool(ITopicDistributer& a_destributor, advcpp::ThreadPool<>& a_eventsPool);

    ~EventsPool() noexcept = default;
    EventsPool(EventsPool const& a_rhs) = delete; 
    EventsPool& operator=(EventsPool const& a_rhs) = delete; 

    bool Submit(std::shared_ptr<eventor::Event> a_event); 

private:
    ITopicDistributer& m_destributor;
    advcpp::ThreadPool<>& m_eventsPool;
};

} //namespace smartHome 
} //namespace hub 

#endif //EVENT_POOL_HPP