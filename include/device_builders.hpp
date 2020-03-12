#ifndef DEVICE_BUILDER_HPP
#define DEVICE_BUILDER_HPP

#include <unordered_map> //std::unordered map

#include "ibuilder.hpp" // IBuilder
#include "idevice_registrator.hpp"

namespace smartHome {
namespace booter {
    
class DeviceBuilders
{
public:
    typedef std::shared_ptr<IBuilder> BuilderPtr;

    DeviceBuilders(IDeviceRegistrator& a_registrator);
    ~DeviceBuilders() = default;

    IBuildPtr operator[](DeviceType const& a_type);

    void AddBuilder(DeviceType const& a_type, BuilderPtr a_builder);

private:
    std::unordered_map<DeviceType, IBuildPtr > m_builders;
    IDeviceRegistrator& m_registrator;
};

} // namespace booter
} // namespace smartHome

#endif // !DEVICE_BUILDER_HPP
