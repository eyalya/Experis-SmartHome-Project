#ifndef SYSTEM_CONNECTORS_HPP
#define SYSTEM_CONNECTORS_HPP

#include "system_connector_api.hpp" //SystemConnectorApi

namespace smartHome {
namespace booter {

class SystemConnectors : public SystemConnectorApi
{
public:
    SystemConnectors(hub::ISubscribersRegister& a_registerator, eventor::IEventReciver& a_storeRemover);

    ~SystemConnectors() = default;

    virtual hub::ISubscribersRegister& GetRegistrator();
    virtual eventor::IEventReciver& GetEventReciever();

private:
    hub::ISubscribersRegister& m_registerator;
    eventor::IEventReciver& m_storeRemover;
};

} //namespace booter
} //namespace smartHome

#endif  //SYSTEM_CONNECTORS_HPP