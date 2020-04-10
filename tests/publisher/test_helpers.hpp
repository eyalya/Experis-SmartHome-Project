#ifndef TEST_HELPERS_HPP
#define TEST_HELPERS_HPP

#include <vector> //std:vector

#include "idevice_data_factory.hpp"
#include "device.hpp" //BaseAgent
#include "event_base.hpp" //location, Topic, Event
#include "ievent_handler.hpp" //IEventHandler
#include "common_types.hpp"

namespace smartHome 
{
namespace booter 
{

class TestFactory: IDeviceDataFactory
{

public:
    TestFactory(size_t a_nPerDevice): m_nDevices(a_nPerDevice){};
    ~TestFactory() = default;

    virtual void LoadDeviceData();
    virtual std::vector<DeviceDataPtr> const& GetDeviceData();
private:
    void CreateDoNothingData(size_t a_nTopics);

private:
    size_t m_nDevices;
    std::vector<DeviceDataPtr> m_datas;
};

class DoNothing: public BaseAgent {
public:
    DoNothing(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector, booter::EventHandlerPtr a_handler);

    virtual booter::EventHandlerPtr GetHandler(Topic const& a_topic);
    virtual void Connect();
    virtual void Disconnect();

private:
    booter::EventHandlerPtr m_handler;
};

class Counter: public hub::IEventHandler {
public:

    Counter() = default;

    virtual void Handle(EventPtr a_event);

    size_t GetCounter();
private: 
    size_t m_counter = {0};
};

struct CountEvent: public EventBase {
    CountEvent(EventType a_type, Location a_location, std::string const& Payload = " ", TimeStamp a_timeStamp = "00:00");
    
    std::string m_payload;
};

} //namespace booter



} //namespace smartHome
#endif //TEST_HELPERS_HPP