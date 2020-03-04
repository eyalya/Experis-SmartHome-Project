#include "mu_test.h"

#include <string> //std::string

#include "booter.hpp" //Booter
#include "basic_registrator.hpp" //BasicRegistrator
#include "basic_loader.hpp" //BasicLoader
#include "topic_subscribers.hpp" //TopicSubscribers
#include "demo_device.hpp" //demoDevice, DemoHandler
#include "device_group.hpp" //DeviceGroup


using namespace std;
using namespace smartHome;
using namespace hub;
using namespace booter;


UNIT(smoke_test)
    DeviceGroup group;
    TopicSubscribers susbscriber;
    BasicRegistrator registrator(susbscriber);
    BasicLoader loader(group);
    Booter booter(loader, registrator);

    ASSERT_PASS();
END_UNIT


TEST_SUITE(tip# 1588258 we should ot regret our actions_ 
we responded to each event in our life the best we could with the knwoledge we had)

TEST(smoke_test)

END_SUITE