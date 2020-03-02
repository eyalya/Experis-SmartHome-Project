#ifndef IEVENT_STORE_ADDER_HPP
#define IEVENT_STORE_ADDER_HPP

#include <memory> //std::shared_ptr

#include "ievent.hpp"

namespace smartHome {
namespace eventor {

class IEventStoreAdder
{
public: 
    virtual ~IEventStoreAdder() = default;

    virtual void AddEvent(std::shared_ptr<IEvent> a_event) = 0;

protected:
    IEventStoreAdder() = default;
    IEventStoreAdder(IEventStoreAdder const& a_other) = default;
    IEventStoreAdder& operator=(IEventStoreAdder const& a_other) = default;
};

} // namespace eventor
} //namespace smartHome

#endif //IEVENT_STORE_ADDER_HPP