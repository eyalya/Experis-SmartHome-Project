#

#ifndef IEVENT_HPP
#define IEVENT_HPP

#include <string> //std::string

namespace smartHome {

class IEvent;

typedef std::string TimeStamp;
typedef std::string EventType;
typedef std::string Payload;
typedef std::shared_ptr<IEvent> EventPtr;

struct Location;

//template<typename PayloadType> //TODO: add template
class IEvent
{
public:
    virtual ~IEvent() = default;

    virtual Location const& GetLocation() const = 0 ;
    virtual EventType const& GetType() const = 0;
    virtual TimeStamp const& GetTimeStamp() const = 0;

    virtual std::ostream& Print(std::ostream& a_os) const = 0;
    
    // virtual Payload& GetPayload() = 0; //TODO: solution without dynamic cast
};

} //namespace smartHome


#endif // !IEVENT_HPP

