#ifndef DEMO_DEVICE_HPP
#define DEMO_DEVICE_HPP

#include <string> //std::string
#include <atomic> //atomic

#include "event_base.hpp" //location, Topic
#include "device.hpp" //Device
#include "ievent_handler.hpp" //IEventHandler
#include "event_manager.hpp" //EventManager

namespace smartHome {
namespace hub {

class DemoDevice: public Device
{
public:
    const size_t nTopics = 10;
    
    DemoDevice(std::string const& a_name, Location a_location);
    std::vector<Topic> GetTopics() const; //TODO: possible for making it virtual

private:
    void RegisterHandlers();

private:
    std::vector<Topic> m_topics;
};

class DemoHandler: public IEventHandler
{
public:
    DemoHandler();

    virtual void Handle(EventPtr a_event);
    size_t GetNRuns() const;

private:
    std::atomic<size_t> m_nRuns;
};

class ShutDownHandler: public IEventHandler
{
public:
    ShutDownHandler(EventManager& a_manager);

    virtual void Handle(EventPtr a_event);

private:
    EventManager& m_manager;
};

} //namespace smartHome
} //namespace hub

#endif //DEMO_DEVICE_HPP
