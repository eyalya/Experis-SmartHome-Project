#ifndef SYSTEM_CONNECTORS_HPP
#define SYSTEM_CONNECTORS_HPP

#include "system_connector_api.hpp" //SystemConnectorApi
#include "device_group.hpp"
#include "isensor.hpp" //ISensor
#include "thread_group.hpp" //ThreadGroup
#include "ievent_store_remover.hpp" //IEventStoreRemover

namespace smartHome {
namespace booter {

class SystemConnectors : public SystemConnectorApi
{
public:
    SystemConnectors(hub::ISubscribersRegister& a_registerator, eventor::IEventStoreRemover& a_storeRemover);

    virtual hub::ISubscribersRegister& GetRegistrator();
    virtual eventor::IEventReciver& GetEventReciever();

private:
    hub::ISubscribersRegister& m_registerator;
    eventor::IEventStoreRemover& m_storeRemover;
};

} //namespace booter
} //namespace smartHome

#endif  //SYSTEM_CONNECTORS_HPP