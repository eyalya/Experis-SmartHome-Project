#include <memory> //std::shared_ptr

#include "demo_config_file.hpp" 
#include "system_connector.hpp"
#include "device.hpp"
#include "demo_device.hpp" //DemoDevice

namespace smartHome {
namespace booter {
    
SystemConnectors::SystemConnectors(hub::ISubscribersRegister& a_registerator, eventor::IEventStoreRemover& a_storeRemover)
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
