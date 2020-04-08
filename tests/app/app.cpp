#include "mu_test.h"

#include <string> //std::string
#include <unistd.h> //sleep

#include "configurators.hpp" //IConfigurator
#include "booter.hpp" //Booter
#include "event_manager.hpp" //EventManager

#include "system_events.hpp" //g_shutDownTopic


using namespace std;
using namespace smartHome;
using namespace hub;
using namespace booter;
using namespace eventor;

UNIT(smoke_test)

    HsBooterConfig booterConfig;
    HsConnectorConfig connectorConfig;
    SystemConnectorApi& connector = connectorConfig.GetConnector();

    Booter booter(connector, booterConfig.GetDeviceMaker(), booterConfig.GetDataFactory());
    booter.BootSystem();

    HsDistributerConfig distributorConfig;
    EventManager manager(connector.GetEventRemover(), distributorConfig.GetDistributor());

    manager.Run();
    sleep(5);
    booter.DisconnectDevices();
    manager.Pause();
    connector.GetEventReciever().RecvEvent(std::make_shared<systemEvents::SystemEvent>
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
    
    TEST(smoke_test)

END_SUITE