#include "mu_test.h"
#include "light_event_factory.hpp"

using namespace smartHome;
using namespace eventor;
using namespace advcpp;

UNIT(smoke_test)
    WaitableQ<LightEventFactory::EventPtr> eventQ(50);
    LightEventFactory factory(eventQ);
    DemoSensor censor(factory);

    censor.Run();

    ASSERT_EQUAL(eventQ.Size(), 30);
END_UNIT

TEST_SUITE(test light factor)

TEST(smoke_test)

END_SUITE