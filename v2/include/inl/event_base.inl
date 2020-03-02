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

size_t Topic::hash() const
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

} //namespace smartHome

#endif //EVENT_BASE_INL