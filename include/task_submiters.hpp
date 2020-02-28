#ifndef TASK_SUBMITTERS_HPP
#define TASK_SUBMITTERS_HPP

namespace advcpp
{

template<typename Runner>
class TasksSubmiter: public IRunnable{    
public:
    explicit TasksSubmiter(ThreadPool<>& a_pool, size_t a_loops, size_t a_nTasks);

    ~TasksSubmiter() = default;
    TasksSubmiter(TasksSubmiter const& a_rhs) = default;
    TasksSubmiter& operator = (TasksSubmiter const& a_rhs) = default;

    void Run() noexcept;
private:
    ThreadPool<>& m_pool;
    size_t m_loops;
    size_t m_nTasks;
};

} //namespace advcpp

#include "inl/task_submiters.inl"

#endif //TASK_SUBMITTERS_HPP