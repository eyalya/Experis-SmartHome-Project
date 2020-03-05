#ifndef SYSTEM_CONNECTOR_API_HPP
#define SYSTEM_CONNECTOR_API_HPP

#include "isubscribers_register.hpp" //ISubscribersRegister
#include "ievent_reciver.hpp" //IEventReciver

namespace smartHome {
namespace booter {

class SystemConnectorApi
{
public:
    virtual ~SystemConnectorApi() = default;

    virtual hub::ISubscribersRegister& GetRegistrator() = 0;
    virtual eventor::IEventReciver& GetEventReciever() = 0;

protected:
    SystemConnectorApi() = default;
    SystemConnectorApi(SystemConnectorApi const& a_other) = default;
    SystemConnectorApi& operator=(SystemConnectorApi const& a_other) = default;
};

} //namespace booter
} //namespace smartHome

#endif //SYSTEM_CONNECTOR_API_HPP