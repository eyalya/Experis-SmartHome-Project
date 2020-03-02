#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <vector> //std::vector
#include <string> //std::string

#include "event_base.hpp" //location

namespace smartHome {
namespace hub {

class Device
{
public:
    Device(std::string const& a_name, Location a_location);

    void RegisterToTopic();
    //EventHandler GetHandler(Topic a_topic);

private:
    std::vector<Topic> m_topics;
    Location m_location;
    std::string m_name;
};

} //namespace smartHome
} //namespace hub

#endif //DEVICE_HPP