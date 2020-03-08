#ifndef IBUILDER_HPP
#define IBUILDER_HPP

#include "iagent.hpp"
#include "system_connector_api.hpp"

namespace smartHome {
namespace booter {
    
class IBuilder
{
public:
    virtual ~IBuilder() = default;

    virtual IAgent Build(DeviceDataPtr a_data, SystemConnectorApi& a_connector) = 0;
    
protected:      
    IBuilder() = default;
    IBuilder(IBuilder const& a_other) = default;
    IBuilder& operator=(IBuilder const& a_rhs) = default;
};

} // namespace Booter    
} // namespace smartHome
#endif // !IBUILDER_HPP