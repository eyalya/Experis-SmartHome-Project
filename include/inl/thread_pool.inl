#ifndef THREAD_POOL_INL
#define THREAD_POOL_INL

#include <cassert>

#include "thread_pool.hpp"
// #include "thread_utils.hpp"

namespace advcpp 
{

const size_t g_taskMaxSize = 2000;

template <typename SafeCont, typename Handler>
class ThreadPool<SafeCont, Handler>::EmptyTask: public IRunnable{
public:
    EmptyTask() = default;

    ~EmptyTask() = default;
    EmptyTask(EmptyTask const& a_rhs) = delete;
    EmptyTask& operator = (EmptyTask const& a_rhs) = delete;

    void Run() noexcept;
};

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::EmptyTask::Run() noexcept
{
}

template <typename SafeCont, typename Handler>
class ThreadPool<SafeCont, Handler>::DestoryerTask: public IRunnable{
public:
    DestoryerTask(WaitableQ<int>& a_report, ThreadsGroup<Tasker>& a_group);

    ~DestoryerTask() = default;
    DestoryerTask(DestoryerTask const& a_rhs) = delete;
    DestoryerTask& operator = (DestoryerTask const& a_rhs) = delete;

    void Run() noexcept;
private:
    WaitableQ<int>& m_report;
    ThreadsGroup<Tasker>& m_group; 
};

template <typename SafeCont, typename Handler>
ThreadPool<SafeCont, Handler>::DestoryerTask::DestoryerTask(WaitableQ<int>& a_report, ThreadsGroup<Tasker>& a_group)
: m_report(a_report)
, m_group (a_group)
{
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::DestoryerTask::Run() noexcept
{
    int id = Thread::GetSelf();
    m_group.GetRunnable(id)->ShutDown();
    m_report.Enqueue(id);
}

////////////////////////////////////////////////////////////////////////
template <typename SafeCont, typename Handler>
ThreadPool<SafeCont, Handler>::ThreadPool(size_t a_nThread)
: m_taskQue (g_taskMaxSize)
, m_state (true)
{
    AddWorkers(a_nThread);
}

template <typename SafeCont, typename Handler>
ThreadPool<SafeCont, Handler>::~ThreadPool() noexcept
{
    assert(m_state != true);
    assert(m_workers.NumOfThreads() == 0);
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::AddWorkers(size_t a_nWorkers)
{
    try
    {
        m_workers.AddThreads(a_nWorkers, m_taskQue);
    }   
    catch(std::exception& e)
    {
        m_exceptionHandler(e);
    }

    assert (m_workers.NumOfThreads() > 0);
    m_state = true;
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::RemoveWorker(size_t a_nWorkers)
{
    a_nWorkers = std::min(a_nWorkers, m_workers.NumOfThreads());
    WaitableQ<int> report(a_nWorkers);

    insertDestroyerTasks(report, a_nWorkers);
    removeVictims(report, a_nWorkers);

    if (m_workers.NumOfThreads() == 0)
    {
        m_state = false;
    }
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::insertDestroyerTasks(WaitableQ<int>& a_report, size_t a_nWorkers)
{
    for(size_t i = 0; i < a_nWorkers; ++i)
    {
        m_taskQue.Enqueue(std::make_shared<DestoryerTask>(a_report, m_workers));
    }
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::removeVictims(WaitableQ<int>& a_report, size_t a_nWorkers)
{
    int result = 0;

    for(size_t i = 0; i < a_nWorkers; ++i)
    {
        a_report.Dequeue (result);
        assert (m_workers.RemoveThread(result));
    }
}

template <typename SafeCont, typename Handler>
bool ThreadPool<SafeCont, Handler>::Submit(TaskPtr a_task)
{
    if (m_state == true && a_task != 0)
    {
        m_taskQue.Enqueue(a_task);
        return true;
    }
    return false;
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::ShutDown(ShutDownModes a_shmode)
{
    m_state = false;
    switch (a_shmode)
    {
    case NOOB:
        shutDownNoob();
        break;
    default:
        break;
    }
    m_workers.JoinAll();
    m_workers.Clear();
}

template <typename SafeCont, typename Handler>
size_t ThreadPool<SafeCont, Handler>::NumOfWorkers() const noexcept
{
    return m_workers.NumOfThreads();
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::shutDownNoob()
{
    size_t nthread = NumOfWorkers();

    shutDownWorkers();
    insertEmptyTasks(nthread);
}

struct TaskShutDown {
    void operator()(std::shared_ptr<Tasker> a_tasker)
    {
        a_tasker->ShutDown();
    }
};

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::shutDownWorkers()
{
    m_workers.ForEach<TaskShutDown>(TaskShutDown());   
}

template <typename SafeCont, typename Handler>
void ThreadPool<SafeCont, Handler>::insertEmptyTasks(size_t a_num)
{
    while (a_num) 
    {
        m_taskQue.Enqueue(TaskPtr(new EmptyTask()));
        --a_num;
    }
}

} //namespace advcpp 

#endif //THREAD_POOL_INL