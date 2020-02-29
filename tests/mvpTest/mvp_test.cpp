#include "mu_test.h"
#include "light_event_factory.hpp"
#include "booter.hpp"
#include "itopic_distributer.hpp"
#include "isubscribers_register.hpp"
#include "topic_subscribers.hpp" //TopicSubscribers
#include "ievent_contorller.hpp"
#include "event_manager.hpp"
#include "thread_pool.hpp"
#include "events_pool.hpp"
#include "demo_controller.hpp"


using namespace smartHome;
using namespace advcpp;
using namespace std;

UNIT(no_app_test)
    hub::TopicSubscribers subscribers;
    hub::EventsPool eventPool(subscribers);
    hub::EventManger manager(eventPool);
    eventor::LightEventFactory factory(eventPool);
    hub::Booter boot(subscribers);

    eventor::DemoSensor censor(factory);
    
    boot.LoadControllers();
    censor.Run();
    manager.ShutDown();
    ASSERT_PASS();
END_UNIT

TEST_SUITE(test mvp)
    TEST(no_app_test)
END_SUITE