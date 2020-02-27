#ifndef EVENT_HPP
#define EVENT_HPP

#include <string> //std::string

typedef std::string TimeStamp;
typedef int Floor;
typedef int Room;
typedef int EventType;//TODO: figure how
typedef std::string Payload;

struct Location
{
    Floor m_floorNum;
    Room m_room;
};

struct Event
{
    EventType m_type;
    TimeStamp m_timestamp;
    Location m_location;
    Payload m_payload;
};




#endif //EVENT_HPP