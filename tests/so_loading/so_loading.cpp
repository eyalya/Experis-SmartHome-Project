#include "mu_test.h"

#include <string> //std::string

#include "device_group.hpp" //DeviceGroup

#include "device_builders.hpp" //DeviceBuilders
#include "device_maker.hpp" //SoDeviceMaker 
#include "so_device_registrator.hpp" //SODeviceRegistrator
#include "device_data_factory.hpp" //DeviceDataFactory

#include "configurators.hpp" //IConfigurator

using namespace std;
using namespace smartHome;
using namespace hub;
using namespace booter;
using namespace eventor;

UNIT(so_loading_test)
    
    SODeviceRegistrator registrator;
    DeviceBuilders builders(registrator);
    DeviceMaker deviceMaker(builders);

    auto smokeBuilder = builders[DeviceType("smoke_detector")];
    auto SprinkleBuilder = builders[DeviceType("sprinkler")];
    ASSERT_PASS();
END_UNIT

UNIT(so_device_building_test)
    
    DeviceDataFactory factory;
    factory.LoadDeviceData();
    std::vector<DeviceDataPtr> deviceDatas = factory.GetDeviceData();

    SODeviceRegistrator registrator;
    DeviceBuilders builders(registrator);
    DeviceMaker deviceMaker(builders);

    HsConnectorConfig connectorConfig;
    SystemConnectorApi& connector = connectorConfig.GetConnector();

    DeviceGroup devices;

    for (auto &data : deviceDatas)
    {
        auto builder = builders[data->m_type];
        auto device = builder->Build(data, connector);
        device->Connect();
        devices.AddDevice(device);
    }

    devices.Foreach([](auto device){device->Disconnect();});

    

    ASSERT_PASS();
END_UNIT


TEST_SUITE(tip# 1588258 we should ot regret our actions\n 
                we responded to each event in our life the\n 
                best we could with the knwoledge we had)

    TEST(so_loading_test)
    TEST(so_device_building_test)

END_SUITE