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

class EventsPool: public advcpp::ThreadPool<> {
public:
    EventsPool(ITopicDistributer& a_destributor, size_t a_nThread = advcpp::getHardwareCores());

    ~EventsPool() noexcept = default;
    EventsPool(EventsPool const& a_rhs) = delete; 
    EventsPool& operator=(EventsPool const& a_rhs) = delete; 

    bool Submit(std::shared_ptr<eventor::Event> a_event); 

private:
    ITopicDistributer& m_destributor;
};

} //namespace smartHome 
} //namespace hub 

#endif //EVENT_POOL_HPP