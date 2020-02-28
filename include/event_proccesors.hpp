#ifndef EVENT_PROCESSOR_HPP
#define EVENT_PROCESSOR_HPP

#include <memory> //shared_ptr
#include <atomic> //atomic

#include "thread.hpp"
#include "event.hpp" //Event
#include "itopic_distributer.hpp" //ITopicDistributer

namespace smartHome 
{
namespace hub 
{

class EventProcessor: public advcpp::IRunnable{
public:

    EventProcessor(std::shared_ptr<eventor::Event> a_event, ITopicDistributer& a_destributor);

    ~EventProcessor() = default;
    EventProcessor(const EventProcessor& a_rhs) = default;
    EventProcessor& operator = (const EventProcessor& a_rhs) = default;

    void Run() noexcept;

private:
    std::shared_ptr<eventor::Event> m_event;
    ITopicDistributer& m_destributor;
};


} //namespace hub
} //namespace smartHome 

#endif //EVENT_PROCESSOR_HPP