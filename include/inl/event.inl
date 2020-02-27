#ifndef EVENT_INL
#define EVENT_INL

#include "event.hpp"

namespace smartHome
{
namespace eventor
{

inline Topic::Topic(EventType a_type, Location a_location)
: m_type(m_type)
, m_location(a_location)
{
}

inline Event::Event(EventType a_type, Location a_location, TimeStamp a_timeStamp, Payload a_payload = "")
: m_type(a_type)
, m_location(a_location)
, m_timestamp(a_timeStamp)
, m_payload(a_payload)
{
}

inline Location::Location(Floor a_floor, Room a_room)
: m_floorNum(a_floor)
, m_room(a_room)
{
}

} //namespace eventor
} //namespace smartHome

#endif //EVENT_INL