#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <utility> //std::pair

#include "common.hpp" // NT
#include "thread.hpp"
#include "waitable_queue.hpp"
#include "taskers.hpp"
#include "thread_group.hpp" // group

namespace advcpp 
{

template <typename SafeCont = WaitableQ<TaskPtr>, typename Handler = DoNothing>
class ThreadPool: public UnCopiable {
public:
    enum ShutDownModes 
    {
        NOOB, 
        HARD
    };

    explicit ThreadPool(size_t a_nThread = getHardwareCores());
    virtual ~ThreadPool() noexcept;

    ThreadPool(ThreadPool const& a_rhs) = delete; 
    ThreadPool& operator=(ThreadPool const& a_rhs) = delete; 

    bool Submit(TaskPtr a_task);
    void ShutDown(ShutDownModes a_shmode);
    void AddWorkers(size_t a_nWorkers = getHardwareCores()); 
    void RemoveWorker(size_t a_nWorkers);

    size_t NumOfWorkers() const noexcept;

private:
    class EmptyTask;
    class DestoryerTask;

    void shutDownNoob();
    void shutDownHard();
    void shutDownWorkers(); 
    void insertEmptyTasks(size_t a_num);
    void insertDestroyerTasks(WaitableQ<int>& a_report, size_t a_nWorkers);
    void removeVictims(WaitableQ<int>& a_report, size_t a_nWorkers);

private:
    SafeCont m_taskQue;
    ThreadsGroup<Tasker> m_workers;

    Handler m_exceptionHandler;
    std::atomic<bool> m_state;
};

} //namespace advcpp 

#include "inl/thread_pool.inl"
#endif //THREAD_POOL_HPP