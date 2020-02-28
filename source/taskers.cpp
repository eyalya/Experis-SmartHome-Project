#include "taskers.hpp"

namespace advcpp
{
class DestoryerTask;

Tasker::Tasker(WaitableQ<TaskPtr>& a_taskQue)
: m_taskQue(a_taskQue)
, m_state(true)
{
}

void Tasker::Run() noexcept
{
    while (m_state == true)
    {
        TaskPtr task;
        // if (dynamic_cast<DestoryerTask>  (task))
        m_taskQue.Dequeue(task);
        task->Run();
    }
}

} // namespace advcpp

