#include <cassert> //assert
#include <memory> //shared_from_this
#include <iostream> //cout

#include "smoke_detector.hpp"
#include "system_events.hpp" //g_shutDownTopic

namespace smartHome {

SmokeDetector::SmokeDetector(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
: BaseAgent(a_data, a_connector)
, m_topics()
, m_state(true)
, m_smokeThread()
, m_detectorOn(std::make_shared<SmokeDetectorOnHandler>(m_state, a_connector.GetEventReciever(), 
                m_smokeThread, a_data))
, m_shutDown(std::make_shared<SmokeDetectorShutDownHandler>(m_state, m_smokeThread))
{
}

void SmokeDetector::LoadToSystem()
{
    booter::SystemConnectorApi& connector = GetConnector();

    connector.GetRegistrator().RegisterSubscriber(shared_from_this(), systemEvents::g_shutDownTopic);
}

booter::EventHandlerPtr SmokeDetector::GetHandler(Topic a_topic)
{
    assert(a_topic == systemEvents::g_shutDownTopic);
    return m_shutDown;
}

RunSmokeDetector::RunSmokeDetector(std::atomic<bool>& a_state, eventor::IEventReciver& a_reciver,
                                   DeviceDataPtr a_data)
: m_state(a_state)
, m_reciver(a_reciver)
, m_data(a_data)
{
}

void RunSmokeDetector::Run() noexcept
{
    while(m_state)
    {
        m_reciver.RecvEvent(
            std::make_shared<FireEvent>(m_data->m_type, m_data->m_location, "FIRE!!!"));
    }
}

FireEvent::FireEvent(EventType a_type, Location a_location, std::string const& a_payload, TimeStamp a_timeStamp)
: EventBase(a_type, a_location, a_timeStamp)
, m_payload(a_payload)
{
}

SmokeDetectorOnHandler::SmokeDetectorOnHandler(std::atomic<bool>& a_state, eventor::IEventReciver& a_reciver, 
                           advcpp::ThreadsGroup<RunSmokeDetector>& a_smokeThread, DeviceDataPtr a_data)
: m_state(a_state)
, m_reciver(a_reciver)
, m_smokeThread(a_smokeThread)
, m_data(a_data)
{
}

void SmokeDetectorOnHandler::Handle(EventPtr)
{
    m_state = true;
    m_smokeThread.AddThreads(1, m_state, m_reciver, m_data);
}

SmokeDetectorShutDownHandler::SmokeDetectorShutDownHandler(std::atomic<bool>& a_state, 
                                                     advcpp::ThreadsGroup<RunSmokeDetector>& a_smokeThread)
: m_state(a_state)
, m_smokeThread(a_smokeThread)
{
}

void SmokeDetectorShutDownHandler::Handle(EventPtr)
{
    m_state = false;
    std::cout << "shut down smoke detector" << std::endl;
    m_smokeThread.JoinAll();
}

} //namespace hub

