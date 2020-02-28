#ifndef EVENT_INL
#define EVENT_INL

#include <string> //string, to_string
#include "hash_funcs.hpp" //
#include "event.hpp"

namespace smartHome
{
namespace eventor
{

inline Topic::Topic(EventType a_type, Location a_location)
: m_type(a_type)
, m_location(a_location)
{
    GenerateID();
}

inline Event::Event(EventType a_type, Location a_location, TimeStamp a_timeStamp, Payload a_payload)
: m_type(a_type)
, m_timestamp(a_timeStamp)
, m_location(a_location)
, m_payload(a_payload)
{
}

inline Location::Location(Floor a_floor, Room a_room)
: m_floorNum(a_floor)
, m_room(a_room)
{
}

inline void Topic::GenerateID()
{
    m_id = std::to_string(m_type);
    m_id += std::to_string(m_location.m_floorNum);
    m_id += std::to_string(m_location.m_room);
}

} //namespace eventor
} //namespace smartHome

#endif //EVENT_INL