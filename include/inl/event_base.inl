#ifndef EVENT_BASE_INL
#define EVENT_BASE_INL

#include <string> //string, to_string

#include "event_base.hpp"
#include "hash_funcs.hpp"

namespace smartHome {

inline Topic::Topic(EventType a_type, Location a_location)
: m_type(a_type)
, m_location(a_location)
{
    GenerateID();
}

inline Topic::Topic(std::shared_ptr<IEvent> a_event)
: m_type(a_event->GetType())
, m_location(a_event->GetLocation())
{
    GenerateID();
}

inline EventBase::EventBase(EventType a_type, Location a_location, TimeStamp a_timeStamp)
: m_type(a_type)
, m_location(a_location)
, m_timestamp(a_timeStamp)
{
}

inline std::ostream& EventBase::Print(std::ostream& a_os) const
{
    a_os << "Type: " << m_type << std::endl;
    a_os << "Room: " << m_location.m_roomNum << std::endl;
    a_os << "Floor: " << m_location.m_floorNum << std::endl;
    a_os << "timestamp: " << m_timestamp << std::endl;
    return a_os;
}

inline Location::Location(Floor a_floor, Room a_room)
: m_floorNum(a_floor)
, m_roomNum(a_room)
{
}

inline void Topic::GenerateID()
{
    m_id = m_type;
    m_id += std::to_string(m_location.m_floorNum);
    m_id += std::to_string(m_location.m_roomNum);
}

inline bool Topic::operator==(Topic const& a_rhs) const
{
    return m_id == a_rhs.m_id;
}

inline size_t Topic::hash()
{
    return advcpp::hash(m_id);
}

inline Location const& EventBase::GetLocation() const
{   
    return m_location;
}

inline EventType const& EventBase::GetType() const
{
    return m_type;
}

inline TimeStamp const& EventBase::GetTimeStamp() const
{
    return m_timestamp;
}

inline std::ostream& operator<<(std::ostream& a_os, EventPtr a_event)
{
    return a_event->Print(a_os);
}

} //namespace smartHome

#endif //EVENT_BASE_INL