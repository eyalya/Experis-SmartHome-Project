#include "demo_config_file.hpp"
#include "lite_event_reciver.hpp" //LiteEventReciver


namespace smartHome {
namespace booter {

void CreateTopics(std::vector<Topic>& a_topics, size_t a_nTopics)
{
    EventType type = "counter";
    Floor floor = 0;
    Room room = 0;
    
    while(a_nTopics --> 0)
    {
        // cout << "create topic: 1" << floor << room << endl;
        a_topics.push_back(Topic(type, Location(floor, room)));
        ++room;            
        ++floor;
    }
}

void RegisterHandlers(hub::TopicSubscribers& a_subscribers, std::vector<std::shared_ptr<hub::IEventHandler> >& a_handlers, 
                        hub::DeviceGroup& a_devices, std::vector<Topic> const& a_topics)
{
    std::string name("temp");
    const size_t topicsSize = a_topics.size();
    Topic temp = a_topics[0];
    const size_t deviceSize = a_devices.Size();

    for (size_t i = 0; i < deviceSize; ++i)
    {
        a_handlers.push_back(std::make_shared<hub::DemoHandler>());
        a_devices[i]->RegisterHandlerToTopic(temp, a_handlers.back());
        a_devices[i]->SubscribeTopics(a_subscribers);
        temp = a_topics[i % topicsSize];
    }
}

void CreateDevices(hub::DeviceGroup& a_devices, size_t a_nDevices)
{
    for (size_t i = 0; i < a_nDevices; ++i)
    {
        std::shared_ptr<hub::Device> demo = std::make_shared<hub::Device>("temp", Location(i, i));
        a_devices.AddDevice(demo);
    }
}

void CreateSensors(advcpp::ThreadsGroup<eventor::DemoSensor>& a_sensors ,eventor::FifoEventStore& a_eventStore, 
                  std::vector<Topic> const& a_topics)
{
    EventType type("counter");
    const size_t topicsSize = a_topics.size();
    const size_t nEvents = 1000;

    eventor::LiteEventReciver eventReciver(a_eventStore);
    for (size_t i = 0; i < nEvents; ++i)
    {
        a_sensors.AddThreads(1, eventReciver, a_topics[i % topicsSize].m_location, type, nEvents);
    }

    a_sensors.JoinAll();
}

size_t SumResults(std::vector<std::shared_ptr<hub::IEventHandler> > a_handlers)
{
    size_t count = 0;
    const size_t handlersSize = a_handlers.size();

    for (size_t i = 0; i < handlersSize; ++i)
    {
        hub::DemoHandler* handler = static_cast<hub::DemoHandler*>(a_handlers[i].get());
        count += handler->GetNRuns();
    }
    return count;
}

void SubmitShutdownEvent(hub::EventManager& a_manager, hub::TopicSubscribers& a_subscribers, 
                         eventor::FifoEventStore& a_eventStore, Location const& a_location)
{
    EventType shutDowntype = "shutDown";
    Topic shutDownTopic(shutDowntype, a_location);
    std::string shutdownName("ender");

    std::shared_ptr<hub::ShutDownHandler> shutDownPtr = std::make_shared<hub::ShutDownHandler>(a_manager);
    std::shared_ptr<hub::Device> ender = std::make_shared<hub::Device>(shutdownName, a_location);
    ender->RegisterHandlerToTopic(shutDownTopic, shutDownPtr);
    a_subscribers.RegisterSubscriber(ender, shutDownTopic);

    a_eventStore.AddEvent(std::make_shared<DemoEvent>(shutDowntype, a_location, "test"));
}

} //namespace smartHome
} //namespace booter