#ifndef FIRE_SENSOR_HPP
#define FIRE_SENSOR_HPP

#include <string> //std::string
#include <atomic> //atomic

#include "event_base.hpp" //location, Topic, Event
#include "device.hpp" //BaseAgent
#include "thread.hpp" //IRunnable
#include "ievent_handler.hpp" //IEventHandler
#include "event_manager.hpp" //EventManager
#include "ievent_reciver.hpp" //IEventReciver
#include "common_types.hpp" //EventHandlerPtr

namespace smartHome {

class FireSensor: public BaseAgent, public advcpp::IRunnable {
public:
    explicit FireSensor(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector);

    ~FireSensor() = default;
    FireSensor(FireSensor const& a_rhs) = delete;
    FireSensor& operator=(FireSensor const& a_rhs) = delete;

    virtual booter::EventHandlerPtr GetHandler(Topic a_topic);
    virtual void Run() noexcept;

private: 
    void LoadToSystem();

private:
    std::vector<Topic> m_topics;
    std::atomic<bool> m_state;
    booter::EventHandlerPtr m_shutDown;
};

struct FireEvent: public EventBase {
    FireEvent(EventType a_type, Location a_location, std::string const& Payload = " ", TimeStamp a_timeStamp = "00:00");
    
    std::string m_payload;
};

class FireSensorOnHandler: public hub::IEventHandler {
public:

    FireSensorOnHandler(std::atomic<bool>& a_state, std::shared_ptr<FireSensor> a_fireSensor);

    virtual void Handle(EventPtr a_event);
private: 
    std::atomic<bool>& m_state;
    std::shared_ptr<FireSensor> a_fireSensor
};

class FireSensorShutDownHandler: public hub::IEventHandler {
public:

    FireSensorShutDownHandler(std::atomic<bool>& a_state, advcpp::ThreadsGroup<FireSensor>& a_fireSensorThread);

    virtual void Handle(EventPtr a_event);
private: 
    std::atomic<bool>& m_state;
    advcpp::ThreadsGroup<FireSensor>& m_fireSensorThread;
};

} //namespace smartHome

#endif //FIRE_SENSOR_HPP
