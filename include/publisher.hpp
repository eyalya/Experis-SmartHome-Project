#ifndef PUBLISHER_HPP
#define PUBLISHER_HPP

#include <unordered_map> //std::unordered_map
#include <unordered_set> //std::unordered_set

#include "ievent.hpp" //IEvent
// #include "dis

namespace smarthome 
{
namespace hub 
{

class Publisher
{
using DSMap = std::unordered_map<DispatcherGroup, EventType>;
using EventTypeMap = std::unordered_map<EventType, DispatcherGroup>;
public:
    Publisher(/* args */);
    ~Publisher();

private:
    std::uns

};
Publisher::Publisher(/* args */)

{
}

Publisher::~Publisher()
{
}


} //namespace hub 
} //namespace smarthome
#endif //PUBLISHER_HPP