#ifndef DISPATCHER_GROUP_HPP
#define DISPATCHER_GROUP_HPP

#include "waitable_queue.hpp"
#include "common_types.hpp"

namespace smartHome {
namespace hub {

class DispatcherGroup
{
public:
    DispatcherGroup();

    Add(EventHandlerPtr)

private:
    advcpp::WaitableQ<EventPtr> m_eventQ;
};
    
} // namespace hub
} // namespace smartHome


#endif //DISPATCHER_GROUP_HPP