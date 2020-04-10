#include "test_helpers.hpp"

#include "device.hpp" //DeviceData

namespace smartHome
{
namespace booter 
{

void TestFactory::LoadDeviceData()
{
    CreateDoNothingData(m_nDevices);
}

std::vector<DeviceDataPtr> const& TestFactory::GetDeviceData()
{
    return m_datas;
}

void TestFactory::CreateDoNothingData(size_t a_nTopics)
{
    EventType type = "counter";
    Floor floor = 0;
    Room room = 0;
    
    for(size_t i = 0; i < a_nTopics; ++i)
    {
        m_datas.push_back(std::make_shared<DeviceData>("counter", Location (floor, room)));
        ++room;            
        ++floor;
    }
}

DoNothing::DoNothing(DeviceDataPtr a_data, booter::SystemConnectorApi& a_connector, booter::EventHandlerPtr a_handler)
: BaseAgent(a_data, a_connector)
, m_handler(a_handler)
{
}

void DoNothing::Connect()
{
}

void DoNothing::Disconnect()
{
}

booter::EventHandlerPtr DoNothing::GetHandler(Topic const&)
{
    return m_handler;
}

void Counter::Handle(EventPtr a_event)
{
    (void) a_event;
    ++m_counter;
}

size_t Counter::GetCounter()
{
    return m_counter;
}

CountEvent::CountEvent(EventType a_type, Location a_location, std::string const& a_payload, TimeStamp a_timeStamp)
: EventBase(a_type, a_location, a_timeStamp)
, m_payload(a_payload)
{
}


} //namespace booter
} //namespace smartHome
