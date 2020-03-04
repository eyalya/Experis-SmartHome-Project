#include "mu_test.h"

#include <string> //std::string
#include <memory> //make_shared
#include <unistd.h> //sleep

#include "ievent.hpp" //IEvent
#include "event_base.hpp" //EventPtr
#include "topic_subscribers.hpp" //TopicSubscribers
#include "event_manager.hpp" //EventManager
#include "fifo_event_store.hpp" //FifoEventStore
#include "local_distributor.hpp" //LocalDistributor
#include "demo_event.hpp" //DemoEvent
#include "demo_device.hpp" //demoDevice, DemoHandler
#include "demo_sensor.hpp" //DemoSensor
#include "lite_event_reciver.hpp" //LiteEventReciver

using namespace std;
using namespace smartHome;
using namespace hub;
using namespace eventor;
using namespace advcpp;

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

void RegisterHandlers(TopicSubscribers& a_subscribers, vector<shared_ptr<IEventHandler> >& a_handlers, DeviceGroup& a_devices, std::vector<Topic> const& a_topics)
{
    string name("temp");
    const size_t topicsSize = a_topics.size();
    Topic temp = a_topics[0];
    const size_t deviceSize = a_devices.Size();

    // cout << "registerHandlers " << endl;
    for (size_t i = 0; i < deviceSize; ++i)
    {
        // cout << "topicId " << a_topics[i % topicsSize].m_id << endl;
        a_handlers.push_back(make_shared<DemoHandler>());
        a_devices[i]->RegisterHandlerToTopic(temp, a_handlers.back());
        a_devices[i]->SubscribeTopics(a_subscribers);
        temp = a_topics[i % topicsSize];
    }
}

void CreateDevices(DeviceGroup& a_devices, std::vector<Topic> const& a_topics, size_t a_nDevices)
{
    string name("temp");
    const size_t topicsSize = a_topics.size();
    Topic temp = a_topics[0];

    // cout << "createDevice " << endl;
    for (size_t i = 0; i < a_nDevices; ++i)
    {
        // cout << "topicId " << a_topics[i % topicsSize].m_id << endl;
        std::shared_ptr<Device> demo = make_shared<Device>(name, temp.m_location);
        a_devices.AddDevice(demo);
        temp = a_topics[i % topicsSize];
    }
}

void SubmitEvents(ThreadsGroup<eventor::DemoSensor>& a_sensors ,FifoEventStore& a_eventStore, std::vector<Topic> const& a_topics, size_t a_nEvents)
{
    EventType type("counter");
    const size_t topicsSize = a_topics.size();
    // Topic temp = a_topics[0];

    eventor::LiteEventReciver eventReciver(a_eventStore);
    // cout << "submitevents " << endl;
    for (size_t i = 0; i < 10; ++i)
    {
        // cout << "topicId " << a_topics[i % topicsSize].m_id << endl;
        // a_eventStore.AddEvent(make_shared<DemoEvent>(a_topics[i % topicsSize].m_type, a_topics[i % topicsSize].m_location, type));
        a_sensors.AddThreads(1, eventReciver, a_topics[i % topicsSize].m_location, type, a_nEvents);
    }
    a_sensors.JoinAll();
}

size_t SumResults(vector<shared_ptr<IEventHandler> > a_handlers)
{
    size_t count = 0;
    const size_t handlersSize = a_handlers.size();

    for (size_t i = 0; i < handlersSize; ++i)
    {
        DemoHandler* handler = static_cast<DemoHandler*>(a_handlers[i].get());
        // cout << "controller run: " << controller->GetNRuns() << endl;
        count += handler->GetNRuns();
    }
    return count;
}

