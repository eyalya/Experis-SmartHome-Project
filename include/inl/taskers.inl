#ifndef TASKERS_INL
#define TASKERS_INL

#include <iostream>

#include "taskers.hpp"

namespace advcpp
{
inline void Tasker::ShutDown()
{
    m_state = false;
}

inline TaskerPtr TaskerFactory(WaitableQ<TaskPtr>& a_taskQue)
{
    return std::shared_ptr<ITaskers> (new  Tasker(a_taskQue)); 
}
    

} // namespace advcpp

#endif //TASKERS_INL
