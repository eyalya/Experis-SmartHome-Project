#ifndef IEVENT_HPP
#define IEVENT_HPP

#include <string> //std::string

namespace smartHome {
namespace eventor {

typedef std::string TimeStamp;
typedef std::string EventType;
typedef std::string Payload;

struct Location;

class IEvent
{
public:
    virtual ~IEvent() = default;

    virtual Location& Location();
    virtual EventType& Type();
    virtual TimeStamp& TimeStamp();
    //virtual Payload& TimeStamp(); //TODO: solution without dynamic cast
};

} //namespace eventor
} //namespace smartHome


#endif // !IEVENT_HPP