void SubmitShutdownEvent(EventManager& a_manager, TopicSubscribers& a_subscribers, FifoEventStore& a_eventStore, Location const& a_location)
{
    EventType shutDowntype = "shutDown";
    Topic shutDownTopic(shutDowntype, a_location);
    string shutdownName("ender");

    std::shared_ptr<ShutDownHandler> shutDownPtr = make_shared<ShutDownHandler>(a_manager);
    std::shared_ptr<Device> ender = make_shared<Device>(shutdownName, a_location);
    ender->RegisterHandlerToTopic(shutDownTopic, shutDownPtr);
    a_subscribers.RegisterSubscriber(ender, shutDownTopic);

    a_eventStore.AddEvent(make_shared<DemoEvent>(shutDowntype, a_location, string("test")));
}

UNIT(smoke_test)
    TopicSubscribers subscribers;
    LocalDistributor disributor(subscribers);
    FifoEventStore eventStore;
    EventManager manager(eventStore, disributor);

    manager.Pause();
    manager.ShutDown();
    ASSERT_PASS();
END_UNIT

UNIT(check_handler)
    EventType type = "counter";
    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    Topic topic(type, location);

    string name("register");
    std::shared_ptr<Device> demo = make_shared<Device>(name, location);
    std::shared_ptr<DemoHandler> handlerPtr = make_shared<DemoHandler>();
    
    handlerPtr->Handle(std::make_shared<DemoEvent>(type, location));

    ASSERT_EQUAL(handlerPtr->GetNRuns(), 1);
END_UNIT

UNIT(check_registration)
    TopicSubscribers subscribers;

    EventType type = "counter";
    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    Topic topic(type, location);

    string name("register");
    std::shared_ptr<Device> demo = make_shared<Device>(name, location);
    std::shared_ptr<DemoHandler> handlerPtr = make_shared<DemoHandler>();

    demo->RegisterHandlerToTopic(topic, handlerPtr);
    demo->SubscribeTopics(subscribers);

    DeviceGroup devices = subscribers.FindTopic(topic);
    std::shared_ptr<IEventHandler> ihandler = devices[0]->GetHandler(topic);
    ihandler->Handle(std::make_shared<DemoEvent>(type, location));

    DemoHandler* resuletedHandler = static_cast<DemoHandler*>(ihandler.get());
    ASSERT_EQUAL(resuletedHandler->GetNRuns(), 1);
END_UNIT

UNIT(check_event_store)
    const size_t nEvents = 100000;
    FifoEventStore eventStore(nEvents);

    EventType type = "counter";
    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    Topic topic(type, location);

    for (size_t i = 0; i < nEvents; ++i)
    {
        eventStore.AddEvent(make_shared<DemoEvent>(type, location, string("test")));
    }
    ASSERT_EQUAL(eventStore.NumOfEventsInStore(), nEvents);

    std::shared_ptr<DemoHandler> handlerPtr = make_shared<DemoHandler>();
    for (size_t i = 0; i < nEvents; ++i)
    {
        EventPtr event = eventStore.RemoverEvent();
        handlerPtr->Handle(event);
    }

    ASSERT_EQUAL(handlerPtr->GetNRuns(), nEvents);
END_UNIT

UNIT(check_event_store_and_registration)
    const size_t nEvents = 100000;
    FifoEventStore eventStore(nEvents);
    TopicSubscribers subscribers;

    EventType type = "counter";
    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    Topic topic(type, location);

    for (size_t i = 0; i < nEvents; ++i)
    {
        eventStore.AddEvent(make_shared<DemoEvent>(type, location, string("test")));
    }
    ASSERT_EQUAL(eventStore.NumOfEventsInStore(), nEvents);

    string name("register");
    std::shared_ptr<Device> demo = make_shared<Device>(name, location);
    std::shared_ptr<DemoHandler> handlerPtr = make_shared<DemoHandler>();
    demo->RegisterHandlerToTopic(topic, handlerPtr);
    demo->SubscribeTopics(subscribers);

    for (size_t i = 0; i < nEvents; ++i)
    {
        EventPtr event = eventStore.RemoverEvent();
        DeviceGroup devices = subscribers.FindTopic(topic);
        std::shared_ptr<IEventHandler> ihandler = devices[0]->GetHandler(topic);
        ihandler->Handle(event);
    }

    ASSERT_EQUAL(handlerPtr->GetNRuns(), nEvents);
END_UNIT

