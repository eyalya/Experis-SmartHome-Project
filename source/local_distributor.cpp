#include "local_distributor.hpp"
#include "ievent_handler.hpp" //IEventHandler
#include "device.hpp" //BaseAgent
#include "device_group.hpp" //DeviceGroup

namespace smartHome {
namespace hub {

LocalDistributor::LocalDistributor(IFindTopicSubscriber& a_subscriberContainer)
: m_subscriberContainer(a_subscriberContainer)
{
}

struct HandleEvent {

    HandleEvent(Topic const& a_topic, std::shared_ptr<IEvent> a_event);

    void operator()(std::shared_ptr<BaseAgent> a_device);

    Topic m_topic;
    std::shared_ptr<IEvent> m_event;
};

HandleEvent::HandleEvent(Topic const& a_topic, std::shared_ptr<IEvent> a_event)
: m_topic(a_topic)
, m_event(a_event)
{
}

void HandleEvent::operator()(std::shared_ptr<BaseAgent> a_device)
{
    (void) a_device;
    std::shared_ptr<IEventHandler> handler = a_device->GetHandler(m_topic);
    handler->Handle(m_event);
}

void LocalDistributor::DistributeToDevice(EventPtr a_event)
{
    Topic topic(a_event);
    DeviceGroup dGroup = m_subscriberContainer.FindTopic(topic);
    HandleEvent handler(topic, a_event);
    dGroup.Foreach<HandleEvent>(handler);
}


} // namespace hub
} // namespace smartHome
