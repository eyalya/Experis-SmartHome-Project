#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <memory> //std::shared_ptr

#include "system_connector_api.hpp" //SystemConnectorApi
#include "iagent.hpp"
#include "event_base.hpp" //Topic, Location
#include "common_types.hpp" //EventHandlerPtr
#include "isubscribers_register.hpp" //ISubscribersRegister

namespace smartHome {

struct DeviceData 
{
    DeviceData(std::string a_type, Location a_location, std::string a_log = "", std::string a_config = "");

    std::string m_type;
    std::string m_log;
    Location m_location;
    std::string m_config;
};

class BaseAgent : public IAgent, public std::enable_shared_from_this<BaseAgent>
{
public:
    BaseAgent(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector);

    virtual booter::EventHandlerPtr GetHandler(Topic& a_topic) = 0;
    virtual void Connect() = 0;
    virtual void Disconnect() = 0;

protected:
    DeviceDataPtr GetData();
    booter::SystemConnectorApi& GetConnector();

private:
    DeviceDataPtr m_data;
    booter::SystemConnectorApi& m_connector;
};

} //namespace smartHome

#include "inl/device.inl"
#endif //DEVICE_HPP