UNIT(check_ditributor)
    const size_t nEvents = 100000;
    FifoEventStore eventStore(nEvents);
    TopicSubscribers subscribers;
    LocalDistributor distributor(subscribers);

    EventType type = "counter";
    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    Topic topic(type, location);

    for (size_t i = 0; i < nEvents; ++i)
    {
        eventStore.AddEvent(make_shared<DemoEvent>(type, location, string("test")));
    }
    ASSERT_EQUAL(eventStore.NumOfEventsInStore(), nEvents);

    string name("register");
    std::shared_ptr<Device> demo = make_shared<Device>(name, location);
    std::shared_ptr<DemoHandler> handlerPtr = make_shared<DemoHandler>();
    demo->RegisterHandlerToTopic(topic, handlerPtr);
    demo->SubscribeTopics(subscribers);

    for (size_t i = 0; i < nEvents; ++i)
    {
        EventPtr event = eventStore.RemoverEvent();
        distributor.DistributeToDevice(event);
    }

    ASSERT_EQUAL(handlerPtr->GetNRuns(), nEvents);
END_UNIT

UNIT(check_shutdown_handler)
    TopicSubscribers subscribers;
    LocalDistributor disributor(subscribers);
    FifoEventStore eventStore(10);
    EventManager manager(eventStore, disributor);
    manager.Run();

    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    
    SubmitShutdownEvent(manager, subscribers, eventStore, location);
    manager.ShutDown();
    ASSERT_PASS();
END_UNIT

UNIT(events_flow_one_topic)
    TopicSubscribers subscribers;
    LocalDistributor disributor(subscribers);
    const size_t nEvents = 100000;
    FifoEventStore eventStore(nEvents);
    EventManager manager(eventStore, disributor);

    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    
    EventType type = "counter";
    Topic topic(type, location);
    string name("register");
    std::shared_ptr<DemoHandler> handlerPtr = make_shared<DemoHandler>();
    std::shared_ptr<Device> demo = make_shared<Device>(name, location);
    demo->RegisterHandlerToTopic(topic, handlerPtr);
    subscribers.RegisterSubscriber(demo, topic);

    manager.Run();
    for (size_t i = 0; i < nEvents; ++i)
    {
        eventStore.AddEvent(make_shared<DemoEvent>(type, location, string("test")));
    }
    
    SubmitShutdownEvent(manager, subscribers, eventStore, location);
    manager.ShutDown();
    ASSERT_EQUAL(handlerPtr->GetNRuns(), nEvents);
END_UNIT

UNIT(events_flow_mul_topic)
    TopicSubscribers subscribers;
    LocalDistributor disributor(subscribers);
    const size_t nEvents = 100000;
    FifoEventStore eventStore(nEvents);
    EventManager manager(eventStore, disributor);
    manager.Run();
    
    const size_t nTopics = 1000;
    vector<Topic> topics;
    CreateTopics(topics, nTopics);
    void CreateTopics(std::vector<Topic>& a_topics, size_t a_nTopics);

    DeviceGroup devices;
    const size_t nDevices = nTopics;
    CreateDevices(devices, topics, nDevices);

    vector<shared_ptr<IEventHandler> > handler;
    RegisterHandlers(subscribers ,handler, devices, topics);
    
    ThreadsGroup<eventor::DemoSensor> sensors;
    SubmitEvents(sensors ,eventStore, topics, nEvents);

    SubmitShutdownEvent(manager, subscribers, eventStore, Location(1,2));
    manager.ShutDown();

    size_t countResults = SumResults(handler);
    ASSERT_EQUAL(countResults, nEvents);
END_UNIT

TEST_SUITE(tip# 1588258 we should ot regret our actions_ 
we responded to each event in our life the best we could with the knwoledge we had)

TEST(smoke_test)
TEST(check_handler)
TEST(check_registration)
TEST(check_event_store)
TEST(check_event_store_and_registration)
TEST(check_ditributor)
TEST(check_shutdown_handler)
TEST(events_flow_one_topic)
TEST(events_flow_mul_topic)

END_SUITE