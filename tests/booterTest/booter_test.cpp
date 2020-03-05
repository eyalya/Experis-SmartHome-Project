#include "mu_test.h"

#include <string> //std::string

// #include "booter.hpp" //Booter
// #include "basic_registrator.hpp" //BasicRegistrator
// #include "basic_loader.hpp" //BasicLoader
// #include "topic_subscribers.hpp" //TopicSubscribers
// #include "demo_devices.hpp" //demoDevice, DemoHandler
// #include "fifo_event_store.hpp" //FifoEventStore
// #include "thread_group.hpp" //ThreadGroup
// #include "local_distributor.hpp" //LocalDistributor

#include "device_group.hpp" //DeviceGroup
#include "fire_sensor.hpp" //FireSensor
#include "device_data_factory.hpp" //DeviceDataFactory
#include "system_connector.hpp" //SystemConnectors


using namespace std;
using namespace smartHome;
using namespace hub;
using namespace booter;
// using namespace eventor;


UNIT(smoke_test)
    DeviceGroup group;
    DeviceDataFactory factory;
    // SystemConnectors connector;
    // FireSensor sensors(factory.GetDeviceData(), ); 
    // TopicSubscribers susbscriber;
    // BasicRegistrator registrator(susbscriber);
    // BasicLoader loader(group);
    // Booter booter(loader, registrator);

    ASSERT_PASS();
END_UNIT

UNIT(boting_and_submiting)
    // DeviceGroup group;
    // TopicSubscribers susbscriber;
    // BasicRegistrator registrator(susbscriber);
    // BasicLoader loader(group);
    // Booter booter(loader, registrator);

    // LocalDistributor disributor(susbscriber);
    // const size_t nEvents = 1000000;
    // FifoEventStore eventStore(nEvents);

    // EventManager manager(eventStore, disributor);
    // manager.Run();

    // advcpp::ThreadsGroup<eventor::DemoSensor> sensors;
    // // SubmitEvents(sensors ,eventStore, group[0]-> topics, nEvents);

    // SubmitShutdownEvent(manager, susbscriber, eventStore, Location(1,2));
    // manager.ShutDown();

    // // size_t countResults = SumResults(handler);
    // ASSERT_EQUAL(countResults, nEvents);
    


    ASSERT_PASS();
END_UNIT


TEST_SUITE(tip# 1588258 we should ot regret our actions_ 
we responded to each event in our life the best we could with the knwoledge we had)

TEST(smoke_test)
TEST(boting_and_submiting)

END_SUITE