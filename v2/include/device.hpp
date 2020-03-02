#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <vector> //std::vector
#include <string> //std::string
#include <unordered_map> //std::unordered_map

#include "event_base.hpp" //Topic, Location

namespace smartHome {
namespace hub {

class Device
{
public:
    Device(std::string const& a_name, Location a_location, size_t a_hashSize = 30);

    void RegisterToTopic(Topic a_topic, IEventHandler* a_handler);
    IEventHandler* GetHandler(Topic a_topic);

private:
    std::unordered_map<Topic, IEventHandler*> m_topicHandlers;
    Location m_location;
    std::string m_name;
};

} //namespace smartHome
} //namespace hub

#endif //DEVICE_HPP