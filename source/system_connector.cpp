#include <memory> //std::shared_ptr

#include "system_connector.hpp"

namespace smartHome {
namespace booter {
    
SystemConnectors::SystemConnectors(hub::ISubscribersRegister& a_registerator, 
                                    eventor::IEventReciver& a_reciever,
                                    hub::IFindTopicSubscriber& a_finder,
                                    eventor::IEventStoreRemover& a_remover)
: m_registerator(a_registerator)
, m_reciever(a_reciever)
, m_finder(a_finder)
, m_remover(a_remover)
{
}

hub::ISubscribersRegister& SystemConnectors::GetRegistrator()
{
    return m_registerator;
}

eventor::IEventReciver& SystemConnectors::GetEventReciever()
{
    return m_reciever;
}

hub::IFindTopicSubscriber& SystemConnectors::GetFinder()
{
    return m_finder;
}

eventor::IEventStoreRemover& SystemConnectors::GetEventRemover()
{
    return m_remover;
}


} // namespace booter
} // namespace smartHome
