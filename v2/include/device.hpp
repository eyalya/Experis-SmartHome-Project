#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <vector> //std::vector
#include <string> //std::string
#include <unordered_map> //std::unordered_map
#include <memory> //shared_ptr

#include "event_base.hpp" //Topic, Location
#include "ievent_handler.hpp"

namespace smartHome {
namespace hub {

class Device
{
public:
    typedef std::shared_ptr<IEventHandler> HandlerPtr;

    Device(std::string const& a_name, Location a_location, size_t a_hashSize = 30);

    void RegisterToTopic(Topic a_topic, HandlerPtr a_handler); //TODO:cahnge to shared ptr
    HandlerPtr GetHandler(Topic a_topic);

    std::unordered_map<Topic, HandlerPtr> const& GetTopicHandlers();

private:
    std::unordered_map<Topic, HandlerPtr> m_topicHandlers;
    Location m_location;
    std::string m_name;
};

} //namespace smartHome
} //namespace hub

#endif //DEVICE_HPP