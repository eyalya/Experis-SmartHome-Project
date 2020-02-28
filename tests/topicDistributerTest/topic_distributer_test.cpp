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
    Event event(1, Location(1, 2), string("test"));

    const size_t nEvents = 10000;
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