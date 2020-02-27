#ifndef TOPIC_SUBSCRIBERS_HPP
#define TOPIC_SUBSCRIBERS_HPP

#include "event.hpp"
#include "hash_table.hpp" //HashTable
#include "ievent_contorller.hpp" //eventControllers

namespace advcpp 
{

class TopicSubscribers {
public:
    explicit TopicSubscribers();

    ~TopicSubscribers() = default;
    TopicSubscribers(TopicSubscribers const& a_rhs) = default;
    TopicSubscribers& operator=(TopicSubscribers const& a_rhs) = default;

    AddSubscriber(IEventController& a_contoroller);

private:
    HashTable m_subscribers;
};

} //namespace advcpp 

// #include "TopicSubscribers.inl"
#endif //TOPIC_SUBSCRIBERS_HPP