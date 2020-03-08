#include <cassert> //assert
#include <memory> //shared_from_this
#include <iostream> //cout

#include "sprinkler_device.hpp"
#include "system_events.hpp" //g_shutDownTopic

namespace smartHome {

Sprinklers::Sprinklers(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
: Device(a_data, a_connector)
, m_topics()
, m_state(true)
, m_shutDown(std::make_shared<SprinklersShutDownHandler>(m_state))
, m_sprinklerOn(std::make_shared<SprinklersOn>(m_state))
{
}


void Sprinklers::LoadToSystem()
{
    booter::SystemConnectorApi& connector = GetConnector();

    connector.GetRegistrator().RegisterSubscriber(shared_from_this(), systemEvents::g_shutDownTopic);
    connector.GetRegistrator().RegisterSubscriber(shared_from_this(), Topic("Fire", GetData()->m_location));
}

booter::EventHandlerPtr Sprinklers::GetHandler(Topic a_topic)
{
    if (a_topic.m_type == "Fire")
    {
        return m_sprinklerOn;
    }
    else
    {
        return m_shutDown;
    }
}

void Sprinklers::Run() noexcept
{
    while(m_state)
    {
    }
    std::cout << "sprinkler off" << std::endl;
}

void Sprinklers::ActivateSprinklers()
{
    std::cout << "sprinkler on" << std::endl;
}

SprinklersShutDownHandler::SprinklersShutDownHandler(std::atomic<bool>& a_state)
: m_state(a_state)
{
}

void SprinklersShutDownHandler::Handle(EventPtr a_event)
{
    (void) a_event;
    m_state = false;
}

SprinklersOn::SprinklersOn(std::atomic<bool>& a_state, Sprinklers* a_sprinkler)
: m_state(a_state)
, m_sprinkler(a_sprinkler)
{
}

void SprinklersOn::Handle(EventPtr a_event)
{
    (void) a_event;
    m_state = true;
    
}

} //namespace hub

