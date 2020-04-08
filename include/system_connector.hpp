#ifndef SYSTEM_CONNECTORS_HPP
#define SYSTEM_CONNECTORS_HPP

#include "system_connector_api.hpp" //SystemConnectorApi

namespace smartHome {
namespace booter {

class SystemConnectors : public SystemConnectorApi
{
public:
    SystemConnectors(hub::ISubscribersRegister& a_registerator, 
                        eventor::IEventReciver& a_reciever,
                        hub::IFindTopicSubscriber& a_finder,
                        eventor::IEventStoreRemover& a_remover);

    ~SystemConnectors() = default;

    virtual hub::ISubscribersRegister& GetRegistrator();
    virtual eventor::IEventReciver& GetEventReciever();
    virtual eventor::IEventStoreRemover& GetEventRemover();
    virtual hub::IFindTopicSubscriber& GetFinder();

private:
    hub::ISubscribersRegister& m_registerator;
    eventor::IEventReciver& m_reciever;
    hub::IFindTopicSubscriber& m_finder;
    eventor::IEventStoreRemover& m_remover;
};

} //namespace booter
} //namespace smartHome

#endif  //SYSTEM_CONNECTORS_HPP