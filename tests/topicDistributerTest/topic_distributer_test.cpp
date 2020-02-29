#include "mu_test.h"

#include <string> //std::string
#include <memory> //make_shared

#include "itopic_distributer.hpp"
#include "isubscribers_register.hpp"
#include "topic_subscribers.hpp" //TopicSubscribers
#include "ievent_contorller.hpp"
#include "event_manager.hpp"
#include "thread_pool.hpp"
#include "events_pool.hpp"
#include "demo_controller.hpp"

using namespace std;
using namespace smartHome;
using namespace eventor;
using namespace hub;
using namespace advcpp;



UNIT(smoke_test)
    TopicSubscribers subscribers;
    ThreadPool<> pool;
    EventManger manager(pool);
    EventsPool eventPool();

    manager.ShutDown();
    ASSERT_PASS();

END_UNIT

UNIT(events_flow)
    TopicSubscribers subscribers;
    ThreadPool<> pool;
    EventManger manager(pool);
    EventsPool eventPool(subscribers, pool);

    EventType type = 1;
    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    Event event(type, location, string("test"));

    string name("register");
    std::shared_ptr<IEventController> demo = make_shared<DemoController>(name, location);
    subscribers.RegisterSubscriber(demo, Topic(type, location));

    const size_t nEvents = 5;
    for (size_t i = 0; i < nEvents; ++i)
    {
        eventPool.Submit(make_shared<Event>(event));
    }


    manager.ShutDown();
    ASSERT_PASS();

END_UNIT

TEST_SUITE(tip# 1588258 we should ot regret our actions_ 
we responded to each event in our life the best we could with the knwoledge we had)

TEST(smoke_test)
TEST(events_flow)

END_SUITE