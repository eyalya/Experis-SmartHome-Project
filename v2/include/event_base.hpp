#ifndef EVENT_BASE_HPP
#define EVENT_BASE_HPP

#include <memory> //std::shared_ptr

#include "ievent.hpp"

namespace smartHome {

typedef int Floor;
typedef int Room;

struct Location
{
    Location(Floor a_floor, Room a_room);
    Floor m_floorNum;
    Room m_roomNum;
};

class EventBase : public IEvent
{
public: 
    virtual Location const& GetLocation() const;
    virtual EventType const& GetType() const;
    virtual TimeStamp const& GetTimeStamp() const;

protected:
    EventBase(EventType a_type, Location a_location, TimeStamp a_timeStamp);
    EventBase(EventBase const& a_other) = delete;
    EventBase& operator=(EventBase const& a_other) = delete;

private:
    const EventType m_type;
    const Location m_location;
    const TimeStamp m_timestamp;
};

struct Topic
{
    Topic(EventType a_type, Location a_location);
    Topic(std::shared_ptr<IEvent> a_event);
    
    EventType m_type;
    Location m_location;
    std::string m_id; //FIXME: maybe remove, used only in hash function

private:
    void GenerateID();
};

} //namespace smartHome

#include "inl/event_base.inl"

#endif //EVENT_BASE_HPP