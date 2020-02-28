#include "event_manager.hpp"

namespace smartHome 
{
namespace hub 
{

EventManger::EventManger(advcpp::ThreadPool<>& a_eventsPool)
: m_eventsPool(a_eventsPool)
{
}

void EventManger::Resume()
{
    m_eventsPool.AddWorkers();
}

void EventManger::ShutDown()
{
    m_eventsPool.ShutDown(advcpp::ThreadPool<>::ShutDownModes::NOOB);
}

} //namespace hub
} //namespace smartHome 