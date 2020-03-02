#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <vector> //std::vector
#include <string> //std::string

#include "event.hpp" //location

namespace smartHome {
namespace hub {

class Device
{
public:
    Device(std::string const& a_name, eventor::Location a_location);

    void RegisterToTopic();
    //EventHandler GetHandler(eventor::Topic a_topic);

private:
    std::vector<eventor::Topic> m_topics;
    eventor::Location m_location;
    std::string m_name;
};

} //namespace smartHome
} //namespace hub

#endif //DEVICE_HPP