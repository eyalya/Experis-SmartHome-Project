#include "mu_test.h"

#include <string> //std::string
#include <unistd.h> //sleep

#include "booter.hpp" //Booter
#include "topic_subscribers.hpp" //TopicSubscribers
#include "fifo_event_store.hpp" //FifoEventStore
#include "lite_event_reciver.hpp" //LiteEventReciver 
#include "thread_group.hpp" //ThreadGroup

#include "local_distributor.hpp" //LocalDistributor
#include "event_manager.hpp" //EventManager

#include "device_group.hpp" //DeviceGroup
#include "device_data_factory.hpp" //DeviceDataFactory
#include "system_connector.hpp" //SystemConnectors

#include "device_builders.hpp" //DeviceBuilders
#include "so_device_maker.hpp" //SoDeviceMaker 
#include "so_loader.hpp" //SODeviceRegistrator

#include "system_events.hpp" //g_shutDownTopic


using namespace std;
using namespace smartHome;
using namespace hub;
using namespace booter;
using namespace eventor;

UNIT(booting_with_so)
    DeviceDataFactory factory;
    SODeviceRegistrator regirtrator;
    DeviceBuilders builder(regirtrator);
    SoDeviceMaker deviceMaker(builder);

    TopicSubscribers susbscriber;
    FifoEventStore fifoEventStore;
    LiteEventReciver eventReciever(fifoEventStore);
    SystemConnectors connectors(susbscriber, eventReciever);

    Booter booter(connectors, deviceMaker, factory);
    booter.BootSystem();

    LocalDistributor disributor(susbscriber);
    EventManager manager(fifoEventStore, disributor);
    manager.Run();
    
    booter.DisconnectDevices();
    manager.Pause();
    connectors.GetEventReciever().RecvEvent(std::make_shared<systemEvents::SystemEvent>
                                                (
                                                    systemEvents::g_shutDownTopic.m_type, 
                                                    systemEvents::g_shutDownTopic.m_location
                                                ));
    manager.ShutDown();
    ASSERT_PASS();
END_UNIT


TEST_SUITE(tip# 1588258 we should ot regret our actions\n 
                we responded to each event in our life the\n 
                best we could with the knwoledge we had)

TEST(booting_with_so)

END_SUITE