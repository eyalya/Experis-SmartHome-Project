#ifndef IBUILDER_HPP
#define IBUILDER_HPP

#include "iagent.hpp"
#include "system_connector_api.hpp"

namespace smartHome {
namespace booter {
    
class IBuilder
{
public:
    //TODO: add interface stuff

    virtual ~IBuilder() = default;

    virtual IAgent Build(DeviceDataPtr a_data, SystemConnectorApi& a_connector) = 0;
};

} // namespace Booter    
} // namespace smartHome
#endif // !IBUILDER_HPP