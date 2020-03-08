#include "mu_test.h"

#include <string> //std::string

#include "booter.hpp" //Booter
#include "topic_subscribers.hpp" //TopicSubscribers
#include "fifo_event_store.hpp" //FifoEventStore
#include "lite_event_reciver.hpp" //LiteEventReciver 
#include "thread_group.hpp" //ThreadGroup

// #include "local_distributor.hpp" //LocalDistributor

#include "device_group.hpp" //DeviceGroup
#include "smoke_detector.hpp" //SmokeDetector
#include "device_data_factory.hpp" //DeviceDataFactory
#include "system_connector.hpp" //SystemConnectors
#include "hardcoded_device_maker.hpp" //HardCodedDeviceMaker


using namespace std;
using namespace smartHome;
using namespace hub;
using namespace booter;
using namespace eventor;


UNIT(smoke_test)
    // DeviceGroup group;
    DeviceDataFactory factory;
    HardCodedDeviceMaker deviceMaker;

    TopicSubscribers susbscriber;
    FifoEventStore fifoEventStore;
    LiteEventReciver eventReciever(fifoEventStore);
    SystemConnectors connectors(susbscriber, eventReciever);

    Booter booter(connectors, deviceMaker, factory);

    ASSERT_PASS();
END_UNIT

UNIT(boting_and_submiting)
    // DeviceGroup group;

    FifoEventStore fifoEventStore;
    LiteEventReciver eventReciever(fifoEventStore);
    TopicSubscribers susbscriber;
    SystemConnectors connectors(susbscriber, eventReciever);

    DeviceDataFactory factory;
    HardCodedDeviceMaker deviceMaker;
    Booter booter(connectors, deviceMaker, factory);
    booter.BootSystem();
    
    cout << "press key to finish" << endl; 
    int a;
    cin >> a; 
    ASSERT_PASS();
END_UNIT


TEST_SUITE(tip# 1588258 we should ot regret our actions_ 
we responded to each event in our life the best we could with the knwoledge we had)

TEST(smoke_test)
TEST(boting_and_submiting)

END_SUITE