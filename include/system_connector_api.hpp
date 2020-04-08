#ifndef SYSTEM_CONNECTOR_API_HPP
#define SYSTEM_CONNECTOR_API_HPP

#include "isubscribers_register.hpp" //ISubscribersRegister
#include "ifind_topic_subscriber.hpp" //IFindTopicSubscriber
#include "ievent_reciver.hpp" //IEventReciver
#include "ievent_store_remover.hpp" //IEventStoreRemover

namespace smartHome {
namespace booter {

class SystemConnectorApi
{
public:
    virtual ~SystemConnectorApi() = default;

    virtual hub::ISubscribersRegister& GetRegistrator() = 0;
    virtual eventor::IEventReciver& GetEventReciever() = 0;
    virtual eventor::IEventStoreRemover& GetEventRemover() = 0;
    virtual hub::IFindTopicSubscriber& GetFinder() = 0;

protected:
    SystemConnectorApi() = default;
    SystemConnectorApi(SystemConnectorApi const& a_other) = delete;
    SystemConnectorApi& operator=(SystemConnectorApi const& a_other) = delete;
};

} //namespace booter
} //namespace smartHome

#endif //SYSTEM_CONNECTOR_API_HPP