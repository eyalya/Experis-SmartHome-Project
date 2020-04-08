#include "local_distributor.hpp"
#include "ievent_handler.hpp" //IEventHandler
#include "device.hpp" //BaseAgent
#include "dispatcher_group.hpp" 

namespace smartHome {
namespace hub {

LocalDistributor::LocalDistributor(IFindTopicSubscriber& a_subscriberContainer)
: m_subscriberContainer(a_subscriberContainer)
{
}

struct HandleEvent {

    HandleEvent(Topic const& a_topic, std::shared_ptr<IEvent> a_event);

    void operator()(std::shared_ptr<IAgent> a_device);

    Topic m_topic;
    std::shared_ptr<IEvent> m_event;
};

HandleEvent::HandleEvent(Topic const& a_topic, std::shared_ptr<IEvent> a_event)
: m_topic(a_topic)
, m_event(a_event)
{
}

void HandleEvent::operator()(std::shared_ptr<IAgent> a_device)
{
    (void) a_device;
    std::shared_ptr<IEventHandler> handler = a_device->GetHandler(m_topic);
    handler->Handle(m_event);
}

void LocalDistributor::DistributeToDevice(EventPtr a_event)
{
    Topic topic(a_event);
    auto dGroups = m_subscriberContainer.FindTopic(topic);
    if (dGroups){
        for (auto dgroup: *dGroups)
        {
            dgroup->AddEvent(a_event);
        }   
    }
}


} // namespace hub
} // namespace smartHome
