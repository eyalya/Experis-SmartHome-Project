#include <cassert> //assert
#include <memory> //shared_from_this
#include <iostream> //cout
#include <unistd.h> //sleep

#include "smoke_detector.hpp"
#include "system_events.hpp" //g_shutDownTopic


namespace smartHome {

SmokeDetector::SmokeDetector(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
: BaseAgent(a_data, a_connector)
, m_topics()
, m_state(true)
, m_runner(new RunSmokeDetector(m_state, a_connector.GetEventReciever(), a_data))
, m_shutDown()
// , m_smokeThread()
// , m_detectorOn(std::make_shared<SmokeDetectorOnHandler>(m_state, a_connector.GetEventReciever(), 
//                 m_smokeThread, a_data))
// , m_shutDown(std::make_shared<SmokeDetectorShutDownHandler>(m_state, m_smokeThread))
{
}

void SmokeDetector::Connect()
{
    // booter::SystemConnectorApi& connector = GetConnector();

    // std::shared_ptr<BaseAgent> pt = shared_from_this(); 
    // connector.GetRegistrator().RegisterSubscriber(pt, systemEvents::g_systemOnTopic);
    // connector.GetRegistrator().RegisterSubscriber(shared_from_this(), systemEvents::g_shutDownTopic);
}

void SmokeDetector::Disconnect()
{
    m_state = false;
    m_runner.Join();
    // m_smokeThread.JoinAll();
}

booter::EventHandlerPtr SmokeDetector::GetHandler(Topic&)
{
    // if (a_topic.m_type == systemEvents::g_systemOnTopic.m_type)
    // {
    //     return m_detectorOn;
    // }
    // else
    // {
    //     return m_shutDown;
    // }
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
    EventType fireStopped("fireStopped");
    
    while(m_state)
    {
        EventPtr fire = std::make_shared<FireEvent>(m_data->m_type, m_data->m_location, "FIRE!!!");
        m_reciver.RecvEvent(fire);
        std::cout << "Details: " << fire <<std::endl;
        sleep(2);
        m_reciver.RecvEvent(
            std::make_shared<FireEvent>(fireStopped, m_data->m_location, "FireStopped"));
    }
}

FireEvent::FireEvent(EventType a_type, Location a_location, std::string const& a_payload, TimeStamp a_timeStamp)
: EventBase(a_type, a_location, a_timeStamp)
, m_payload(a_payload)
{
}

// SmokeDetectorOnHandler::SmokeDetectorOnHandler(std::atomic<bool>& a_state, eventor::IEventReciver& a_reciver, 
//                            advcpp::ThreadsGroup<RunSmokeDetector>& a_smokeThread, DeviceDataPtr a_data)
// : m_state(a_state)
// , m_reciver(a_reciver)
// , m_smokeThread(a_smokeThread)
// , m_data(a_data)
// {
// }

// void SmokeDetectorOnHandler::Handle(EventPtr)
// {
//     m_state = true;
//     std::cout << "smoke detector on" << std::endl; 
//     m_smokeThread.AddThreads(1, m_state, m_reciver, m_data);
// }

// SmokeDetectorShutDownHandler::SmokeDetectorShutDownHandler(std::atomic<bool>& a_state, 
//                                                      advcpp::ThreadsGroup<RunSmokeDetector>& a_smokeThread)
// : m_state(a_state)
// , m_smokeThread(a_smokeThread)
// {
// }

void SmokeDetectorShutDownHandler::Handle(EventPtr)
{
    // m_state = false;
    std::cout << "shut down smoke detector" << std::endl;
    // m_smokeThread.JoinAll();
} 

DevicePtr SmokeDetectorBuilder::Build(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector)
{
    return std::make_shared<SmokeDetector>(a_data, a_connector);
}


} //namespace smartHome

using namespace smartHome;

extern "C" void RegistrateBuilder(booter::DeviceBuilders& a_builders)
{
    static std::shared_ptr<SmokeDetectorBuilder> s_fireBuilder(new SmokeDetectorBuilder);
    if(s_fireBuilder)
        a_builders.AddBuilder("smoke_detector", s_fireBuilder);
}
