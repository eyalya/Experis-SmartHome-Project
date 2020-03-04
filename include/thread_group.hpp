#ifndef THREAD_GROUP_HPP
#define THREAD_GROUP_HPP

#include <map> //map
#include <memory> //std::shared_ptr

// #include "irunnable.hpp" // Runnable
#include "thread.hpp" // Thread
#include "locks.hpp" // Mutex

namespace advcpp
{

// class ThreadCreateException: public EnrichedExeption {
// public:
//     explicit ThreadCreateException (InfoException a_info, const char* a_msg = "thread create failed")
//     : EnrichedExeption(a_msg, a_info) 
//     {};
// };




template <typename Runnable>
class ThreadsGroup {
public: 
    typedef std::pair<std::shared_ptr<Thread>, std::shared_ptr<Runnable> > Worker;
    typedef std::map<int, Worker> ThreadContainer;
    typedef typename std::map<int, Worker>::iterator iterator;

    static const size_t maxnThread; 

    ThreadsGroup() = default;

    ~ThreadsGroup() = default;
    ThreadsGroup(ThreadsGroup const& a_rhs) = default;
    ThreadsGroup& operator=( ThreadsGroup const& a_rhs) = default;

    template <typename... Args>
    size_t AddThreads(size_t a_nWorkers, Args&... a_args);

    bool RemoveThread(int a_threadId);
    void JoinAll();

    void Clear();

    template <typename UnaryAction>
    void ForEach(UnaryAction a_action);

    std::shared_ptr<Runnable> GetRunnable(int a_threadId);

    size_t NumOfThreads() const;
private:
    template <typename ...Args>
    std::shared_ptr<Runnable> createRunnable(Args&... a_args);

    struct ThreadJoin;
    template <typename UnaryAction>
    struct RunnableAction;
private:
    ThreadContainer m_threads;
    mutable Mutex m_lock;
};


} //namespace advcpp

#include "inl/thread_group.inl"

#endif //THREAD_GROUP_HPP
