#include <algorithm>
#include <pthread.h>

#include "thread_group.hpp"


namespace advcpp
{

template <typename Runnable>
template <typename... Args>
size_t ThreadsGroup<Runnable>::AddThreads(size_t a_nWorkers, Args&... a_args)
{
    Guard guard(m_lock);
    size_t nWorkerCreated = 0;  
    a_nWorkers = std::min(a_nWorkers, maxnThread - m_threads.size());

    for (size_t i = 0; i < a_nWorkers; ++i)
    {
        std::shared_ptr<Runnable> spTasker = createRunnable(a_args...);
        std::shared_ptr<Thread> spThread = std::make_shared<Thread>(spTasker.get());

        m_threads.emplace(std::make_pair(spThread->GetId() ,Worker(spThread, spTasker)));
        ++nWorkerCreated;
    }
    return nWorkerCreated;
}

template <typename Runnable>
size_t ThreadsGroup<Runnable>::AddThreads(std::shared_ptr<Runnable> a_runnable)
{
    Guard guard(m_lock);

    std::shared_ptr<Thread> spThread = std::make_shared<Thread>(a_runnable.get());
    m_threads.emplace(std::make_pair(spThread->GetId() ,Worker(spThread, a_runnable)));
    ++nWorkerCreated;

    return nWorkerCreated;
}

template <typename Runnable>
const size_t ThreadsGroup<Runnable>::maxnThread = GetMaxThreadsNum();

template <typename Runnable>
bool ThreadsGroup<Runnable>::RemoveThread(int a_threadId)
{
    Guard guard(m_lock);
    iterator iter = m_threads.find(a_threadId);
    if (iter != m_threads.end())
    {
        iter->second.first->Join();
        m_threads.erase(iter);
        return true;
    }
    return false;
}

template <typename Runnable>
struct ThreadsGroup<Runnable>::ThreadJoin {
    void operator()(std::pair<int, Worker> a_pair)
    {
        a_pair.second.first->Join();
    }
};

template <typename Runnable>
void ThreadsGroup<Runnable>::JoinAll()
{
    Guard guard(m_lock);
    std::for_each(m_threads.begin(), m_threads.end(), ThreadJoin());
}

template <typename Runnable>
void ThreadsGroup<Runnable>::Clear()
{
    Guard guard(m_lock);
    m_threads.clear();
}

template <typename Runnable>
size_t ThreadsGroup<Runnable>::NumOfThreads() const
{
    Guard guard(m_lock);
    return m_threads.size();
}

template <typename Runnable>
template <typename... Args>
std::shared_ptr<Runnable> ThreadsGroup<Runnable>::createRunnable(Args&... a_args)
{
    return std::make_shared<Runnable>(a_args...);
}

template <typename Runnable>
template <typename UnaryAction>
struct ThreadsGroup<Runnable>::RunnableAction {
    RunnableAction(UnaryAction a_action) :m_action(a_action){}
    void operator()(std::pair<int, Worker> a_pair)
    {
        m_action(a_pair.second.second);
    }
    UnaryAction m_action;
};

template <typename Runnable>
template <typename UnaryAction>
void ThreadsGroup<Runnable>::ForEach(UnaryAction a_action)
{
    Guard guard(m_lock);
    std::for_each(m_threads.begin(), m_threads.end(), RunnableAction<UnaryAction>(a_action));
}

template <typename Runnable>
std::shared_ptr<Runnable> ThreadsGroup<Runnable>::GetRunnable(int a_threadId)
{
    Guard guard(m_lock);
    iterator iter = m_threads.find(a_threadId);
    if (iter != m_threads.end())
    {
        return iter->second.second;
    }
    return 0;
}

} //namespace advcpp