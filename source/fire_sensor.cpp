#include <cassert> //assert
#include <memory> //shared_from_this

#include "fire_sensor.hpp"
#include "system_events.hpp" //g_shutDownTopic

namespace smartHome {

FireSensor::FireSensor(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
: BaseAgent(a_data, a_connector)
, m_topics()
, m_state(true)
, m_shutDown(std::make_shared<FireSensorShutDownHandler>(m_state))
{
}

void FireSensor::LoadToSystem()
{
    booter::SystemConnectorApi& connector = GetConnector();

    connector.GetRegistrator().RegisterSubscriber(shared_from_this(), systemEvents::g_shutDownTopic);
}

booter::EventHandlerPtr FireSensor::GetHandler(Topic a_topic)
{
    assert(a_topic == systemEvents::g_shutDownTopic);
    return m_shutDown;
}

void FireSensor::Run() noexcept
{
    eventor::IEventReciver& reciver = GetConnector().GetEventReciever();
    while(m_state)
    {
        reciver.RecvEvent(
            std::make_shared<FireEvent>(GetData()->m_type, GetData()->m_location, "FIRE!!!"));
    }
}

FireEvent::FireEvent(EventType a_type, Location a_location, std::string const& a_payload, TimeStamp a_timeStamp)
: EventBase(a_type, a_location, a_timeStamp)
, m_payload(a_payload)
{
}

FireSensorShutDownHandler::FireSensorShutDownHandler(std::atomic<bool>& a_state)
: m_state(a_state)
{
}

void FireSensorShutDownHandler::Handle(EventPtr)
{
    m_state = false;
}

} //namespace hub

