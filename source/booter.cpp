#include "booter.hpp"
#include "system_events.hpp"

namespace smartHome {
namespace booter{

Booter::Booter(SystemConnectorApi& a_connectors, IDeviceMaker& a_maker, IDeviceDataFactory& a_factory)
: m_connectors(a_connectors)
, m_maker(a_maker)
, m_factory(a_factory)
, m_deviceGroup()
{
}

void Booter::BootSystem()
{
    m_maker.CreateDevices(m_deviceGroup, m_connectors, m_factory);
    m_connectors.GetEventReciever().RecvEvent(std::make_shared<systemEvents::SystemEvent>
                                                (
                                                    systemEvents::g_systemOnTopic.m_type, 
                                                    systemEvents::g_systemOnTopic.m_location
                                                ));
}

void Booter::DisconnectDevices()
{
    m_deviceGroup.Foreach([](DevicePtr a_device){a_device->Disconnect();});
}


}// namespace booter
} // namespace smartHome