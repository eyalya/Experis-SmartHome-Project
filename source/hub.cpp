#include "hub.hpp" 

namespace smartHome{
namespace hub {

Hub::Hub()
: m_subscribers()
, m_systemBooter(m_subscribers)
, m_eventsPool(m_subscribers)
, m_eventManager(m_eventsPool)
, m_factory(m_eventsPool)
{
}

void Hub::Run()
{
    m_systemBooter.LoadControllers();
}

Hub::~Hub()
{
    m_eventManager.ShutDown();
}

} //namespace hub
} //namespace smartHome