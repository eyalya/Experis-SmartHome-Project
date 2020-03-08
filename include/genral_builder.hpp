#ifndef GENRAL_BUILDER_HPP
#define GENRAL_BUILDER_HPP

#include <string> //std::string

#include "ibuilder.hpp" //ibuilder
#include "device_builders.hpp"

namespace smartHome {
namespace booter {

template <typename AgentType>
class GenralBuilder : public IBuilder
{
public:
    GenralBuilder() = default;
    ~GenralBuilder() = default;

    static void Register(std::string const& m_agentTypeID, DeviceBuilders& a_builders);
    virtual DevicePtr Build(DeviceDataPtr a_data, SystemConnectorApi& a_connector);    
};

} //namespace smartHome 
} //namespace booter

#include "inl/genral_builder.inl"

#endif // !GENRAL_BUILDER_HPP