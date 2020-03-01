#ifndef EVENT_HPP
#define EVENT_HPP

#include "ievent.hpp"

namespace smartHome {
namespace eventor {

typedef int Floor;
typedef int Room;

struct Location
{
    Floor m_floorNum;
    Room m_roomNum;
};

struct Event
{
    Event(EventType a_type, Location a_location, TimeStamp a_timeStamp, Payload a_payload = "");

    TimeStamp m_timestamp;
    EventType m_type;
    Location m_location;
    Payload m_payload;
};

struct Topic
{
    Topic(EventType a_type, Location a_location);
    
    EventType m_type;
    Location m_location;
    std::string m_id; //FIXME: maybe remove, used only in hash function

private:
    void GenerateID();
};

} //namespace eventor
} //namespace smartHome

#include "inl/event_base.inl"
#endif //EVENT_HPP