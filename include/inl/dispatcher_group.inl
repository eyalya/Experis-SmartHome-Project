#ifndef DISPATCHER_GROUP_INL
#define DISPATCHER_GROUP_INL

#include "dispatcher_group.hpp"

namespace smartHome {
namespace hub {

template <typename Executor>
DispatcherGroup<Executor>::DispatcherGroup()
: m_eventQ(DEFAULT_QUEUE_SIZE)
, m_publisher() //T
{

}

template <typename Executor>
void DispatcherGroup<Executor>::AddHandler(booter::EventHandlerPtr a_handler)
{
    m_handlers
}

} //namespace hub
} //namespace smartHome

#endif //DISPATCHER_GROUP_INL