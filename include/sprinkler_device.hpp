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
#include "ibuilder.hpp" //IBuilder

namespace smartHome {

class RunSprinkle: public advcpp::IRunnable {
public:
    RunSprinkle(std::atomic<bool>& a_state, EventPtr a_event);

    virtual void Run() noexcept;
private: 
    std::atomic<bool>& m_state;
    EventPtr m_event;
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
    virtual void Connect();
    virtual void Disconnect();
    
private:
    std::vector<Topic> m_topics;
    std::atomic<bool> m_state;
    advcpp::ThreadsGroup<RunSprinkle> m_sprinklerRunner;
    booter::EventHandlerPtr m_sprinklerOn;
    booter::EventHandlerPtr m_shutDown;
};

class SprinkelBuilder: public booter::IBuilder {
public:
    SprinkelBuilder() = default;

    ~SprinkelBuilder() = default;
    SprinkelBuilder(SprinkelBuilder const& a_rhs) = delete;
    SprinkelBuilder& operator=(SprinkelBuilder const& a_rhs) = delete;

    virtual DevicePtr Build(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector);
};


} //namespace smartHome

#endif //SPRINKLERS_HPP
