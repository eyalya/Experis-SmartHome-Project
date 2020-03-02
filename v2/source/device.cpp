#include "device.hpp"

namespace smartHome {
namespace hub {

Device::Device(std::string const& a_name, eventor::Location a_location)
: m_topics()
, m_location(a_location)
, m_name(a_name)
{
    
}

void Device::RegisterToTopic()
//TODO: fill functions
{

}


} //namespace smartHome
} //namespace hub
