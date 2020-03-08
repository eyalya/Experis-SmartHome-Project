#ifndef SPRINKLERS_HPP
#define SPRINKLERS_HPP

#include <string> //std::string
#include <atomic> //atomic
#include <vector> //std::vector

#include "event_base.hpp" //location, Topic, Event
#include "device.hpp" //BaseAgent
#include "thread_group.hpp" //Thread
#include "ievent_handler.hpp" //IEventHandler
#include "common_types.hpp" //EventHandlerPtr

namespace smartHome {

class RunSprinkle: public advcpp::IRunnable {
public:
    RunSprinkle(std::atomic<bool>& a_state);

    virtual void Run() noexcept;
private: 
    std::atomic<bool>& m_state;
};

class SprinklersOn: public hub::IEventHandler {
public:

    SprinklersOn(std::atomic<bool>& a_state, advcpp::ThreadsGroup<RunSprinkle>& a_sprinklerThread);

    virtual void Handle(EventPtr a_event);

private: 
    std::atomic<bool>& m_state;
    advcpp::ThreadsGroup<RunSprinkle>& m_sprinklerThread;
};

class SprinklersShutDownHandler: public hub::IEventHandler {
public:

    SprinklersShutDownHandler(std::atomic<bool>& a_state, advcpp::ThreadsGroup<RunSprinkle>& a_sprinklerThread);

    virtual void Handle(EventPtr a_event);
private: 
    std::atomic<bool>& m_state;
    advcpp::ThreadsGroup<RunSprinkle>& m_sprinklerThread;
};

class Sprinklers: public BaseAgent {
public:
    explicit Sprinklers(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector);

    ~Sprinklers() = default;
    Sprinklers(Sprinklers const& a_rhs) = delete;
    Sprinklers& operator=(Sprinklers const& a_rhs) = delete;

    virtual booter::EventHandlerPtr GetHandler(Topic a_topic);
    
private: 
    void LoadToSystem();

private:
    std::vector<Topic> m_topics;
    std::atomic<bool> m_state;
    advcpp::ThreadsGroup<RunSprinkle> m_sprinklerRunner;
    booter::EventHandlerPtr m_shutDown;
    booter::EventHandlerPtr m_sprinklerOn;
};




} //namespace smartHome

#endif //SPRINKLERS_HPP
