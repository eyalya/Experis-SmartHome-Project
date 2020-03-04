#include "mu_test.h"

#include <string> //std::string
#include <memory> //make_shared
#include <unistd.h> //sleep

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

void CreateTopics(std::vector<Topic>& a_topics, size_t a_nTopics)
{
    EventType type = 1;
    Floor floor = 0;
    Room room = 0;
    
    while(a_nTopics --> 0)
    {
        // cout << "create topic: 1" << floor << room << endl;
        a_topics.push_back(Topic(type, Location(floor, room)));
        ++room;            
        ++floor;
    }
}

void CreateControllers(TopicSubscribers& subscribers, ControllerContainer& a_controllers, std::vector<Topic> const& a_topics, size_t a_nControllers)
{
    string name("temp");
    const size_t topicsSize = a_topics.size();
    Topic temp = a_topics[0];

    for (size_t i = 0; i < a_nControllers; ++i)
    {
        std::shared_ptr<IEventController> demo = make_shared<DemoController>(name, temp.m_location);
        a_controllers.AddController(demo);
        subscribers.RegisterSubscriber(demo, temp);
        temp = a_topics[i % topicsSize];
    }
}

void SubmitEvents(EventsPool& a_pool, std::vector<Topic> const& a_topics, size_t a_nEvents)
{
    EventType type = 1;

    const size_t topicsSize = a_topics.size();
    Topic temp = a_topics[0];

    for (size_t i = 0; i < a_nEvents; ++i)
    {
        temp = a_topics[i % topicsSize];
        a_pool.Submit(make_shared<Event>(type, temp.m_location, string("test")));
        // cout << "submitting event: 1" << temp.m_location.m_floorNum << temp.m_location.m_room << endl;
    }
}

size_t SumResults(ControllerContainer const& a_controllers)
{
    size_t count = 0;
    const size_t controllersSize = a_controllers.Size();

    for (size_t i = 0; i < controllersSize; ++i)
    {
        DemoController* controller = static_cast<DemoController*>(a_controllers[i].get());
        // cout << "controller run: " << controller->GetNRuns() << endl;
        count += controller->GetNRuns();
    }
    return count;
}

UNIT(smoke_test)
    TopicSubscribers subscribers;
    EventsPool eventPool(subscribers);
    EventManager manager(eventPool);

    manager.ShutDown();
    ASSERT_PASS();

END_UNIT

UNIT(events_flow_one_topic)
    TopicSubscribers subscribers;
    EventsPool eventPool(subscribers, 10);
    EventManager manager(eventPool);

    EventType type = 1;
    Floor floor = 2;
    Room room = 3;
    Location location(floor, room);
    Event event(type, location, string("test"));

    string name("register");
    std::shared_ptr<IEventController> demo = make_shared<DemoController>(name, location);
    subscribers.RegisterSubscriber(demo, Topic(type, location));

    const size_t nEvents = 100000;
    for (size_t i = 0; i < nEvents; ++i)
    {
        eventPool.Submit(make_shared<Event>(event));
    }

    manager.ShutDown();
   
    DemoController* controller = static_cast<DemoController*>(demo.get());
    ASSERT_EQUAL(controller->GetNRuns(), nEvents);

END_UNIT

UNIT(events_flow_mul_topic)
    TopicSubscribers subscribers;
    EventsPool eventPool(subscribers, 1);
    EventManager manager(eventPool);

    const size_t nTopics = 1000;
    vector<Topic> topics;
    CreateTopics(topics, nTopics);

    ControllerContainer controllers;
    const size_t factor = 3;
    const size_t nControllers = nTopics * factor;
    CreateControllers(subscribers, controllers, topics, nControllers);

    const size_t nEvents = 100000;
    SubmitEvents(eventPool, topics, nEvents);

    manager.ShutDown();
   
    size_t countResults = SumResults(controllers);
    ASSERT_EQUAL(countResults, nEvents * factor);

END_UNIT

TEST_SUITE(tip# 1588258 we should not regret our actions_ 
we responded to each event in our life the best we could with the knwoledge we had)

TEST(smoke_test)
TEST(events_flow_one_topic)
TEST(events_flow_mul_topic)

END_SUITE