#ifndef GENRAL_BUILDER_INL
#define GENRAL_BUILDER_INL

#include "genral_builder.hpp"

namespace smartHome {
namespace booter {

template <typename AgentType>
DevicePtr GenralBuilder<AgentType>::Build(DeviceDataPtr a_data, SystemConnectorApi& a_connector)
{
    return make_shared(new AgentType(a_data, a_connector));
}


} //namespace smartHome 
} //namespace booter


#endif //GENRAL_BUILDER_INL