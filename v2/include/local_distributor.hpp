#ifndef IDISTRIBUTOR_HPP
#define IDISTRIBUTOR_HPP

#include "ievent.hpp" 
#include <memory> //std::shared_ptr

namespace smartHome {
namespace eventor {

class IEventReciver
{
public:
    typedef std::shared_ptr<IEvent> EventPtr;

    virtual ~IEventReciver() = default;
    virtual void DistributeToDevice(EventPtr a_event) = 0;

protected:
    IEventReciver() = default;
    IEventReciver(IEventReciver const& a_other) = default;
    IEventReciver& operator=(IEventReciver const& a_other) = default;
};

} // namespace eventor
} // namespace smartHome

#endif //IDISTRIBUTOR_HPP