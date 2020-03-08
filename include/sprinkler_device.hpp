#ifndef SPRINKLERS_HPP
#define SPRINKLERS_HPP

#include <string> //std::string
#include <atomic> //atomic

#include "event_base.hpp" //location, Topic, Event
#include "device.hpp" //Device
#include "thread.hpp" //IRunnable
#include "ievent_handler.hpp" //IEventHandler
#include "event_manager.hpp" //EventManager
#include "ievent_reciver.hpp" //IEventReciver
#include "common_types.hpp" //EventHandlerPtr

namespace smartHome {

class Sprinklers: public Device, public advcpp::IRunnable {
public:
    explicit Sprinklers(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector);

    ~Sprinklers() = default;
    Sprinklers(Sprinklers const& a_rhs) = delete;
    Sprinklers& operator=(Sprinklers const& a_rhs) = delete;

    virtual booter::EventHandlerPtr GetHandler(Topic a_topic);
    virtual void Run() noexcept;
    
    void ActivateSprinklers();

private: 
    void LoadToSystem();

private:
    std::vector<Topic> m_topics;
    std::atomic<bool> m_state;
    booter::EventHandlerPtr m_shutDown;
    booter::EventHandlerPtr m_sprinklerOn;
};

class SprinklersShutDownHandler: public hub::IEventHandler {
public:

    SprinklersShutDownHandler(std::atomic<bool>& a_state);

    virtual void Handle(EventPtr a_event);
private: 
    std::atomic<bool>& m_state;
};

class SprinklersOn: public hub::IEventHandler {
public:

    SprinklersOn(std::atomic<bool>& a_state, Sprinklers* a_sprinkler);

    virtual void Handle(EventPtr a_event);
private: 
    std::atomic<bool>& m_state;
    Sprinklers* m_sprinkler;
};
} //namespace smartHome

#endif //SPRINKLERS_HPP
