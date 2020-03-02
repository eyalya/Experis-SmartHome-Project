#include "mu_test.h"
#include "fifo_event_store.hpp"
#include "lite_event_reciver.hpp"
#include "demo_sensor.hpp"
#include "thread.hpp"

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

    vector<eventor::DemoSensor> sensors;
    vector<unique_ptr<Thread> > threads;

    for (size_t i = 0; i < 10; i++)
    {
        sensors.emplace_back(eventReciver, Location(5, 3), "test event", 50);
        threads.emplace_back(make_unique<Thread>(&sensors[i]));
    }

    ASSERT_EQUAL(eventStore.NumOfEventsInStore(), 350);

END_UNIT 

TEST_SUITE(test light factor)

    TEST(smoke_test)
    TEST(few_censors)

END_SUITE