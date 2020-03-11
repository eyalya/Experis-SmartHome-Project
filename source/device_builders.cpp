#include "device_builders.hpp"

namespace smartHome {
namespace booter
{

DeviceBuilders::DeviceBuilders(IDeviceRegistrator& a_registrator)
: m_registrator(a_registrator)
{ 
}


//TODO: for mhz: make it optional
//TODO: make it return a pointer, on failure erturn null
IBuilder& DeviceBuilders::operator[](DeviceType const& a_type)
{
    auto builder = m_builders.find(a_type);
    if(builder != m_builders.end())
    {
        return *(builder->second);
    }

    m_registrator.Register(a_type, *this);

    builder = m_builders.find(a_type);
    // FIXME: return if not found
    // if(builder != m_builders.end())
    // {
    //     return *(builder->second);
    // }
    return *(builder->second);
}

void DeviceBuilders::AddBuilder(DeviceType const& a_type, BuilderPtr a_builder)
{
    m_builders.insert({a_type, std::move(a_builder)});
}
    
} // namespace booter
} // namespace smartHome

