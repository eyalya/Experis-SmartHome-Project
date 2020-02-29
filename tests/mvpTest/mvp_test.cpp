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

UNIT(full_test)
    hub::TopicSubscribers subscribers;
    hub::EventsPool eventPool(subscribers);
    hub::EventManger manager(eventPool);
    eventor::LightEventFactory factory(eventPool);
    eventor::DemoSensor censor(factory);
    hub::Booter boot(subscribers);

    EventType type = 0;
    Floor floor = 5;
    Room room = 2;
    eventor::Location location(floor, room);

    string name("register");
    shared_ptr<hub::IEventController> demo = make_shared<hub::DemoController>(name, location);
    subscribers.RegisterSubscriber(demo, eventor::Topic(type, location));
    boot.LoadControllers();
    censor.Run();
    manager.ShutDown();
    ASSERT_PASS();

END_UNIT

TEST_SUITE(test mvp)

TEST(full_test)

END_SUITE