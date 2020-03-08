#ifndef DEVICE_BUILDER_HPP
#define DEVICE_BUILDER_HPP

#include <unordered_map> //std::unordered map

#include "ievent.hpp" //eventType
#include "ibuilder.hpp" // IBuilder

namespace smartHome {
namespace booter {
    
class DeviceBuilders
{
public:
    DeviceBuilders(/* args */);
    ~DeviceBuilders();

    IBuilder& operator[](EventType const& a_type) const;

private:
    std::unordered_map<EventType, IBuilder> m_builders;
};

} // namespace booter
} // namespace smartHome

#endif // !DEVICE_BUILDER_HPP
