#ifndef DEMO_CONFIG_HPP
#define DEMO_CONFIG_HPP

#include <vector> //std::vector
#include <memory> //std::shared_ptr

#include "ievent_handler.hpp" //IEventHandler
#include "event_base.hpp" //EventPtr
#include "topic_subscribers.hpp" //TopicSubscribers
#include "event_manager.hpp" //EventManager
#include "fifo_event_store.hpp" //FifoEventStore
#include "thread_group.hpp" //ThreadGroup
#include "demo_device.hpp" //demoDevice, DemoHandler
#include "demo_sensor.hpp" //DemoSensor


namespace smartHome {
namespace booter {

void CreateTopics(std::vector<Topic>& a_topics, size_t a_nTopics);

void RegisterHandlers(hub::TopicSubscribers& a_subscribers, std::vector<std::shared_ptr<hub::IEventHandler> >& a_handlers, 
                        hub::DeviceGroup& a_devices, std::vector<Topic> const& a_topics);

void CreateDevices(hub::DeviceGroup& a_devices, size_t a_nDevices);

void CreateSensors(advcpp::ThreadsGroup<eventor::DemoSensor>& a_sensors ,eventor::FifoEventStore& a_eventStore, std::vector<Topic> const& a_topics
                    ,size_t a_nEvents);

size_t SumResults(std::vector<std::shared_ptr<hub::IEventHandler> > a_handlers);

void SubmitShutdownEvent(hub::EventManager& a_manager, hub::TopicSubscribers& a_subscribers, 
                        eventor::FifoEventStore& a_eventStore, Location const& a_location);

} //namespace smartHome
} //namespace booter
#endif //DEMO_DEVICE_HPP