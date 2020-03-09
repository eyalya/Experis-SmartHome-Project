#ifndef IAGENT_HPP
#define IAGENT_HPP 

#include "event_base.hpp" //Topic
#include "system_connector_api.hpp" //booter::SystemConnectorApi
#include "common_types.hpp" // booter::EventHandlerPtr, DeviceDataPtr

namespace smartHome {

class IAgent
{
public:
    virtual ~IAgent() = default;

    virtual booter::EventHandlerPtr GetHandler(Topic a_topic) = 0;
    virtual DeviceDataPtr GetData() = 0;
    virtual booter::SystemConnectorApi& GetConnector() = 0;
    virtual void Connect() = 0;

protected:
    IAgent() = default;
    IAgent(IAgent const& a_other) = default;
    IAgent& operator=(IAgent const& a_rhs) = default;

};

} // namespace smartHome

#endif // !IAGENT_HPP