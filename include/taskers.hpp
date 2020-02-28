#ifndef TASKERS_HPP
#define TASKERS_HPP

#include <memory> //shared_ptr
#include <atomic> //atomic

#include "thread.hpp"
#include "waitable_queue.hpp"

namespace advcpp
{

class ITaskers;
typedef std::shared_ptr<IRunnable> TaskPtr;
typedef std::shared_ptr<ITaskers> TaskerPtr;


class ITaskers: public IRunnable {
public:
    virtual ~ITaskers() = default;
    virtual void ShutDown() = 0;
};

class Tasker: public ITaskers {
public:
    explicit Tasker(WaitableQ<TaskPtr>& a_taskQue);

    ~Tasker() = default;
    Tasker(const Tasker& a_rhs) = default;
    Tasker& operator = (const Tasker& a_rhs) = default;

    void Run() noexcept;
    void ShutDown();

private:
    WaitableQ<TaskPtr>& m_taskQue;
    std::atomic<bool> m_state; 
};


TaskerPtr TaskerFactory(WaitableQ<TaskPtr>& a_taskQue);

} // namespace advcpp

#include "inl/taskers.inl"
#endif //TASKERS_HPP
