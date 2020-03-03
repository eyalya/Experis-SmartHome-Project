#ifndef DEMO_DEVICE_HPP
#define DEMO_DEVICE_HPP

#include <string> //std::string
#include <atomic> //atomic

#include "event_base.hpp" //location
#include "device.hpp" //Device
#include "ievent_handler.hpp" //IEventHandler

namespace smartHome {
namespace hub {

class DemoDevice: public Device
{
public:
    DemoDevice(std::string const& a_name, Location a_location);
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



} //namespace smartHome
} //namespace hub

#endif //DEMO_DEVICE_HPP
