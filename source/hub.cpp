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

Hub::~Hub()
{
    m_eventManager.ShutDown();
}

} //namespace hub
} //namespace smartHome