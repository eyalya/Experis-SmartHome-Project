#ifndef FIRE_SENSOR_HPP
#define FIRE_SENSOR_HPP

#include <string> //std::string
#include <atomic> //atomic
#include <vector> //std::vector

#include "event_base.hpp" //location, Topic, Event
#include "device.hpp" //BaseAgent
#include "thread_group.hpp" //ThreadGroup, IRunnable
#include "ievent_handler.hpp" //IEventHandler
#include "ievent_reciver.hpp" //IEventReciver
#include "common_types.hpp" //EventHandlerPtr
#include "ibuilder.hpp" //IBuilder

namespace smartHome {

class RunSmokeDetector: public advcpp::IRunnable {
public:
    RunSmokeDetector(std::atomic<bool>& a_state, eventor::IEventReciver& a_reciver,
                      DeviceDataPtr a_data);

    virtual void Run() noexcept;
private: 
    std::atomic<bool>& m_state;
    eventor::IEventReciver& m_reciver;
    DeviceDataPtr m_data;
};

class SmokeDetector: public BaseAgent {
public:
    SmokeDetector(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector);

    ~SmokeDetector() = default;
    SmokeDetector(SmokeDetector const& a_rhs) = delete;
    SmokeDetector& operator=(SmokeDetector const& a_rhs) = delete;

    virtual booter::EventHandlerPtr GetHandler(Topic a_topic);
    virtual void Connect();

private:
    std::vector<Topic> m_topics;
    std::atomic<bool> m_state;
    advcpp::ThreadsGroup<RunSmokeDetector> m_smokeThread;
    booter::EventHandlerPtr m_detectorOn;
    booter::EventHandlerPtr m_shutDown;
};

struct FireEvent: public EventBase {
    FireEvent(EventType a_type, Location a_location, std::string const& Payload = " ", TimeStamp a_timeStamp = "00:00");
    
    std::string m_payload;
};

class SmokeDetectorOnHandler: public hub::IEventHandler {
public:

    SmokeDetectorOnHandler(std::atomic<bool>& a_state, eventor::IEventReciver& a_reciver, 
                           advcpp::ThreadsGroup<RunSmokeDetector>& a_smokeThread, DeviceDataPtr a_data);

    virtual void Handle(EventPtr a_event);
private: 
    std::atomic<bool>& m_state;
    eventor::IEventReciver& m_reciver;
    advcpp::ThreadsGroup<RunSmokeDetector>& m_smokeThread;
    DeviceDataPtr m_data;
};

class SmokeDetectorShutDownHandler: public hub::IEventHandler {
public:

    SmokeDetectorShutDownHandler(std::atomic<bool>& a_state, advcpp::ThreadsGroup<RunSmokeDetector>& a_smokeThread);

    virtual void Handle(EventPtr a_event);
private: 
    std::atomic<bool>& m_state;
    advcpp::ThreadsGroup<RunSmokeDetector>& m_smokeThread;
};

class SmokeDetectorBuilder: public booter::IBuilder {
public:
    SmokeDetectorBuilder() = default;

    ~SmokeDetectorBuilder() = default;
    SmokeDetectorBuilder(SmokeDetectorBuilder const& a_rhs) = delete;
    SmokeDetectorBuilder& operator=(SmokeDetectorBuilder const& a_rhs) = delete;

    virtual DevicePtr Build(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector);
};

} //namespace smartHome

#endif //FIRE_SENSOR_HPP