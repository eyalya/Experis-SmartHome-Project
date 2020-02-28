#ifndef TASK_SUBMITTERS_INL
#define TASK_SUBMITTERS_INL

#include "task_submiters.hpp"
#include <memory> //shared_ptr

namespace advcpp
{

template<typename Runner>
TasksSubmiter<Runner>::TasksSubmiter(ThreadPool<>& a_pool, size_t a_loops, size_t a_nTasks)
: m_pool (a_pool)
, m_loops (a_loops)
, m_nTasks (a_nTasks)
{
}

template<typename Runner>
void TasksSubmiter<Runner>::Run() noexcept
{
    std::vector<std::shared_ptr<Runner> > loopers;
    loopers.reserve(m_nTasks);

    while (m_nTasks --> 0)
    {
        loopers.push_back(std::make_shared<Runner>());
        m_pool.Submit(loopers.back());        
    }    
}

} //namespace advcpp

#endif //TASK_SUBMITTERS_INL