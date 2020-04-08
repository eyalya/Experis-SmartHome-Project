#include "mu_test.h"

#include <string> //std::string
#include <unistd.h> //sleep

#include "booter.hpp" //Booter
#include "publisher.hpp" //Publisher
#include "fifo_event_store.hpp" //FifoEventStore
#include "lite_event_reciver.hpp" //LiteEventReciver 
#include "thread_group.hpp" //ThreadGroup

#include "local_distributor.hpp" //LocalDistributor
#include "event_manager.hpp" //EventManager

#include "device_group.hpp" //DeviceGroup
#include "device_data_factory.hpp" //DeviceDataFactory
#include "system_connector.hpp" //SystemConnectors

#include "device_builders.hpp" //DeviceBuilders
#include "device_maker.hpp" //SoDeviceMaker 
#include "so_device_registrator.hpp" //SODeviceRegistrator

#include "configurators.hpp" //IConfigurator

#include "system_events.hpp" //g_shutDownTopic


using namespace std;
using namespace smartHome;
using namespace hub;
using namespace booter;
using namespace eventor;

UNIT(smoke_test)

    DeviceDataFactory factory;
    SODeviceRegistrator registrator;
    DeviceBuilders builders(registrator);
    DeviceMaker deviceMaker(builders);

    HsConnectorConfig connectorConfig;
    SystemConnectorApi& connector = connectorConfig.GetConnector();

    Booter booter(connector, deviceMaker, factory);
    booter.BootSystem();

    LocalDistributor distributor(connector.GetFinder());
    EventManager manager(connector.GetEventRemover(), distributor);
    ASSERT_PASS();
END_UNIT

UNIT(booting_with_so)
    DeviceDataFactory factory;
    SODeviceRegistrator regirtrator;
    DeviceBuilders builder(regirtrator);
    DeviceMaker deviceMaker(builder);

    Publisher publisher;
    FifoEventStore fifoEventStore;
    LiteEventReciver eventReciever(fifoEventStore);
    SystemConnectors connectors(publisher, eventReciever, publisher, fifoEventStore);

    Booter booter(connectors, deviceMaker, factory);
    booter.BootSystem();

    LocalDistributor disributor(connectors.GetFinder());
END_UNIT


TEST_SUITE(tip# 1588258 we should ot regret our actions\n 
                we responded to each event in our life the\n 
                best we could with the knwoledge we had)
    
    TEST(smoke_test)
    TEST(booting_with_so)

END_SUITE