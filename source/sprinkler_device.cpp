#include <cassert> //assert
#include <memory> //shared_from_this
#include <iostream> //cout

#include "sprinkler_device.hpp"
#include "system_events.hpp" //g_shutDownTopic

namespace smartHome {

Sprinklers::Sprinklers(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
: BaseAgent(a_data, a_connector)
, m_topics()
, m_state(true)
, m_sprinklerRunner()
, m_sprinklerOn(std::make_shared<SprinklersOn>(m_state, m_sprinklerRunner))
, m_shutDown(std::make_shared<SprinklersShutDownHandler>(m_state, m_sprinklerRunner))
{
}


void Sprinklers::Connect()
{
    booter::SystemConnectorApi& connector = GetConnector();

    connector.GetRegistrator().RegisterSubscriber(shared_from_this(), systemEvents::g_shutDownTopic);
    connector.GetRegistrator().RegisterSubscriber(shared_from_this(), Topic("Fire", GetData()->m_location));
    connector.GetRegistrator().RegisterSubscriber(shared_from_this(), Topic("fireStopped", GetData()->m_location));
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

RunSprinkle::RunSprinkle(std::atomic<bool>& a_state, EventPtr a_event)
: m_state(a_state)
, m_event(a_event)
{
}

void RunSprinkle::Run() noexcept
{
    std::cout << "sprinkler on: " << std::endl;
    std::cout << "Details: " << m_event <<std::endl;
    while(m_state)
    {
    }
    std::cout << "sprinkler off" << std::endl;
    std::cout << "Details: " << m_event <<std::endl;
}

SprinklersOn::SprinklersOn(std::atomic<bool>& a_state, advcpp::ThreadsGroup<RunSprinkle>& a_sprinklerThread)
: m_state(a_state)
, m_sprinklerThread(a_sprinklerThread)
{
}


void SprinklersOn::Handle(EventPtr a_event)
{
    m_state = true;
    m_sprinklerThread.AddThreads(1, m_state, a_event);
}

SprinklersShutDownHandler::SprinklersShutDownHandler(std::atomic<bool>& a_state, advcpp::ThreadsGroup<RunSprinkle>& a_sprinklerThread)
: m_state(a_state)
, m_sprinklerThread(a_sprinklerThread)
{
}

void SprinklersShutDownHandler::Handle(EventPtr)
{
    m_state = false;
    m_sprinklerThread.JoinAll();
}

DevicePtr SprinkelBuilder::Build(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
{
    return std::make_shared<Sprinklers>(a_data, a_connector);
}

} //namespace hub

