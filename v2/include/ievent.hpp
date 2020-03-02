#ifndef IEVENT_HPP
#define IEVENT_HPP

#include <string> //std::string

namespace smartHome {

typedef std::string TimeStamp;
typedef std::string EventType;
typedef std::string Payload;

struct Location;

class IEvent
{
public:
    virtual ~IEvent() = default;

    virtual Location const& GetLocation() const = 0 ;
    virtual EventType const& GetType() const = 0;
    virtual TimeStamp const& GetTimeStamp() const = 0;
    
    //virtual Payload& TimeStamp(); //TODO: solution without dynamic cast
};

} //namespace smartHome


#endif // !IEVENT_HPP

