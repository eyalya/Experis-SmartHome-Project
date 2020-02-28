#ifndef EVENT_HPP
#define EVENT_HPP

#include <string> //std::string

typedef std::string TimeStamp;
typedef int Floor;
typedef int Room;
typedef int EventType;//TODO: figure how
typedef std::string Payload;

namespace smartHome
{
namespace eventor
{

struct Location
{
    Location(Floor a_floor, Room a_room);

    Floor m_floorNum;
    Room m_room;
};

struct Event
{
    Event(EventType a_type, Location a_location, TimeStamp a_timeStamp, Payload a_payload = "");

    EventType m_type;
    TimeStamp m_timestamp;
    Location m_location;
    Payload m_payload;
};

struct Topic
{
    Topic(EventType a_type, Location a_location);
    EventType m_type;
    Location m_location;

    size_t hash() const;
};

} //namespace eventor
} //namespace smartHome

#include "./inl/event.inl"
#endif //EVENT_HPP