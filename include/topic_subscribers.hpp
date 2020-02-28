#ifndef TOPIC_SUBSCRIBERS_HPP
#define TOPIC_SUBSCRIBERS_HPP

#include "event.hpp" //Topic
#include "hash_table.hpp" //HashTable
#include "ievent_contorller.hpp" //eventControllers
#include "itopic_distributer.hpp" //ITopicDistributer
#include "isubscribers_register.hpp " //ISubscribersRegister
#include "controller_container.hpp" //ControllerContainer


namespace smartHome 
{
namespace hub 
{

class TopicSubscribers: public ITopicDistributer, public ISubscribersRegister {
public:
    TopicSubscribers() = default;

    ~TopicSubscribers() = default;
    TopicSubscribers(TopicSubscribers const& a_rhs) = default;
    TopicSubscribers& operator=(TopicSubscribers const& a_rhs) = default;

    virtual void RegisterSubscriber(IEventController& a_controller, Topic const& a_topic);
    virtual void UnRegisterSubscriber(IEventController& a_controller, Topic const& a_topic);

    virtual void ExecuteTopic(eventor::Topic const& a_topic, Event a_event) const;

private:
    typedef HashTable<Topic, ControllerContainer>::iterator Iterator;

private:
    HashTable<Topic, ControllerContainer> m_subscribers;
};


} //namespace hub
} //namespace smartHome 


#endif //TOPIC_SUBSCRIBERS_HPP