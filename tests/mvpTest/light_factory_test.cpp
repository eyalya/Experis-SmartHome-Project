#include "mu_test.h"
#include "light_event_factory.hpp"
#include "topic_subscribers.hpp"
#include "booter.hpp"

using namespace smartHome;
using namespace advcpp;


UNIT(full_test)
    WaitableQ<eventor::LightEventFactory::EventPtr> eventQ(50);
    eventor::LightEventFactory factory(eventQ);
    eventor::DemoSensor censor(factory);

    hub::TopicSubscribers sub;
    hub::Booter boot(sub);

    boot.LoadControllers();
    censor.Run();

END_UNIT

TEST_SUITE(test mvp)

TEST(full_test)

END_SUITE