#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <vector> //std::vector
#include <string> //std::string
#include <unordered_map> //std::unordered_map
#include <memory> //shared_ptr, std::enable_shared_from_this

#include "event_base.hpp" //Topic, Location
#include "ievent_handler.hpp" //HandlerPtr
#include "isubscribers_register.hpp" //ISubscribersRegister

namespace smartHome {
namespace hub {

class Device : public std::enable_shared_from_this<Device>
{
public:
    typedef std::shared_ptr<IEventHandler> HandlerPtr;

    Device(std::string const& a_name, Location a_location, size_t a_hashSize = 30);

    void RegisterHandlerToTopic(Topic a_topic, HandlerPtr a_handler); 
    void SubscribeTopics(ISubscribersRegister& a_subscriber); 
    HandlerPtr GetHandler(Topic a_topic);

    std::unordered_map<Topic, HandlerPtr, TopicHash> const& GetTopicHandlers();

private:
    std::unordered_map<Topic, HandlerPtr, TopicHash> m_topicHandlers;
    Location m_location;
    std::string m_name;
};

} //namespace smartHome
} //namespace hub

#endif //DEVICE_HPP