#include "mu_test.h"
#include "fifo_event_store.hpp"
#include "lite_event_reciver.hpp"
#include "demo_sensor.hpp"
#include "thread.hpp"
#include "thread_group.hpp"

#include <memory>

using namespace smartHome;
using namespace advcpp;
using namespace std;

UNIT(smoke_test)

    eventor::FifoEventStore eventStore;
    eventor::LiteEventReciver eventReciver(eventStore);

    eventor::DemoSensor sensor(eventReciver, Location(5, 3), "test event", 50);

    sensor.Run();

    ASSERT_EQUAL(eventStore.NumOfEventsInStore(), 50);
END_UNIT 

UNIT(few_censors)

    eventor::FifoEventStore eventStore(500);
    eventor::LiteEventReciver eventReciver(eventStore);

    ThreadsGroup<eventor::DemoSensor> sensors;
    Location loc(5, 3);
    int numOfEvents = 40;

    sensors.AddThreads(10, eventReciver, loc, "test event", numOfEvents);

    sensors.JoinAll();
    ASSERT_EQUAL(eventStore.NumOfEventsInStore(), 400);

END_UNIT 

TEST_SUITE(test light factor)
    TEST(smoke_test)
    TEST(few_censors)
END_SUITE