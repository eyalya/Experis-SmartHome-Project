#include <memory> //std::shared_ptr

#include "system_connector.hpp"

namespace smartHome {
namespace booter {
    
SystemConnectors::SystemConnectors(hub::ISubscribersRegister& a_registerator, eventor::IEventReciver& a_storeRemover)
: m_registerator(a_registerator)
, m_storeRemover(a_storeRemover)
{
}

hub::ISubscribersRegister& SystemConnectors::GetRegistrator()
{
    return m_registerator;
}

eventor::IEventReciver& SystemConnectors::GetEventReciever()
{
    return m_storeRemover;
}



} // namespace booter
} // namespace smartHome
